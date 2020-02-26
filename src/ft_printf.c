/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:00:25 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/26 14:11:31 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_variables(t_printf *data)
{
	char	*fmt;
	char	*middle;
	char	*next;
	int		len_to_next;

	fmt = data->format;
	next = ft_strchr(fmt, '%');
	len_to_next = next ? next - fmt : ft_strlen(fmt);
	if (!(middle = ft_strnew(len_to_next)))
		return (FALSE);
	middle = ft_strncpy(middle, fmt, len_to_next);
	data->result = middle;
	data->len += len_to_next;
	// parse_symbol(data);
	return (TRUE);
}

int		ft_printf(const char *format, ...)
{
	t_printf	data;

	data.fd = 1;
	data.len = 0;
	data.result = NULL;
	data.format = (char*)format;
	va_start(data.variables, format);
	if (!parse_variables(&data))
	{
		ft_putstr_fd(data.error, 2);
		return (FALSE);
	}
	va_end(data.variables);
	write(data.fd, data.result, data.len);
	ft_strdel(&data.result);
	return (data.len);
}
