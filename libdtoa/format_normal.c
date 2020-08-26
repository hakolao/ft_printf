/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_normal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 23:40:28 by ohakola           #+#    #+#             */
/*   Updated: 2020/08/26 14:54:16 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dtoa.h"

/*
** When double value is larger than one, buffer is first appended with zeros
** by the amount of whole digits - digits returned by dragon4. Until whole digit
** is covered. Then fraction digits are moved by whole digits + 1 to account for
** the decimal dot.
*/

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

/*
** Zeros before the digit are filled based on inputted digit start index.
** And after 0. (this function is only used when double value is less than 1.0)
*/

static void		fill_zeros_before_digit(t_dragon4_params params,
				uint32_t digits_start_i)
{
	size_t		i;

	i = 2;
	while (i < digits_start_i)
		params.buf[i++] = '0';
}

/*
** When number is less than one, e.g. 0.12335, digits are moved by where
** digits start index starts (2: 0.) + (fraction zeros). Zeros before digit
** are filled. 0 and . are placed to the beginning of buffer.
*/

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

/*
** Formats the digit in buffer in positional (normal) format, e.g.:
** 123.123456
** Fraction parts are first moved and decimal dot is placed based on where
** whole digits and fraction digits are cut.
** Trailing zeros are added if precision is larger than fraction digits.
*/

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
