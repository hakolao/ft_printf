/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_padding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:50:42 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/13 12:05:33 by ohakola          ###   ########.fr       */
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
	int		len;
	int		add_size;

	if (data->width <= data->var_len)
		return (res);
	len = data->var_len;
	add_size = data->width - len;
	res = extend_str(res, len, add_size);
	data->var_len = data->width;
	if (data->left_justify && data->pad_zeros)
		add_chars_to_str_end(res, len, data->width, '0');
	else if (data->left_justify && !data->pad_zeros)
		add_chars_to_str_end(res, len, data->width, ' ');
	else if (data->pad_zeros)
		add_chars_to_str_begin(res, len, data->width, '0');
	else
		add_chars_to_str_begin(res, len, data->width, ' ');
	if (data->pad_zeros)
	{
		swap_zerox(data, res, add_size + 1);
		swap_sign_after_padding(data, res, add_size);
	}
	return (res);
}

char					*handle_char_padding(t_printf *data, char *res)
{
	int		len;

	if (res[0])
		return (handle_string_padding(data, res));
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
		add_chars_to_null_str_begin(res, len, data->width, '0');
	else
		add_chars_to_null_str_begin(res, len, data->width, ' ');
	return (res);
}
