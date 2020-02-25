/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:00:25 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/25 16:54:05 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int		is_allowed_specifier(char c)
{
	return (c == 'd' || c == 'i' || c == 'u' || c == 'o' || c == 'x' || c == 'X'
			|| c == 'f' || c == 'F' || c == 'e' || c == 'E' || c == 'g' ||
			c == 'G' || c == 'a' || c == 'A' || c == 'c' || c == 's' ||
			c == 'p' || c == 'n' || c == '%');
}

int		is_allowed_sub_specifier(char c)
{
	return (c == '-' || c == '+' || c == 'h' || c == 'l' || c == 'j' ||
			c == 'z' || c == 't' || c == 'L' || ft_isdigit(c));
}

int		var_formats_len(const char *format)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (format[i] && format[i + 1])
	{
		if (format[i] == '%')
		{
			if (is_allowed_specifier(format[i + 1]) ||
				is_allowed_sub_specifier(format[i + 1]))
				len++;
			while (format[i] && is_allowed_sub_specifier(format[i]) &&
					!is_allowed_specifier(format[i]))
				i++;
			while (format[i] && format[i + 1] &&
					!is_allowed_sub_specifier(format[i]) &&
					is_allowed_specifier(format[i]) &&
					format[i + 1] != '%')
				i++;
		}
		i++;
	}
	return (len);
}

int		ft_printf(const char *format, ...)
{
	int		i;
	int		formats_size;
	// char	**var_formats;

	i = 0;
	formats_size = var_formats_len(format);
	while (format[i])
	{
		
		i++;
	}
	printf("Formats size: %d\n", formats_size);
	return (0);
}
