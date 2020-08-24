/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_normal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 23:40:28 by ohakola           #+#    #+#             */
/*   Updated: 2020/08/24 19:51:49 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dtoa.h"

static void		format_gte_one(t_dragon4_params params, int32_t print_exponent,
				uint32_t *digits, uint32_t *fraction_digits)
{
	uint32_t	whole_digits;
	uint32_t	max_fraction_digits;

	whole_digits = print_exponent + 1;
	if (*digits < whole_digits)
	{
		if (whole_digits > params.buf_size)
			whole_digits = params.buf_size;
		while (*digits < whole_digits)
			params.buf[(*digits)++] = '0';
	}
	else if (*digits > whole_digits)
	{
		*fraction_digits = *digits - whole_digits;
		max_fraction_digits = params.buf_size - whole_digits - 1;
		if (*fraction_digits > max_fraction_digits)
			*fraction_digits = max_fraction_digits;
		ft_memmove(params.buf + whole_digits + 1,
			params.buf + whole_digits, *fraction_digits);
		params.buf[whole_digits] = '.';
		*digits = whole_digits + 1 + *fraction_digits;
	}
}

static void		fill_zeros_before_digit(t_dragon4_params params,
				uint32_t digits_start_i)
{
	size_t		i;

	i = 2;
	while (i < digits_start_i)
		params.buf[i++] = '0';
}

static void		format_lt_one(t_dragon4_params params, int32_t print_exponent,
				uint32_t *digits, uint32_t *fraction_digits)
{
	uint32_t	fraction_zeros;
	uint32_t	digits_start_i;
	uint32_t	max_fraction_digits;

	if (params.buf_size > 2)
	{
		fraction_zeros = (uint32_t)-print_exponent - 1;
		if (fraction_zeros > params.buf_size - 2)
			fraction_zeros = params.buf_size - 2;
		digits_start_i = 2 + fraction_zeros;
		*fraction_digits = *digits;
		max_fraction_digits = params.buf_size - digits_start_i;
		if (*fraction_digits > max_fraction_digits)
			*fraction_digits = max_fraction_digits;
		ft_memmove(params.buf + digits_start_i, params.buf, *fraction_digits);
		fill_zeros_before_digit(params, digits_start_i);
		*fraction_digits += fraction_zeros;
		*digits = *fraction_digits;
	}
	if (params.buf_size > 1 && (params.buf[1] = '.'))
		*digits += 1;
	if (params.buf_size > 0 && (params.buf[0] = '0'))
		*digits += 1;
}

uint32_t		format_normal(t_dragon4_params params, int32_t precision)
{
	int32_t		exp;
	uint32_t	digits;
	uint32_t	fraction_digits;
	uint32_t	total_digits;

	exp = 0;
	params.out_exponent = &exp;
	digits = dragon4(params);
	fraction_digits = 0;
	if (exp >= 0)
		format_gte_one(params, exp, &digits, &fraction_digits);
	else
		format_lt_one(params, exp, &digits, &fraction_digits);
	if (precision > (int32_t)fraction_digits && digits < params.buf_size)
	{
		if (fraction_digits == 0)
			params.buf[digits++] = '.';
		total_digits = digits + (precision - fraction_digits);
		if (total_digits > params.buf_size)
			total_digits = params.buf_size;
		while (digits < total_digits)
			params.buf[digits++] = '0';
	}
	params.buf[digits] = '\0';
	return (digits);
}
