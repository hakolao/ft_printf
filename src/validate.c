/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:13:32 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/04 16:55:25 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						is_int_specifier(char c)
{
	return (c == 'd' || c == 'i' || c == 'u' ||
			c == 'o' || c == 'x' || c == 'X');
}

int						is_float_specifier(char c)
{
	return (c == 'f' || c == 'F' || c == 'e' || c == 'E' || c == 'g' ||
			c == 'G' || c == 'a' || c == 'A');
}

int						is_char_specifier(char c)
{
	return (c == 'c' || c == 's');
}

int						is_specifier(char c)
{
	return (is_int_specifier(c) || is_float_specifier(c) ||
			is_char_specifier(c) || c == 'p' || c == 'n' || c == '%');
}

int						is_flag(char c)
{
	return (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0');
}

int						is_sub_specifier(char c)
{
	return ((c == '-' || c == '+' || c == 'h' || c == 'l' || c == 'j' ||
			c == 'z' || c == 't' || c == 'L' || ft_isdigit(c) ||
			c == '#' || c == '.' || c == '*' || c == ' '));
}



t_printf_lengths		ft_printf_lengths(char *fmt, t_printf_lengths lengths)
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
