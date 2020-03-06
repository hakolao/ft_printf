/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:59:46 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/06 16:31:42 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*handle_precision(t_printf *data, char *res)
{
	(void)data;
	return (res);
}

char					*handle_padding(t_printf *data, char *res)
{
	(void)data;
	return (res);
}

char					*handle_formatting(t_printf *data, char *res)
{
	int		len;

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