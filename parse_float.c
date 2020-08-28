/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 17:29:40 by ohakola           #+#    #+#             */
/*   Updated: 2020/08/28 11:14:17 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char				*parse_g_gloat(t_printf *data)
{
	char				*res;
	char				buf1[DTOA_BUF_SIZE];
	char				buf2[DTOA_BUF_SIZE];
	long double			var;
	t_float_dissector	fds;
	int					print_lens[2];
	int					i;
	int					exp;

	res = NULL;
	if (data->type == length_L)
		var = va_arg(data->variables, long double);
	else
		var = va_arg(data->variables, double);
	fds.f = var;
	if (fds.b.sign)
		data->is_negative = true;
	data->precision = data->precision >= 0 ? data->precision : 6;
	print_lens[0] = ft_dtoa_buf((t_dtoa_params){.precision = data->precision,
		.value = var, .format = FORMAT_SCI, .hashtag = data->zerox,
		.g_mode = true}, buf1, DTOA_BUF_SIZE);
	print_lens[1] = ft_dtoa_buf((t_dtoa_params){.precision =
		data->precision - 1,
		.value = var, .format = FORMAT_NORM, .hashtag = data->zerox,
		.g_mode = true}, buf2, DTOA_BUF_SIZE);
	i = print_lens[0];
	while (buf1[i] != 'e')
		i--;
	exp = ft_atoi(buf1 + i + 1);
	if (exp >= -4 && exp <= data->precision)
	{
		data->var_len = print_lens[1];
		if (!(res = ft_strnew(data->var_len)))
			return (NULL);
		ft_memmove(res, buf2, data->var_len);
	}
	else
	{
		data->var_len = print_lens[0];
		if (!(res = ft_strnew(data->var_len)))
			return (NULL);
		ft_memmove(res, buf1, data->var_len);
		if (data->c == 'G')
			ft_capitalize(res);
	}
	return (res);
}


static char				*parse_f_float(t_printf *data)
{
	char				*res;
	char				buf[DTOA_BUF_SIZE];
	long double			var;
	t_float_dissector	fds;

	res = NULL;
	if (data->type == length_L)
		var = va_arg(data->variables, long double);
	else
		var = va_arg(data->variables, double);
	fds.f = var;
	if (fds.b.sign)
		data->is_negative = true;
	data->precision = data->precision >= 0 ? data->precision : 6;
	data->var_len = ft_dtoa_buf((t_dtoa_params){.precision = data->precision,
		.value = var, .format = data->c == 'f' || data->c == 'F' ?
			FORMAT_NORM : FORMAT_SCI, .hashtag = data->zerox},
		buf, DTOA_BUF_SIZE);
	if (!(res = ft_strnew(data->var_len)))
		return (NULL);
	ft_memmove(res, buf, data->var_len);
	if (data->c == 'E')
		ft_capitalize(res);
	return (res);
}

char					*parse_float(t_printf *data)
{
	if (data->c == 'f' || data->c == 'F')
		return (parse_f_float(data));
	return (parse_g_gloat(data));
}
