/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dragon4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 19:27:50 by ohakola           #+#    #+#             */
/*   Updated: 2020/08/24 20:10:51 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dtoa.h"

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

uint32_t			dragon4(t_dragon4_params params)
{
	t_big_int	scale;
	t_big_int	scaled_value;
	t_big_int	scaled_margins[2];
	int32_t		digit_exponent;

	if (zero_if_zero(params))
		return (1);
	if (params.has_unequal_margins)
		initial_whole_number_integers(params, &scale, &scaled_value,
			scaled_margins);
	else
		initial_fractional_number_integers(params, &scale, &scaled_value,
			scaled_margins);
	digit_exponent = get_digit_exponent(params);
	scale_values_by_digit_exponent(&scale, &scaled_value,
		scaled_margins, &digit_exponent);
	*(params.out_exponent) = digit_exponent - 1;
	prepare_values_for_division(&scale, &scaled_value, scaled_margins);
	if (CUTOFF_NONE)
		return (output_without_cutoff(params, &scale, &scaled_value,
			scaled_margins));
	else
		return (output_with_cutoff(params, &scale, &scaled_value));
}
