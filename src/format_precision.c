/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:50:00 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/10 16:17:19 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*handle_int_precision(t_printf *data, char *res)
{
	int		len;

	len = data->var_len;
	if (data->has_precision)
	{
		data->pad_zeros = FALSE;
		data->var_len = data->precision;
		if (data->precision > len)
		{
			res = extend_str(res, len, data->precision - len);
			res = add_chars_to_str_begin(res, len, data->precision, '0');
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
