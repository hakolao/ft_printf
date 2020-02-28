/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:00:25 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/28 13:45:44 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						reset_var_specific_data(t_printf *data)
{
	data->left_justify = FALSE;
	data->pad_zeros = FALSE;
	data->show_sign = FALSE;
	data->blank_space = FALSE;
	data->zerox = FALSE;
	data->width = 0;
	data->precision = 6;
	return (TRUE);
}

static int				init_printf(t_printf *data, const char *format)
{
	data->fd = 1;
	data->len = 0;
	if (!(data->result = ft_strnew(0)))
		return (FALSE);
	data->format = (char*)format;
	reset_var_specific_data(data);
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
