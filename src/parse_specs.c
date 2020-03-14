/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:07:54 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/14 17:21:31 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char				*parse_string(t_printf *data)
{
	char	*res;
	void	*var;

	var = (void*)va_arg(data->variables, char*);
	if (!(res = var ? ft_strdup((char*)var) : ft_strdup("(null)")))
		return (NULL);
	data->var_len = ft_strlen(res);
	return (res);
}

static char				*parse_char(t_printf *data)
{
	char	*res;

	if (!(res = ft_strnew(1)))
		return (NULL);
	res[0] = va_arg(data->variables, int);
	data->var_len = 1;
	return (res);
}

static char				*parse_variable(t_printf *data)
{
	char	*res;

	data->c = data->spec[data->spec_len - 1];
	if (data->spec_len > 1)
		parse_sub_specifiers(data);
	if (is_int_specifier(data->c))
		return (handle_formatting(data, parse_int(data)));
	else if (is_float_specifier(data->c))
		return (handle_formatting(data, parse_float(data)));
	else if (data->c == 'p')
		return (handle_formatting(data, parse_address(data)));
	else if (data->c == 's')
		return (handle_formatting(data, parse_string(data)));
	else if (data->c == 'c')
		return (handle_formatting(data, parse_char(data)));
	else if (data->c == '%' && (data->var_len = 1))
		return (handle_formatting(data, ft_strdup("%")));
	if (!(res = ft_strnew(1)))
		return (NULL);
	res[0] = data->c;
	data->var_len++;
	return (res);
}

char					*parse_spec_variable_pair(t_printf *data, char *fmt)
{
	char	*spec;
	char	*variable;
	int		i;

	if (!(spec = ft_strnew(data->spec_len)))
		return (NULL);
	spec = ft_strncpy(spec, fmt, data->spec_len);
	data->spec = spec;
	if (!(variable = parse_variable(data)))
		return (NULL);
	ft_strdel(&spec);
	data->buffer = extend_str(data->buffer, data->len, data->var_len);
	i = -1;
	while (++i < data->var_len)
		data->buffer[data->len + i] = variable[i];
	data->len += data->var_len;
	data->buffer[data->len] = '\0';
	ft_strdel(&variable);
	return (data->buffer);
}
