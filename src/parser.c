/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:05:04 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/27 17:28:39 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char				*parse_arg(t_printf *data)
{
	char	*ret;
	char	c;

	if (data->spec_len > 1)
		parse_sub_specifiers(data);
	c = data->spec[data->spec_len - 1];
	if (is_int_specifier(c))
		ret = parse_int(data);
	else if (is_float_specifier(c))
		ret = parse_float(data);
	else if (c == 's')
		ret = ft_strdup(va_arg(data->variables, char*));
	else if (c == 'c')
	{
		if (!(ret = ft_strnew(1)))
			return (NULL);
		ret[0] = va_arg(data->variables, int);
	}
	else if (c == 'p')
		ret = parse_address(data);
	else if (c == '%')
		ret = ft_strdup("%");
	else
		ret = ft_strnew(0);
	return (ret);
}

static int				parse_specifiers(t_printf *data, char *fmt,
						int spec_len)
{
	char	*spec;
	char	*tmp;
	char	*variable;

	if (!(spec = ft_strnew(spec_len)))
		return (FALSE);
	spec = ft_strncpy(spec, fmt, spec_len);
	data->spec = spec;
	data->spec_len = spec_len;
	if (!(variable = parse_arg(data)))
		return (FALSE);
	ft_strdel(&spec);
	tmp = data->result;
	if (!(data->result = ft_strjoin(data->result, variable)))
		return (FALSE);
	data->len += ft_strlen(variable);
	ft_strdel(&variable);
	ft_strdel(&tmp);
	return (TRUE);
}

static char				*parse_middle(t_printf *data, char *fmt,
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
