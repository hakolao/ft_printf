/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:52:00 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/05 14:00:13 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char				*handle_formatting(t_printf *data, char *res)
{
	int		len;

	len = ft_strlen(res);
	if (data->show_sign && !ft_strchr(res, '-'))
	{
		res = add_char_to_beg(res, '+', len + 1);
		len++;
	}
	res = handle_padding(data, res, len);
	if (!data->show_sign && data->blank_space)
	{
		len = ft_strlen(res);
		res = add_char_to_beg(res, ' ', len + 1);
	}
	return (res);
}

intmax_t				parse_type(t_printf *data)
{
	intmax_t		var;

	if (data->length_type == length_h)
		var = (intmax_t)((char)va_arg(data->variables, int));
	else if (data->length_type == length_l)
		var = (intmax_t)(va_arg(data->variables, long int));
	else if (data->length_type == length_ll)
		var = (intmax_t)(va_arg(data->variables, long long int));
	else if (data->length_type == length_j)
		var = (intmax_t)(va_arg(data->variables, long long int));
	else if (data->length_type == length_z)
		var = (intmax_t)(va_arg(data->variables, long long int));
	else
		var = (intmax_t)va_arg(data->variables, int);
	return (var);
}

char					*parse_int(t_printf *data)
{
	char			*res;
	char			c;
	intmax_t		var;

	res = NULL;
	c = data->spec[data->spec_len - 1];
	var = parse_type(data);
	if (data->has_precision && data->precision == 0)
		res = ft_strdup("");
	else if (c == 'd' || c == 'i')
		res = ft_itoa_long_base(var, 10);
	else if (c == 'u' || c == 'd' || c == 'i')
		res = var < 0 ? ft_itoa_long_base(((long int)1 << 32) + var, 10) :
			ft_itoa_long_base(var, 10);
	else if (c == 'o')
		res = var < 0 ? ft_itoa_long_base(((long int)1 << 32) + var, 8) :
			ft_itoa_long_base(var, 8);
	else if (c == 'x' || c == 'X')
		res = var < 0 ? ft_itoa_long_base(((long int)1 << 32) + var, 16) :
			ft_itoa_long_base(var, 16);
	if (data->zerox && c == 'o')
		res = add_char_to_beg(res, '0', ft_strlen(res) + 1);
	if (data->zerox && (c == 'x' || c == 'X') && var != 0)
		res = add_str_to_beg(res, "0x");
	res = handle_formatting(data, res);
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
	res = handle_formatting(data, res);
	return (res);
}
