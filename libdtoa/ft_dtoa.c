/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 18:19:22 by ohakola           #+#    #+#             */
/*   Updated: 2020/08/24 21:12:00 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dtoa.h"

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
		dragon->mantissa = (1ULL << 52) | fd.b.fraction;
		dragon->exponent = fd.b.exp - 1023 - 52;
		dragon->mantissa_high_bit_index = 52;
		dragon->has_unequal_margins = (fd.b.exp != 1) && (fd.b.fraction == 0);
	}
	else
	{
		dragon->buf = buf + fd.b.sign;
		dragon->buf_size = buf_size - fd.b.sign - (dtoa.format == FORMAT_NORM);
		dragon->mantissa = fd.b.fraction;
		dragon->exponent = 1 - 1023 - 52;
		dragon->mantissa_high_bit_index = log_base2_32(fd.b.fraction);
		dragon->has_unequal_margins = false;
	}
	set_cutoffs(dragon, dtoa);
}

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
