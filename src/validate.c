/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:13:32 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/14 19:13:58 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						is_int_specifier(char c)
{
	return (c == 'd' || c == 'i' || c == 'u' || c == 'U' ||
			c == 'o' || c == 'x' || c == 'X' || c == 'b');
}

int						is_float_specifier(char c)
{
	return (c == 'f' || c == 'F' || c == 'e' || c == 'E' || c == 'g' ||
			c == 'G');
}

int						is_specifier(char c)
{
	return (is_int_specifier(c) || is_float_specifier(c) ||
			c == 'c' || c == 's' || c == 'p' || c == 'n' || c == '%');
}

int						is_flag(char c)
{
	return (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0');
}

int						is_sub_specifier(char c)
{
	return (is_flag(c) || c == 'h' || c == 'l' || c == 'j' ||
			c == 'z' || c == 't' || c == 'L' || ft_isdigit(c) ||
			c == '.' || c == '*' || c == '\'');
}
