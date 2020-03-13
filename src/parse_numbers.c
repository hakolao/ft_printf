/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:52:00 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/13 17:12:55 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t				parse_type(t_printf *data)
{
	intmax_t		var;

	if (data->c == 'U' && (data->c = 'u'))
		data->type = length_l;
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

static char				*printf_itoa(t_printf *data, intmax_t var,
						int base, int is_signed)
{
	int				is_conversion_up;

	is_conversion_up = data->type == length_l || data->type == length_ll ||
	data->type == length_j || data->type == length_z || data->type == length_t;
	if (!is_signed)
	{
		if (data->type == length_hh)
			return (ft_itoa_u_base((unsigned char)var, base));
		else if (data->type == length_h)
			return (ft_itoa_u_base((unsigned short int)var, base));
		else if (is_conversion_up)
			return (ft_itoa_uintmax_base(var, base));
		else
			return (ft_itoa_u_base(var, base));
	}
	else if (data->type == length_hh)
		return (ft_itoa_base((char)var, base));
	else if (data->type == length_h)
		return (ft_itoa_base((short int)var, base));
	else if (is_conversion_up)
		return (ft_itoa_intmax_base(var, base));
	return (ft_itoa_base(var, base));
}

char					*parse_int(t_printf *data)
{
	int				i;
	int				is_zero;
	char			*res;
	intmax_t		var;

	var = parse_type(data);
	res = NULL;
	is_zero = TRUE;
	if (data->has_precision && data->precision == 0 && var == 0)
		res = ft_strdup("");
	else if ((data->c == 'd' || data->c == 'i'))
		res = printf_itoa(data, var, 10, TRUE);
	else if (data->c == 'u')
		res = printf_itoa(data, var, 10, FALSE);
	else if (data->c == 'o')
		res = printf_itoa(data, var, 8, FALSE);
	else if ((data->c == 'x' || data->c == 'X'))
		res = printf_itoa(data, var, 16, FALSE);
	data->var_len = ft_strlen(res);
	i = -1;
	while (res[++i])
		if (res[i] != '0' && !(is_zero = FALSE))
			break ;
	data->is_zero_res = is_zero;
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
