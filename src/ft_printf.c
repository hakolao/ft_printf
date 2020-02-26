/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:00:25 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/26 17:52:05 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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

	if (!(result = ft_strnew(3)))
		return (NULL);
	result = "var";
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
	if (!(variable = variable_by_spec(data, spec)))
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
	t_printf_lengths	lengths;

	lengths = ft_printf_lengths(fmt, (t_printf_lengths){0, 0, 0});
	printf("middle: %d, spec: %d sub_spec: %d\n",
	lengths.middle_len, lengths.spec_len, lengths.sub_spec_len);
	if (lengths.middle_len > 0)
		if (!(data->result = parse_middle(data, fmt, lengths.middle_len)))
			return (FALSE);
	if (lengths.middle_len == 0 && lengths.spec_len == 0 && *fmt == '%')
		if (!(data->result = parse_middle(data, fmt, 1)))
			return (FALSE);
	if (lengths.spec_len > 0)
	{
		parse_specifiers(data, fmt + lengths.middle_len + 1,
			lengths.spec_len);
		fmt += lengths.middle_len + 1 + lengths.spec_len;
	}
	else if (lengths.middle_len > 0)
		fmt += lengths.middle_len;
	else if (*fmt == '%')
		fmt += 1;
	return (*fmt ? parse_variables(data, fmt) : TRUE);
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
