/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:00:25 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/27 12:52:45 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>



char					*parse_float(char c, float var)
{
	char	*res;

	(void)c;
	res = ft_ftoa(var, 5);
	return (res);
}

char					*parse_address(char c, void *var)
{
	(void)c;
	(void)var;
	return (NULL);
}

char					*parse_arg(char c, t_printf *data, char *specs)
{
	char	*ret;

	(void)specs;
	if (is_int_specifier(c))
		ret = parse_int(c, va_arg(data->variables, int));
	else if (is_float_specifier(c))
		ret = parse_float(c, va_arg(data->variables, double));
	else if (c == 's')
		ret = ft_strdup(va_arg(data->variables, char*));
	else if (c == 'c')
	{
		if (!(ret = ft_strnew(1)))
			return (NULL);
		ret[0] = va_arg(data->variables, int);
	}
	else if (c == 'p')
		ret = parse_address(c, va_arg(data->variables, void *));
	else if (c == '%')
		ret = ft_strdup("%");
	else
		ret = ft_strnew(0);
	return (ret);
}

int						parse_specifiers(t_printf *data, char *fmt,
						int spec_len)
{
	char	*specs;
	char	*tmp;
	char	*variable;

	(void)data;
	if (!(specs = ft_strnew(spec_len)))
		return (FALSE);
	specs = ft_strncpy(specs, fmt, spec_len);
	if (!(variable = parse_arg(specs[spec_len - 1], data, specs)))
		return (FALSE);
	tmp = data->result;
	if (!(data->result = ft_strjoin(data->result, variable)))
		return (FALSE);
	data->len += ft_strlen(variable);
	ft_strdel(&tmp);
	return (TRUE);
}

char					*parse_middle(t_printf *data, char *fmt,
						int middle_len)
{
	char	*middle;
	char	*tmp;

	tmp = data->result;
	if (!(middle = ft_strnew(middle_len)) ||
		!(middle = ft_strncpy(middle, fmt, middle_len)) ||
		!(data->result = ft_strjoin(data->result, middle)))
		return (NULL);
	data->len += middle_len;
	ft_strdel(&middle);
	ft_strdel(&tmp);
	return (data->result);
}

int						parse_variables(t_printf *data, char *fmt)
{
	t_printf_lengths	l;

	l = ft_printf_lengths(fmt, (t_printf_lengths){0, 0, 0});
	if (l.middle_len > 0 &&
		!(data->result = parse_middle(data, fmt, l.middle_len)))
		return (FALSE);
	if (l.middle_len == 0 && l.spec_len == 0 && *fmt == '%' &&
		!(data->result = parse_middle(data, fmt, 1)))
		return (FALSE);
	if (l.spec_len > 0 &&
		parse_specifiers(data, fmt + l.middle_len + 1,
		l.spec_len))
		fmt += l.middle_len + 1 + l.spec_len;
	else if (l.middle_len > 0)
		fmt += l.middle_len;
	else if (*fmt == '%')
		fmt += 1;
	return (*fmt ? parse_variables(data, fmt) : TRUE);
}

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
