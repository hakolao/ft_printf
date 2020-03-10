/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_padding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:50:42 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/10 17:03:54 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*handle_float_padding(t_printf *data, char *res)
{
	int		len;
	
	len = data->var_len;
	if (data->width <= data->var_len)
		return (res);
	res = extend_str(res, len, data->width - len);
	data->var_len = data->width;
	if (data->left_justify && !data->pad_zeros)
		add_chars_to_str_end(res, len, data->width, ' ');
	else
		add_chars_to_str_begin(res, len, data->width, ' ');
	return (res);
}

char					*handle_string_padding(t_printf *data, char *res)
{
	int		len;
	
	len = data->var_len;
	if (data->width <= data->var_len)
		return (res);
	res = extend_str(res, len, data->width - len);
	data->var_len = data->width;
	if (data->left_justify && data->pad_zeros)
		add_chars_to_str_end(res, len, data->width, '0');
	else if (data->left_justify && !data->pad_zeros)
		add_chars_to_str_end(res, len, data->width, ' ');
	else if (data->pad_zeros)
		add_chars_to_str_begin(res, len, data->width, '0');
	else
		add_chars_to_str_begin(res, len, data->width, ' ');
	return (res);
}

char					*handle_int_padding(t_printf *data, char *res)
{
	if (data->is_negative || data->show_sign)
		data->blank_space = FALSE;
	return (handle_string_padding(data, res));
}

char					*handle_char_padding(t_printf *data, char *res)
{
	return (handle_string_padding(data, res));
}