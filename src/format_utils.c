/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 17:18:22 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/11 17:21:36 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				swap_zerox(t_printf *data, char *res, int x_index)
{
	if (!(data->zerox && (data->c == 'x' || data->c == 'X')))
		return ;
	res[x_index] = '0';
	res[1] = data->c == 'x' ? 'x' : 'X';
}

void				swap_sign_after_padding(t_printf *data, char *res, int sign_index)
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

void				swap_sign_after_precision(t_printf *data, char *res, int sign_index)
{
	if (!(data->c == 'i' || data->c == 'd'))
		return ;
	if (data->show_sign && !data->is_negative &&
		(res[sign_index] = '0'))
		res[0] = '+';
	else if (data->is_negative && (res[sign_index] = '0'))
		res[0] = '-';
}

char				*handle_blank(t_printf *data, char *res)
{
	res = extend_str(res, data->var_len, 1);
	add_chars_to_str_begin(res, data->var_len, data->var_len + 1, ' ');
	data->var_len += 1;
	return (res);
}