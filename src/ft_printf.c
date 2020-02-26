/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:00:25 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/26 15:09:31 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_allowed_specifier(char c)
{
	return (c == 'd' || c == 'i' || c == 'u' || c == 'o' || c == 'x' || c == 'X'
			|| c == 'f' || c == 'F' || c == 'e' || c == 'E' || c == 'g' ||
			c == 'G' || c == 'a' || c == 'A' || c == 'c' || c == 's' ||
			c == 'p' || c == 'n' || c == '%');
}

int		is_allowed_sub_specifier(char c)
{
	return (c == '-' || c == '+' || c == 'h' || c == 'l' || c == 'j' ||
			c == 'z' || c == 't' || c == 'L' || ft_isdigit(c));
}

int		parse_sub_specs(t_printf *data, char *symbol)
{
	int	len;

	(void)data;
	len = ft_strlen(symbol);
	if (len > 1)
	{
		ft_putstr("Sub specs:\n");
		write(1, symbol, len - 1);
		ft_putstr("\n-----");
	}
	return (TRUE);
}

int		parse_specifiers(t_printf *data, char *fmt)
{
	char	*symbol;
	int		i;

	i = 0;
	(void)data;
	while (fmt[i] &&
		is_allowed_sub_specifier(fmt[i]))
		i++;
	if (fmt[i] && is_allowed_specifier(fmt[i]))
		i++;
	else
		return (FALSE);
	if (!(symbol = ft_strnew(i)))
		return (FALSE);
	symbol = ft_strncpy(symbol, fmt, i);
	ft_putstr("Specs:\n");
	ft_putstr(symbol);
	ft_putstr("\n-----\n");
	parse_sub_specs(data, symbol);
	return (TRUE);
}

int		parse_variables(t_printf *data, char *fmt)
{
	char	*next;
	int		len;

	next = ft_strchr(fmt, '%');
	len = next ? next - fmt : ft_strlen(fmt);
	if (next == NULL)
		return (TRUE);
	data->len += len;
	parse_specifiers(data, fmt);
	return (parse_variables(data, fmt + len + 1));
}

int		ft_printf(const char *format, ...)
{
	t_printf	data;

	data.fd = 1;
	data.len = 0;
	if (!(data.result = ft_strnew(0)))
		return (FALSE);
	data.format = (char*)format;
	va_start(data.variables, format);
	if (!parse_variables(&data, (char*)format))
	{
		ft_putstr_fd(data.error, 2);
		return (FALSE);
	}
	va_end(data.variables);
	// write(data.fd, data.result, data.len);
	// ft_strdel(&data.result);
	return (data.len);
}
