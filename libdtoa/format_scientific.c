/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_scientific.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 23:41:48 by ohakola           #+#    #+#             */
/*   Updated: 2020/08/27 17:48:08 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dtoa.h"

/*
** Fraction digits are moved by one to give space for the decimal dot.
*/

static void				move_fraction_digits(t_dragon4_params params,
						uint32_t *fraction_digits, uint32_t *digit_i)
{
	uint32_t	max_fraction_digits;

	max_fraction_digits = params.buf_size - 2;
	if (*fraction_digits > max_fraction_digits)
		*fraction_digits = max_fraction_digits;
	ft_memmove(params.buf + *digit_i + 1,
		params.buf + *digit_i, *fraction_digits);
	params.buf[*digit_i] = '.';
	*digit_i += (1 + *fraction_digits);
	params.buf_size -= (1 + *fraction_digits);
}

/*
** After fraction digits, as many zeros as there are remaining after subtracting
** number of fraction digits from precision, are added.
*/

static void				add_trailing_zeros(t_dragon4_params params,
						uint32_t fraction_digits, int32_t precision,
						uint32_t *digit_i)
{
	uint32_t	zeros;
	uint32_t	zeros_i;

	if (fraction_digits == 0)
	{
		params.buf[(*digit_i)++] = '.';
		params.buf_size--;
	}
	zeros = (precision - fraction_digits);
	if (zeros > params.buf_size - 1)
		zeros = params.buf_size - 1;
	zeros_i = *digit_i;
	while (zeros_i < *digit_i + zeros)
		params.buf[zeros_i++] = '0';
	*digit_i = zeros_i;
}

static void				set_exp_buf(t_dragon4_params params, int32_t exp,
						char *exp_buf, uint32_t *exp_size)
{
	uint32_t	tens;
	uint32_t	hundreds;

	hundreds = (exp / 100);
	tens = (exp - hundreds * 100) / 10;
	if (hundreds == 0)
	{
		exp_buf[2] = (char)('0' + tens);
		exp_buf[3] = (char)('0' + (exp - hundreds * 100 - tens * 10));
		*exp_size = (params.buf_size - 1) > 4 ? 4 : params.buf_size - 1;
	}
	else
	{
		exp_buf[2] = (char)('0' + hundreds);
		exp_buf[3] = (char)('0' + tens);
		exp_buf[4] = (char)('0' + (exp - hundreds * 100 - tens * 10));
		*exp_size = (params.buf_size - 1) > 5 ? 5 : params.buf_size - 1;
	}
}

/*
** Based on the exponent value either + or - is placed after the e in exp buf
** array. tens, hundreds and thousand digits are added in their corresponding
** place. Exp buf is memcopied after the digits.
*/

static void				add_exp_notation(t_dragon4_params params,
						int32_t exp, uint32_t *digit_i)
{
	char		exp_buf[5];
	uint32_t	exp_size;

	exp_buf[0] = 'e';
	if (exp >= 0)
		exp_buf[1] = '+';
	else
	{
		exp_buf[1] = '-';
		exp = -exp;
	}
	set_exp_buf(params, exp, exp_buf, &exp_size);
	ft_memcpy(params.buf + *digit_i, exp_buf, exp_size);
	*digit_i += exp_size;
	params.buf_size -= exp_size;
}

/*
** Formats the digit in buffer in scientific format, e.g.:
** 1.123e001
** After first digit, fraction digits are moved onwards and a dot is added.
** Trailing zeros are added.
** Lastly the exponent is placed at the end of buffer.
*/

uint32_t				format_scientific(t_dragon4_params params,
						int32_t precision, t_bool hashtag)
{
	int32_t		exp;
	uint32_t	digits;
	uint32_t	fraction_digits;
	uint32_t	digit_i;

	exp = 0;
	digit_i = 0;
	params.out_exponent = &exp;
	digits = dragon4(params);
	if (params.buf_size > 1)
	{
		digit_i++;
		params.buf_size -= 1;
	}
	fraction_digits = digits - 1;
	if (fraction_digits > 0 && params.buf_size > 1)
		move_fraction_digits(params, &fraction_digits, &digit_i);
	if (precision > (int32_t)fraction_digits && params.buf_size > 1 &&
		!params.no_trailing_zeros)
		add_trailing_zeros(params, fraction_digits, precision, &digit_i);
	if (precision == 0 && hashtag && fraction_digits == 0)
		params.buf[digit_i++] = '.';
	if (params.buf_size > 1)
		add_exp_notation(params, exp, &digit_i);
	params.buf[digit_i] = '\0';
	return (digit_i);
}
