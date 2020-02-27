/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:00:25 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/27 13:08:07 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int				init_printf(t_printf *data, const char *format)
{
	data->fd = 1;
	data->len = 0;
	if (!(data->result = ft_strnew(0)))
		return (FALSE);
	data->format = (char*)format;
	return (TRUE);
}

int						ft_printf(const char *format, ...)
{
	t_printf	data;

	if (!(init_printf(&data, format)))
		return (FALSE);
	va_start(data.variables, format);
	if (!parse_variables(&data, (char*)format))
		return (FALSE);
	va_end(data.variables);
	write(data.fd, data.result, data.len);
	ft_strdel(&data.result);
	return (data.len);
}
