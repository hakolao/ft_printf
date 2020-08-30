/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_ld.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 18:32:14 by ohakola           #+#    #+#             */
/*   Updated: 2020/08/30 18:49:54 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dtoa.h"
#include <stdio.h>

static void		set_dragon4_params_ld(t_dragon4_params *dragon, t_dtoa_params dtoa,
				char *buf, uint32_t buf_size)
{
	t_float_dissector_ld	fd;
	t_float_dissector_ld	fd2;

	fd.f = dtoa.value_ld;
	dragon->no_trailing_zeros = dtoa.g_mode;
	dragon->hashtag = dtoa.hashtag;
	printf("mantissa: %llu, exp: %u, sign: %u\n", fd.b.fraction, fd.b.exp, fd.b.sign);
	fd2.b.exp = fd.b.exp;
	fd2.b.sign = fd.b.sign;
	fd2.b.fraction = fd.b.fraction;
	fd2.b.intbit = fd.b.intbit;
	printf("float incoming value: %Lf\n", (long double)dtoa.value);
	printf("float constructed from parts: %Lf\n", fd2.f);
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
		dragon->exponent = 1 - 16383 - 63;
		dragon->mantissa_high_bit_index = log_base2_64(fd.b.fraction);
		dragon->has_unequal_margins = false;
	}
	set_cutoffs(dragon, dtoa);
}

char			*ft_dtoa_ld(t_dtoa_params params)
{
	char					buf[DTOA_BUF_SIZE];
	t_dragon4_params		dragon;
	t_float_dissector_ld	fd;

	fd.f = params.value_ld;
	if (fd.b.sign == 1)
		*buf = '-';
	if (fd.b.exp == 0x7FFF)
		format_inf_nan(buf + fd.b.sign, fd.b.fraction);
	else
	{
		set_dragon4_params_ld(&dragon, params, buf, DTOA_BUF_SIZE);
		if (params.format == FORMAT_SCI)
			format_scientific(dragon, params.precision);
		else
			format_normal(dragon, params.precision -
				(params.g_mode && params.hashtag));
	}
	return (ft_strdup(buf));
}

int				ft_dtoa_buf_ld(t_dtoa_params params, char *buf, int buf_size)
{
	t_dragon4_params		dragon;
	t_float_dissector_ld	fd;

	fd.f = params.value_ld;
	if (fd.b.sign == 1)
		*buf = '-';
	if (fd.b.exp == 0x7FFF)
		return (format_inf_nan(buf + fd.b.sign, fd.b.fraction) + fd.b.sign);
	else
	{
		set_dragon4_params_ld(&dragon, params, buf, buf_size);
		if (params.format == FORMAT_SCI)
			return (format_scientific(dragon, params.precision) + fd.b.sign);
		else
			return (format_normal(dragon, params.precision -
				(params.g_mode && params.hashtag)) + fd.b.sign);
	}
}
