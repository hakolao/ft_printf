/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:52:00 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/27 13:37:14 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*parse_int(t_printf *data)
{
	char			*res;
	char			c;
	int				i;

	res = NULL;
	c = data->spec[data->spec_len - 1];
	if (c == 'd' || c == 'i')
		res = ft_itoa(va_arg(data->variables, int));
	else if (c == 'u')
		res = ft_itoa(va_arg(data->variables, unsigned int));
	else if (c == 'o')
		res = ft_itoa_base(va_arg(data->variables, unsigned int), 8);
	else if (c == 'x' || c == 'X')
	{
		res = ft_itoa_base(va_arg(data->variables, unsigned int), 16);
		if (c == 'X')
		{
			i = -1;
			while (res[++i])
				res[i] = ft_toupper(res[i]);
		}
	}
	return (res);
}

char					*parse_float(t_printf *data)
{
	char	*res;
	char	c;

	c = data->spec[data->spec_len - 1];
	res = ft_ftoa(va_arg(data->variables, double), 5);
	return (res);
}
