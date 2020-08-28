/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dragon4_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 18:52:45 by ohakola           #+#    #+#             */
/*   Updated: 2020/08/28 11:55:56 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dtoa.h"

static t_bool	is_round_down(t_big_int *scale, t_big_int *scaled_value,
				uint32_t output_digit, t_bool lo_hi[2])
{
	int32_t		compare;
	t_bool		round_down;

	round_down = lo_hi[0];
	if (lo_hi[0] == lo_hi[1])
	{
		big_int_mul_2_modif(scaled_value);
		compare = big_int_cmp(scaled_value, scale);
		round_down = compare < 0;
		if (compare == 0)
			round_down = (output_digit & 1) == 0;
	}
	return (round_down);
}

static int32_t	cutoff(t_dragon4_params params,
				int32_t digit_exponent)
{
	int32_t		cutoff_exponent;
	int32_t		desired_cutoff_exponent;

	cutoff_exponent = digit_exponent - params.buf_size;
	if (params.cutoff_mode == CUTOFF_TOTAL_LENGTH)
	{
		desired_cutoff_exponent = digit_exponent - (int32_t)params.cutoff_num;
		if (desired_cutoff_exponent > cutoff_exponent)
			cutoff_exponent = desired_cutoff_exponent;
	}
	else if (params.cutoff_mode == CUTOFF_FRACTION_LENGTH)
	{
		desired_cutoff_exponent = -(int32_t)params.cutoff_num;
		if (desired_cutoff_exponent > cutoff_exponent)
			cutoff_exponent = desired_cutoff_exponent;
	}
	return (cutoff_exponent);
}

static uint32_t	round_if_needed(t_dragon4_params params, t_bool round_down,
				uint32_t output_digit, uint32_t pos)
{
	if (round_down)
		params.buf[pos++] = (char)('0' + output_digit);
	else
	{
		if (output_digit == 9)
		{
			while (1)
			{
				if (&(params.buf[pos]) == params.buf)
				{
					params.buf[pos++] = '1';
					*(params.out_exponent) += 1;
					break ;
				}
				if (params.buf[--pos] != '9')
				{
					params.buf[pos++] += 1;
					break ;
				}
			}
		}
		else
			params.buf[pos++] = (char)('0' + output_digit + 1);
	}
	return (pos);
}

uint32_t		output_without_cutoff(t_dragon4_params params, t_big_int *scale,
				t_big_int *scaled_value, t_big_int scaled_margins[2])
{
	int32_t		digit_exp;
	uint32_t	output_digit;
	t_bool		lo_hi[2];
	t_big_int	scaled_value_high;
	uint32_t	pos;

	digit_exp = *(params.out_exponent) + 1;
	pos = 0;
	while (1)
	{
		digit_exp = digit_exp - 1;
		output_digit = big_int_divide_to_output_digit(scaled_value, scale);
		big_int_add(scaled_value, &scaled_margins[1], &scaled_value_high);
		lo_hi[0] = big_int_cmp(scaled_value, &scaled_margins[0]) < 0;
		lo_hi[1] = big_int_cmp(&scaled_value_high, scale) > 0;
		if (lo_hi[0] | lo_hi[1] | (digit_exp == cutoff(params, digit_exp)))
			break ;
		params.buf[pos++] = (char)('0' + output_digit);
		big_int_mul_10_modif(scaled_value);
		big_int_mul_10_modif(&scaled_margins[0]);
		if (big_int_cmp(&scaled_margins[1], &scaled_margins[0]) != 0)
			big_int_mul_2(&scaled_margins[0], &scaled_margins[1]);
	}
	return (round_if_needed(params, is_round_down(scale, scaled_value,
		output_digit, lo_hi), output_digit, pos));
}

uint32_t		output_with_cutoff(t_dragon4_params params, t_big_int *scale,
				t_big_int *scaled_value)
{
	int32_t		digit_exp;
	uint32_t	output_digit;
	t_bool		lo_hi[2];
	int32_t		cutoff_exponent;
	uint32_t	pos;

	digit_exp = *(params.out_exponent) + 1;
	cutoff_exponent = cutoff(params, digit_exp);
	pos = 0;
	lo_hi[0] = false;
	lo_hi[1] = false;
	while (1)
	{
		digit_exp = digit_exp - 1;
		output_digit = big_int_divide_to_output_digit(scaled_value, scale);
		if (big_int_is_zero(scaled_value) |
			(digit_exp == cutoff_exponent))
			break ;
		params.buf[pos] = (char)('0' + output_digit);
		pos++;
		big_int_mul_10_modif(scaled_value);
	}
	return (round_if_needed(params, is_round_down(scale, scaled_value,
		output_digit, lo_hi), output_digit, pos));
}
