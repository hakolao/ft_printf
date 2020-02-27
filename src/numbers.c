/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:52:00 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/27 20:24:22 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int			next_var_arg(t_printf *data)
{
	unsigned		var;

	var = va_arg(data->variables, unsigned);
	if (data->use_prev_var)
	{
		data->previous_variable = var;
		var = va_arg(data->variables, unsigned);
		data->width = (int)var;
	}
	return (var);
}

char					*parse_int(t_printf *data)
{
	char			*res;
	char			c;
	int				i;
	unsigned		var;

	res = NULL;
	c = data->spec[data->spec_len - 1];
	var = next_var_arg(data);
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
		i = -1;
		if (c == 'X')
			while (res[++i])
				res[i] = ft_toupper(res[i]);
	}
	return (res);
}

char					*parse_float(t_printf *data)
{
	char	*res;
	char	c;

	c = data->spec[data->spec_len - 1];
	if (c == 'f')
		res = ft_ftoa(va_arg(data->variables, double),
		data->precision);
	else
		res = ft_ftoa(va_arg(data->variables, double),
		data->precision);
	return (res);
}
