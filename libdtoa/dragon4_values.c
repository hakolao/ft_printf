/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dragon4_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 18:57:09 by ohakola           #+#    #+#             */
/*   Updated: 2020/08/24 20:13:56 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dtoa.h"

void			scale_values_by_digit_exponent(t_big_int *scale,
				t_big_int *scaled_value, t_big_int scaled_margins[2],
				int32_t *digit_exponent)
{
	t_big_int	temp;
	t_big_int	pow10;

	if (*digit_exponent > 0)
		big_int_mul_pow_10(scale, *digit_exponent, scale);
	else if (*digit_exponent < 0)
	{
		big_int_pow_10(-*digit_exponent, &pow10);
		big_int_mul(scaled_value, &pow10, &temp);
		*scaled_value = temp;
		big_int_mul(&scaled_margins[0], &pow10, &temp);
		scaled_margins[0] = temp;
		if (big_int_cmp(&scaled_margins[1], &scaled_margins[0]) != 0)
			big_int_mul_2(&scaled_margins[0], &scaled_margins[1]);
	}
	if (big_int_cmp(scaled_value, scale) >= 0)
		*digit_exponent = *digit_exponent + 1;
	else
	{
		big_int_mul_10_modif(scaled_value);
		big_int_mul_10_modif(&scaled_margins[0]);
		if (big_int_cmp(&scaled_margins[1], &scaled_margins[0]) != 0)
			big_int_mul_2(&scaled_margins[0], &scaled_margins[1]);
	}
}

void			initial_whole_number_integers(t_dragon4_params params,
				t_big_int *scale, t_big_int *scaled_value,
				t_big_int scaled_margins[2])
{
	if (params.exponent > 0)
	{
		big_int_set_u64(scaled_value, 4 * params.mantissa);
		big_int_shift_left(params.exponent, scaled_value);
		big_int_set_u32(scale, 4);
		big_int_pow_2(params.exponent, &scaled_margins[0]);
		big_int_pow_2(params.exponent + 1, &scaled_margins[1]);
	}
	else
	{
		big_int_set_u64(scaled_value, 4 * params.mantissa);
		big_int_pow_2(-params.exponent * 2, scale);
		big_int_set_u32(&scaled_margins[0], 1);
		big_int_set_u32(&scaled_margins[1], 2);
	}
}

void			initial_fractional_number_integers(t_dragon4_params params,
				t_big_int *scale, t_big_int *scaled_value,
				t_big_int scaled_margins[2])
{
	if (params.exponent > 0)
	{
		big_int_set_u64(scaled_value, 2 * params.mantissa);
		big_int_shift_left(params.exponent, scaled_value);
		big_int_set_u32(scale, 2);
		big_int_pow_2(params.exponent, &scaled_margins[0]);
	}
	else
	{
		big_int_set_u64(scaled_value, 2 * params.mantissa);
		big_int_pow_2(-params.exponent + 1, scale);
		big_int_set_u32(&scaled_margins[0], 1);
	}
	scaled_margins[1] = scaled_margins[0];
}

void			prepare_values_for_division(t_big_int *scale,
				t_big_int *scaled_value, t_big_int scaled_margins[2])
{
	uint32_t	high_block;
	uint32_t	shift;

	high_block = scale->blocks[scale->length - 1];
	if (high_block < 8 || high_block > 429496729)
	{
		shift = (32 + 27 + log_base2_32(high_block)) % 32;
		big_int_shift_left(shift, scale);
		big_int_shift_left(shift, scaled_value);
		big_int_shift_left(shift, &scaled_margins[0]);
		if (big_int_cmp(&scaled_margins[1], &scaled_margins[0]) != 0)
			big_int_mul_2(&scaled_margins[0], &scaled_margins[1]);
	}
}
