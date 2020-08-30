/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 17:29:40 by ohakola           #+#    #+#             */
/*   Updated: 2020/08/30 18:77:18 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char				*choose_g_output(t_printf *data, int *print_lens,
						char *norm_buf, char *sci_buf)
{
	char				*res;
	int					exp;
	int					i;

	i = print_lens[0];
	while (sci_buf[i] != 'e')
		i--;
	exp = ft_atoi(sci_buf + i + 1);
	if (exp >= -4 && exp < data->precision)
	{
		data->var_len = print_lens[1];
		if (!(res = ft_strnew(data->var_len)))
			return (NULL);
		ft_memmove(res, norm_buf, data->var_len);
	}
	else
	{
		data->var_len = print_lens[0];
		if (!(res = ft_strnew(data->var_len)))
			return (NULL);
		ft_memmove(res, sci_buf, data->var_len);
		if (data->c == 'G')
			ft_capitalize(res);
	}
	return (res);
}

static char				*parse_g_float(t_printf *data)
{
	char				norm_buf[DTOA_BUF_SIZE];
	char				sci_buf[DTOA_BUF_SIZE];
	long double			var;
	t_float_dissector	fds;
	int					print_lens[2];

	data->precision = data->precision >= 0 ? data->precision : 6;
	data->precision = data->precision == 0 ? 1 : data->precision;
	if (data->type == length_L)
	{
		var = va_arg(data->variables, long double);
		print_lens[0] = ft_dtoa_buf((t_dtoa_params){.precision = data->precision,
			.value = var, .format = FORMAT_SCI, .hashtag = data->zerox,
			.g_mode = true, .long_double = true}, sci_buf, DTOA_BUF_SIZE);
		print_lens[1] = ft_dtoa_buf((t_dtoa_params){.precision = data->precision,
			.value = var, .format = FORMAT_NORM, .hashtag = data->zerox,
			.g_mode = true, .long_double = true}, norm_buf, DTOA_BUF_SIZE);
	}
	else
	{
		var = va_arg(data->variables, double);
		print_lens[0] = ft_dtoa_buf((t_dtoa_params){.precision = data->precision,
			.value = var, .format = FORMAT_SCI, .hashtag = data->zerox,
			.g_mode = true, .long_double = false}, sci_buf, DTOA_BUF_SIZE);
		print_lens[1] = ft_dtoa_buf((t_dtoa_params){.precision = data->precision,
			.value = var, .format = FORMAT_NORM, .hashtag = data->zerox,
			.g_mode = true, .long_double = false}, norm_buf, DTOA_BUF_SIZE);
	}
	fds.f = var;
	if (fds.b.sign)
		data->is_negative = true;
	return (choose_g_output(data, print_lens, norm_buf, sci_buf));
}

static char				*parse_f_float(t_printf *data)
{
	char				*res;
	char				buf[DTOA_BUF_SIZE];
	long double			var;
	t_float_dissector	fds;

	res = NULL;
	data->precision = data->precision >= 0 ? data->precision : 6;
	if (data->type == length_L)
	{
		var = va_arg(data->variables, long double);
		data->var_len = ft_dtoa_buf((t_dtoa_params){.precision = data->precision,
			.value = var, .format = data->c == 'f' || data->c == 'F' ?
			FORMAT_NORM : FORMAT_SCI, .hashtag = data->zerox, .g_mode = false,
			.long_double = true}, buf, DTOA_BUF_SIZE);
	}
	else
	{
		var = va_arg(data->variables, double);
		data->var_len = ft_dtoa_buf((t_dtoa_params){.precision = data->precision,
			.value = var, .format = data->c == 'f' || data->c == 'F' ?
			FORMAT_NORM : FORMAT_SCI, .hashtag = data->zerox, .g_mode = false,
			.long_double = false}, buf, DTOA_BUF_SIZE);
	}
	fds.f = var;
	if (fds.b.sign)
		data->is_negative = true;
	if (!(res = ft_strnew(data->var_len)))
		return (NULL);
	ft_memmove(res, buf, data->var_len);
	if (data->c == 'E')
		ft_capitalize(res);
	return (res);
}

char					*parse_float(t_printf *data)
{
	if (data->c == 'f' || data->c == 'F' || data->c == 'e' || data->c == 'E')
		return (parse_f_float(data));
	return (parse_g_float(data));
}
