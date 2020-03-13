/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:59:46 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/13 19:25:37 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*handle_precision(t_printf *data, char *res)
{
	if (is_int_specifier(data->c))
		res = handle_number_precision(data, res);
	else if (is_float_specifier(data->c))
		res = handle_number_precision(data, res);
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
	if (is_int_specifier(data->c) || is_float_specifier(data->c))
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
