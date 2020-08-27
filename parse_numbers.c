/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:52:00 by ohakola           #+#    #+#             */
/*   Updated: 2020/08/27 15:07:38 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t			parse_type(t_printf *data)
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
		data->is_negative = true;
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
	char			*res;
	intmax_t		var;

	var = parse_type(data);
	res = NULL;
	if (data->has_precision && data->precision == 0 && var == 0)
		res = ft_strnew(0);
	else if (data->c == 'd' || data->c == 'i')
		res = printf_itoa(data, var, 10, true);
	else if (data->c == 'u')
		res = printf_itoa(data, var, 10, false);
	else if (data->c == 'o')
		res = printf_itoa(data, var, 8, false);
	else if (data->c == 'x' || data->c == 'X')
		res = printf_itoa(data, var, 16, false);
	else if (data->c == 'b')
		res = printf_itoa(data, ft_abs(var), 2, true);
	data->var_len = ft_strlen(res);
	check_parsed_zero(data, res);
	return (res);
}

char					*parse_float(t_printf *data)
{
	char				*res;
	char				buf[DTOA_BUF_SIZE];
	long double			var;
	t_float_dissector	fds;

	res = NULL;
	if (data->type == length_L)
		var = va_arg(data->variables, long double);
	else
		var = va_arg(data->variables, double);
	fds.f = var;
	if (fds.b.sign)
		data->is_negative = true;
	data->precision = data->precision >= 0 ? data->precision : 6;
	data->var_len = ft_dtoa_buf((t_dtoa_params){.precision = data->precision,
		.value = var, .format = data->c == 'f' || data->c == 'F' ?
			FORMAT_NORM : FORMAT_SCI},
		buf, DTOA_BUF_SIZE);
	if (!(res = ft_strnew(data->var_len)))
		return (NULL);
	ft_memmove(res, buf, data->var_len);
	if (data->c == 'E')
		ft_capitalize(res);
	return (res);
}

char					*parse_address(t_printf *data)
{
	char		*res;
	uintmax_t	var;

	var = va_arg(data->variables, long long int);
	if (var != 0)
		res = ft_itoa_uintmax_base(var, 16);
	else if (var == 0 && ft_abs(data->precision) > 0)
	{
		res = ft_strnew(1);
		res[0] = '0';
	}
	else
		res = ft_strnew(0);
	data->var_len = ft_strlen(res);
	return (res);
}
