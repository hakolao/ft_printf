/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 18:19:22 by ohakola           #+#    #+#             */
/*   Updated: 2020/08/26 21:57:59 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dtoa.h"

/*
** Sets cutoff modes based on the inputted formats and precision
** If precision is negative, use no cutoff and output as many decimals
** as possible.
** With scientific, cutoff includes the total length of the digit array
** because there is always just one digit ahead of the dot. Precision (cutoff
** num is incremented by one to account for that).
** With normal mode the precision defines the cutoff num.
*/

static void		set_cutoffs(t_dragon4_params *dragon, t_dtoa_params dtoa)
{
	if (dtoa.precision < 0)
	{
		dragon->cutoff_mode = CUTOFF_NONE;
		dragon->cutoff_num = 0;
	}
	else
	{
		if (dtoa.format == FORMAT_NORM)
		{
			dragon->cutoff_mode = CUTOFF_FRACTION_LENGTH;
			dragon->cutoff_num = dtoa.precision;
		}
		else if (dtoa.format == FORMAT_SCI)
		{
			dragon->cutoff_mode = CUTOFF_TOTAL_LENGTH;
			dragon->cutoff_num = dtoa.precision + 1;
		}
	}
}

/*
** Presets dragon4 algorithm related parameters before calling the algorithm.
** Float is dissected into mantissa, sign and exponent.
** See: http://www.ryanjuckett.com/programming/printing-floating-point-numbers/
** part-3/
** Mantissa becomes (2^52 + float mantissa)
** Exponent becomes (exponent - 1023 - 52)
** Sign is 1 when negative, 0 when positive thus bufffer length is increased by
** sign bit.
*/

static void		set_dragon4_params(t_dragon4_params *dragon, t_dtoa_params dtoa,
				char *buf, uint32_t buf_size)
{
	t_float_dissector	fd;

	fd.f = dtoa.value;
	if (fd.b.sign == 1)
		*buf = '-';
	if (fd.b.exp != 0)
	{
		dragon->buf = buf + fd.b.sign;
		dragon->buf_size = buf_size - fd.b.sign - (dtoa.format == FORMAT_NORM);
		dragon->mantissa = (1ULL << 63) | fd.b.fraction;
		dragon->exponent = fd.b.exp - 16383 - 63;
		dragon->mantissa_high_bit_index = 63;
		dragon->has_unequal_margins = (fd.b.exp != 1) && (fd.b.fraction == 0);
	}
	else
	{
		dragon->buf = buf + fd.b.sign;
		dragon->buf_size = buf_size - fd.b.sign - (dtoa.format == FORMAT_NORM);
		dragon->mantissa = fd.b.fraction;
		dragon->exponent = 1 - 1023 - 63;
		dragon->mantissa_high_bit_index = log_base2_64(fd.b.fraction);
		dragon->has_unequal_margins = false;
	}
	set_cutoffs(dragon, dtoa);
}

/*
** Dtoa returns an allocated double value as a char* in either scientific
** or normal format.
*/

char			*ft_dtoa(t_dtoa_params params)
{
	char				*res;
	char				buf[DTOA_BUF_SIZE];
	t_dragon4_params	dragon;
	uint32_t			print_len;
	t_float_dissector	fd;

	fd.f = params.value;
	set_dragon4_params(&dragon, params, buf, DTOA_BUF_SIZE);
	if (params.format == FORMAT_SCI)
		print_len = format_scientific(dragon, params.precision) + fd.b.sign;
	else
		print_len = format_normal(dragon, params.precision) + fd.b.sign;
	if (!(res = ft_strnew(print_len)))
		return (NULL);
	ft_strcpy(res, buf);
	return (res);
}

/*
** Dtoa version where the caller can input buffer to prevent memory allocation
** costs. The length of the resulting char array is returned.
*/

int				ft_dtoa_buf(t_dtoa_params params, char *buf, int buf_size)
{
	t_dragon4_params	dragon;
	uint32_t			print_len;
	t_float_dissector	fd;

	fd.f = params.value;
	set_dragon4_params(&dragon, params, buf, buf_size);
	if (params.format == FORMAT_SCI)
		print_len = format_scientific(dragon, params.precision) + fd.b.sign;
	else
		print_len = format_normal(dragon, params.precision) + fd.b.sign;
	return (print_len);
}