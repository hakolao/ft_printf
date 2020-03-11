/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:50:00 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/11 12:41:38 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*handle_int_precision(t_printf *data, char *res)
{
	int		len;
	int		add_size;
	int		new_var_len;

	len = data->var_len;
	if (data->has_precision && data->precision > 0)
	{
		data->pad_zeros = FALSE;
		new_var_len = data->is_negative || data->show_sign ?
				data->precision + 1 : data->precision;
		if (new_var_len > len)
		{
			data->var_len = new_var_len;
			add_size = data->var_len - len;
			res = extend_str(res, len, add_size);
			res = add_chars_to_str_begin(res, len, data->var_len, '0');
			if (data->show_sign && !data->is_negative &&
				(res[add_size] = '0'))
				res[0] = '+';
			else if (data->is_negative && (res[add_size] = '0'))
				res[0] = '-';
		}
	}
	return (res);
}

char					*handle_string_precision(t_printf *data, char *res)
{
	if (data->has_precision)
		data->var_len = data->precision;
	return (res);
}
