/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:52:00 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/27 13:49:59 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*parse_int(t_printf *data)
{
	char			*res;
	char			c;
	int				i;
	unsigned		var;

	res = NULL;
	c = data->spec[data->spec_len - 1];
	var = va_arg(data->variables, int);
	if (c == 'd' || c == 'i')
		res = ft_itoa(var);
	else if (c == 'u')
		res = var < 0 ? ft_itoa_long(((long int)1 << 32) + var) :
			ft_itoa_long(var);
	else if (c == 'o')
		res = var < 0 ? ft_itoa_long_base(((long int)1 << 32) + var, 8) :
			ft_itoa_long_base(var, 8);
	else if (c == 'x' || c == 'X')
	{
		res = var < 0 ? ft_itoa_long_base(((long int)1 << 32) + var, 16) :
			ft_itoa_long_base(var, 16);
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
