/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dragon4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 19:27:50 by ohakola           #+#    #+#             */
/*   Updated: 2020/08/28 12:59:53 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dtoa.h"

/*
** Exit dragon4 if mantissa is zero. The value is thus zero.
*/

static int32_t		zero_if_zero(t_dragon4_params params)
{
	if (params.mantissa == 0)
	{
		*(params.out_exponent) = 0;
		params.buf[0] = '0';
		return (1);
	}
	return (0);
}

/*
** Initial digit exponent calculation based on algorithm outlined in
** www.ryanjuckett.com/programming/printing-floating-point-numbers/part-2/
*/

static int32_t		get_digit_exponent(t_dragon4_params params)
{
	int32_t		digit_exponent;

	digit_exponent =
		(int32_t)(ft_ceil((double)((int32_t)params.mantissa_high_bit_index +
			params.exponent) * LOG10_2 - 0.69));
	if (params.cutoff_mode == CUTOFF_FRACTION_LENGTH &&
		digit_exponent <= -(int32_t)params.cutoff_num)
		digit_exponent = -(int32_t)params.cutoff_num + 1;
	return (digit_exponent);
}

/*
** Dragon4 implementation using the algorithm laid out by ryanjuckett in
** http://www.ryanjuckett.com/programming/printing-floating-point-numbers/
** Here implemented in C and split into small logical functions.
** scale: Positive scale applied to value and margin so those are represented
** as whole numbers
** scaled_value: scale * mantissa
** scaled_margins[2]:
**  [0]: low, scale * 0.5 * (distance between this floating point number and
**       its lower value),
**  [1]: high: low * 2 or same as low depending on whether margins are equal
** 1. First compute the intial state in integer form.
** 2. Get digit exponent estimate using "Printing Floating-Point Numbers Quickly
** and Accurately" by Burger and Dybvig http://citeseerx.ist.psu.edu/viewdoc/
** download?doi=10.1.1.72.4656&rep=rep1&type=pdf using modifications by ryan.
** 3. Scale values by digit exponent
** 4. Prepare values for output generation by big int division
** 5. Generate output digits by big int division
*/

uint32_t			dragon4(t_dragon4_params params)
{
	t_big_int	scale;
	t_big_int	scaled_value;
	t_big_int	scaled_margins[2];
	int32_t		digit_exponent;

	if (zero_if_zero(params))
		return (1);
	if (params.has_unequal_margins)
		normalized_initial_state(params, &scale, &scaled_value,
			scaled_margins);
	else
		denormalized_initial_state(params, &scale, &scaled_value,
			scaled_margins);
	digit_exponent = get_digit_exponent(params);
	scale_values_by_digit_exponent(&scale, &scaled_value,
		scaled_margins, &digit_exponent);
	*(params.out_exponent) = digit_exponent - 1;
	prepare_values_for_division(&scale, &scaled_value, scaled_margins);
	if (params.cutoff_mode == CUTOFF_NONE)
		return (output_without_cutoff(params, &scale, &scaled_value,
			scaled_margins));
	else
		return (output_with_cutoff(params, &scale, &scaled_value));
}
