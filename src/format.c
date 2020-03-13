/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:59:46 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/13 15:10:22 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*handle_zerox(t_printf *data, char *res)
{
	int		i;
	int		is_zero;

	is_zero = TRUE;
	if (data->c == 'o')
	{
		res = add_str_to_beg(res, "0");
		data->var_len += 1;
	}
	else if (data->c == 'x' || data->c == 'X')
	{
		i = -1;
		while (res[++i])
			if (res[i] != '0' && !(is_zero = FALSE))
				break ;
		if (is_zero)
			return (res);
		res = add_str_to_beg(res, "0x");
		data->var_len += 2;
	}
	return (res);
}

char					*handle_precision(t_printf *data, char *res)
{
	if (is_int_specifier(data->c))
	{
		if (data->show_sign && !data->is_negative)
		{
			res = add_str_to_beg(res, "+");
			data->var_len += 1;
		}
		res = handle_int_precision(data, res);
		if (data->blank_space)
			res = handle_blank(data, res);
		if (data->zerox)
			res = handle_zerox(data, res);
		if (data->c == 'X')
			ft_capitalize(res);
		return (res);
	}
	else if (data->c == 'p')
		return (handle_int_precision(data, res));
	else if (data->c == 's')
		return (handle_string_precision(data, res));
	return (res);
}

char					*handle_padding(t_printf *data, char *res)
{
	if (is_int_specifier(data->c))
		return (handle_int_padding(data, res));
	else if (is_float_specifier(data->c))
		return (handle_float_padding(data, res));
	else if (data->c == 'p')
		return (handle_int_padding(data, res));
	else if (data->c == 's')
		return (handle_string_padding(data, res));
	else if (data->c == 'c')
		return (handle_char_padding(data, res));
	else if (data->c == '%')
		return (handle_string_padding(data, res));
	return (res);
}

char					*handle_formatting(t_printf *data, char *res)
{
	if (is_int_specifier(data->c))
	{
		if (data->left_justify ||
			(data->has_precision && data->precision == 0))
			data->pad_zeros = FALSE;
		if (data->show_sign || data->is_negative)
			data->blank_space = FALSE;
	}
	else if (!is_int_specifier(data->c))
	{
		if (data->blank_space || data->left_justify)
			data->pad_zeros = FALSE;
	}
	res = handle_precision(data, res);
	res = handle_padding(data, res);
	return (res);
}
