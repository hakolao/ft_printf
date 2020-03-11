/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_padding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:50:42 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/11 14:33:50 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				swap_zerox(t_printf *data, char *res, int x_index)
{
	if (!(data->zerox && (data->c == 'x' || data->c == 'X')))
		return ;
	res[x_index] = '0';
	res[1] = data->c == 'x' ? 'x' : 'X';
}

static void				swap_sign(t_printf *data, char *res, int sign_index)
{
	if (!(data->c == 'i' || data->c == 'd'))
		return ;
	if (!(data->has_precision && data->precision > 0))
	{
		if (data->is_negative && (res[sign_index] = '0'))
			res[0] = '-';
		else if (data->show_sign && (res[sign_index] = '0'))
			res[0] = '+';
	}
}

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

	if (data->is_negative || data->show_sign)
		data->blank_space = FALSE;
	if (data->width <= data->var_len)
		return (res);
	len = data->var_len;
	add_size = data->width - len;
	res = extend_str(res, len, add_size);
	data->var_len = data->width;
	if (data->left_justify && data->pad_zeros)
	{
		add_chars_to_str_end(res, len, data->width, '0');
		swap_zerox(data, res, add_size + 1);
		swap_sign(data, res, add_size);
	}
	else if (data->left_justify && !data->pad_zeros)
		add_chars_to_str_end(res, len, data->width, ' ');
	else if (data->pad_zeros)
	{
		add_chars_to_str_begin(res, len, data->width, '0');
		swap_zerox(data, res, add_size + 1);
		swap_sign(data, res, add_size);
	}
	else
		add_chars_to_str_begin(res, len, data->width, ' ');
	return (res);
}

char					*handle_char_padding(t_printf *data, char *res)
{
	return (handle_string_padding(data, res));
}