/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 17:29:40 by ohakola           #+#    #+#             */
/*   Updated: 2020/08/27 17:41:45 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*parse_float(t_printf *data)
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
