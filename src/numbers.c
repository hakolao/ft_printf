/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:52:00 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/28 16:35:42 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char				*handle_number_formats(t_printf *data, char *res)
{
	int		len;
	int		i;

	len = ft_strlen(res);
	if (data->show_sign && !ft_strchr(res, '-'))
	{
		res = add_char_to_beg(res, '+', len + 1);
		len++;
	}
	if (data->width > 0 && len < data->width)
	{
		res = add_to_str(res, data->width);
		if (!data->left_justify)
		{
			ft_strrev(res);
			i = len;
			while (i < data->width)
				res[i++] = data->pad_zeros ? '0' : ' ';
			ft_strrev(res);
		}
		else
		{
			i = len;
			while (i < data->width)
				res[i++] = data->pad_zeros ? '0' : ' ';
		}
	}
	if (!data->show_sign && data->blank_space)
	{
		len = ft_strlen(res);
		res = add_char_to_beg(res, ' ', len + 1);
	}
	return (res);
}

char					*parse_int(t_printf *data)
{
	char			*res;
	char			c;
	unsigned		var;

	res = NULL;
	c = data->spec[data->spec_len - 1];
	var = va_arg(data->variables, unsigned);
	if (c == 'd' || c == 'i')
		res = ft_itoa(var);
	else if (c == 'u')
		res = var < 0 ? ft_itoa_long(((long int)1 << 32) + var) :
			ft_itoa_long(var);
	else if (c == 'o')
		res = var < 0 ? ft_itoa_long_base(((long int)1 << 32) + var, 8) :
			ft_itoa_long_base(var, 8);
	else if (c == 'x' || c == 'X')
		res = var < 0 ? ft_itoa_long_base(((long int)1 << 32) + var, 16) :
			ft_itoa_long_base(var, 16);
	if (data->zerox && c == 'o')
		res = add_char_to_beg(res, '0', ft_strlen(res) + 1);
	if (data->zerox && (c == 'x' || c == 'X'))
		res = add_str_to_beg(res, "0x");
	res = handle_number_formats(data, res);
	if (c == 'X')
		ft_capitalize(res);
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
	res = handle_number_formats(data, res);
	return (res);
}
