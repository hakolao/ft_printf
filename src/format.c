/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:59:46 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/10 13:53:22 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*handle_precision(t_printf *data, char *res)
{
	if (is_int_specifier(data->c))
		return (handle_int_precision(data, res));
	else if (data->c == 'p')
		return (handle_int_precision(data, res));
	else if (data->c == 's')
		return (handle_string_precision(data, res));
	else if (data->c == 'c')
		return (handle_char_precision(data, res));
	return (res);
}

char					*handle_padding(t_printf *data, char *res)
{
	if (is_int_specifier(data->c))
		return (res);
	else if (is_float_specifier(data->c))
		return (res);
	else if (data->c == 'p')
		return (res);
	else if (data->c == 's')
		return (res);
	else if (data->c == 'c')
		return (res);
	else if (data->c == '%')
		return (res);
	return (res);
}

char					*handle_formatting(t_printf *data, char *res)
{
	res = handle_precision(data, res);
	res = handle_padding(data, res);
	return (res);
}

t_printf_lengths		fmt_part_lengths(char *fmt, t_printf_lengths lengths)
{
	int					i;
	char				*next;

	i = 0;
	next = ft_strchr(fmt, '%');
	if (!next)
	{
		i = -1;
		while (fmt[++i])
			lengths.middle_len++;
		return (lengths);
	}
	if (fmt && next && next - fmt > 0)
	{
		i = next - fmt;
		lengths.middle_len = next - fmt;
	}
	i++;
	if (fmt[i] && (!is_sub_specifier(fmt[i]) &&
		!is_specifier(fmt[i])))
		return (lengths);
	while (fmt[i] && is_sub_specifier(fmt[i]))
	{
		lengths.spec_len++;
		i++;
	}
	if (is_specifier(fmt[i]))
		lengths.spec_len++;
	else
		lengths.spec_len = 0;
	return (lengths);
}