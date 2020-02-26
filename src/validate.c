/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:13:32 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/26 17:47:02 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						is_allowed_specifier(char c)
{
	return (c == 'd' || c == 'i' || c == 'u' || c == 'o' || c == 'x' || c == 'X'
			|| c == 'f' || c == 'F' || c == 'e' || c == 'E' || c == 'g' ||
			c == 'G' || c == 'a' || c == 'A' || c == 'c' || c == 's' ||
			c == 'p' || c == 'n' || c == '%');
}

int						is_allowed_sub_specifier(char c)
{
	return (c == '-' || c == '+' || c == 'h' || c == 'l' || c == 'j' ||
			c == 'z' || c == 't' || c == 'L' || ft_isdigit(c) || c == '#');
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