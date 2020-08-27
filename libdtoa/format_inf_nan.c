/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_inf_nan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 13:29:41 by ohakola           #+#    #+#             */
/*   Updated: 2020/08/27 14:05:15 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dtoa.h"

static uint32_t	print_hex(char *buf, uint32_t buf_size,
				uint64_t value, uint32_t width)
{
	char		*digits;
	uint32_t	max_print_len;
	size_t		i;

	digits = "0123456789abcdef";
	max_print_len = buf_size - 1;
	if (width > max_print_len)
		width = max_print_len;
	i = 0;
	while (width > 0)
	{
		--width;
		buf[i] = digits[(uint8_t)((value >> 4ULL*(uint64_t)width) & 0xF)];
		i++;
	}
	buf[i] = '\0';
	return (i);
}

uint32_t		format_inf_nan(t_dragon4_params params, uint64_t mantissa,
				uint32_t mantissa_hex_width)
{
	uint32_t	max_print_len;
	uint32_t	print_len;

	max_print_len = params.buf_size - 1;
	if (mantissa == 0)
	{
		print_len = max_print_len > 3 ? 3 : max_print_len;
		ft_memcpy(params.buf, "Inf", print_len);
		params.buf[print_len] = '\0';
		return (print_len);
	}
	else
	{
		print_len = max_print_len > 3 ? 3 : max_print_len;
		ft_memcpy(params.buf, "NaN", print_len);
		params.buf[print_len] = '\0';	
		if (max_print_len > 3)
			print_len += print_hex(params.buf + 3,
				params.buf_size - 3, mantissa, mantissa_hex_width);
		return (print_len);
	}
}