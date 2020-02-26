/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:00:25 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/26 16:44:07 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_sub_specs(t_printf *data, char *symbol)
{
	int	len;

	(void)data;
	len = ft_strlen(symbol);
	if (len == 1)
		return (TRUE);
	return (TRUE);
}

char	*variable_by_spec(t_printf *data, char *symbol)
{
	char	*result;

	result = NULL;
	parse_sub_specs(data, symbol);
	return (result);
}

int						parse_specifiers(t_printf *data, char *fmt,
						int spec_len)
{
	char	*spec;
	char	*tmp;
	char	*variable;

	(void)data;

	if (!(spec = ft_strnew(spec_len)))
		return (FALSE);
	spec = ft_strncpy(spec, fmt, spec_len);
	ft_putstr(spec);
	ft_putstr("\n");
	if (!(variable = variable_by_spec(data, spec)))
		return (FALSE);
	tmp = data->result;
	if (!(data->result = ft_strjoin(data->result, variable)))
		return (FALSE);
	ft_strdel(&tmp);
	return (TRUE);
}

t_printf_lengths		ft_printf_lengths(char *fmt, t_printf_lengths lengths)
{
	int					i;

	i = 0;
	while (fmt[i] && fmt[i] != '%')
	{
		lengths.middle_len++;
		i++;
	}
	i++;
	if (fmt[i] && (!is_allowed_sub_specifier(fmt[i]) &&
		!is_allowed_specifier(fmt[i])))
		return (lengths);
	while (fmt[i] && is_allowed_sub_specifier(fmt[i]))
	{
		lengths.sub_spec_len++;
		lengths.spec_len++;
		i++;
	}
	if (is_allowed_specifier(fmt[i]))
		lengths.spec_len++;
	else
		lengths.spec_len = 0;
	return (lengths);
}

int						parse_variables(t_printf *data, char *fmt)
{
	char				*tmp;
	char				*middle;
	t_printf_lengths	lengths;

	lengths = ft_printf_lengths(fmt, (t_printf_lengths){0, 0, 0});
	if (lengths.middle_len > 0)
	{
		tmp = data->result;
		if (!(middle = ft_strnew(lengths.middle_len)) ||
			!(middle = ft_strncpy(middle, fmt, lengths.middle_len)) ||
			!(data->result = ft_strjoin(data->result, middle)))
			return (FALSE);
		data->len += lengths.middle_len;
		ft_strdel(&middle);
		ft_strdel(&tmp);
	}
	if (lengths.spec_len > 0)
		parse_specifiers(data, fmt + lengths.middle_len, lengths.spec_len);
	if (lengths.middle_len > 0 || lengths.spec_len > 0)
		return (parse_variables(data,
				fmt + lengths.middle_len + 1 + lengths.spec_len));
	return (TRUE);
}

int						ft_printf(const char *format, ...)
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
	write(data.fd, data.result, data.len);
	ft_strdel(&data.result);
	return (data.len);
}
