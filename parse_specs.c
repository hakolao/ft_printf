/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:07:54 by ohakola           #+#    #+#             */
/*   Updated: 2021/05/04 16:58:35 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Parses char * variables handling also the special null case
*/

static char	*parse_string(t_printf *data)
{
	char	*res;
	char	*var;

	var = va_arg(data->variables, char *);
	if (var)
	{
		res = ft_strdup(var);
		data->var_len = ft_strlen(res);
		return (res);
	}
	res = ft_strdup("(null)");
	data->var_len = 6;
	return (res);
}

/*
** Parses char variables
*/

static char	*parse_char(t_printf *data)
{
	char	*res;

	res = ft_strnew(1);
	if (!res)
		return (NULL);
	res[0] = va_arg(data->variables, int);
	data->var_len = 1;
	return (res);
}

/*
** Parses variable and based on t_printf *data mapped by parse_sub_specifiers
** outputs varialble to char *res to be later copied to buffer.
*/

static char	*parse_variable(t_printf *data)
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
	else if (data->c == '%')
	{
		data->var_len = 1;
		return (handle_formatting(data, ft_strdup("%")));
	}
	else if (data->c == 'n')
		return (print_nothing_case(data));
	data->var_len++;
	return (handle_formatting(data, (res = ft_strdup(&data->c))));
}

/*
** Parses spec from fmt, based on that parses variable input and outputs
** result to data->buffer.
*/

int	parse_spec_variable_pair(t_printf *data, char *fmt)
{
	char	*variable;
	int		i;

	data->spec = fmt;
	variable = parse_variable(data);
	if (!variable)
		return (false);
	data->buffer = extend_str(data->buffer, data->len, data->var_len);
	if (!data->buffer)
		return (false);
	i = -1;
	while (++i < data->var_len)
		data->buffer[data->len + i] = variable[i];
	data->len += data->var_len;
	data->buffer[data->len] = '\0';
	ft_strdel(&variable);
	return (true);
}
