/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:52:00 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/12 14:06:42 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t				parse_type(t_printf *data)
{
	intmax_t		var;

	if (data->type == length_h)
		var = (intmax_t)((short int)va_arg(data->variables, int));
	else if (data->type == length_hh)
		var = (intmax_t)((char)va_arg(data->variables, unsigned int));
	else if (data->type == length_l)
		var = (intmax_t)(va_arg(data->variables, long int));
	else if (data->type == length_ll)
		var = (intmax_t)(va_arg(data->variables, long long int));
	else if (data->type == length_j)
		var = (intmax_t)(va_arg(data->variables, long long int));
	else if (data->type == length_z)
		var = (intmax_t)(va_arg(data->variables, long long int));
	else
		var = (intmax_t)va_arg(data->variables, int);
	if (var < 0)
		data->is_negative = TRUE;
	return (var);
}

char					*parse_int(t_printf *data)
{
	char			*res;
	intmax_t		var;

	res = NULL;
	var = parse_type(data);
	if (data->has_precision && data->precision == 0 && var == 0)
		res = ft_strdup("");
	else if (data->c == 'd' || data->c == 'i')
		res = ft_itoa_long_base(var, 10);
	else if (data->c == 'u' && data->type != length_l &&
		data->type != length_ll)
		res = ft_itoa_u_base(var, 10);
	else if (data->c == 'u' && (data->type == length_l ||
		data->type == length_ll))
		res = ft_itoa_uintmax_base(var, 10);
	else if (data->c == 'o')
		res = var < 0 ? ft_itoa_long_base(((long int)1 << 32) + var, 8) :
			ft_itoa_long_base(var, 8);
	else if ((data->c == 'x' || data->c == 'X') && data->type == length_j)
		res = ft_itoa_uintmax_base(var, 16);
	else if ((data->c == 'x' || data->c == 'X'))
		res = var < 0 ? ft_itoa_long_base(((long int)1 << 32) + var, 16) :
			ft_itoa_long_base(var, 16);
	data->var_len = ft_strlen(res);
	return (res);
}

char					*parse_float(t_printf *data)
{
	char	*res;

	if (data->c == 'f')
		res = ft_ftoa(va_arg(data->variables, double),
		data->precision);
	else
		res = ft_ftoa(va_arg(data->variables, double),
		data->precision);
	data->var_len = ft_strlen(res);
	return (res);
}

char					*parse_address(t_printf *data)
{
	return (add_str_to_beg(ft_itoa_uintmax_base(va_arg(data->variables,
		long long int), 16), "0x"));
}
