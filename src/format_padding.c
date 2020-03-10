/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_padding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:50:42 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/10 15:43:41 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*handle_int_padding(t_printf *data, char *res)
{
	int		len;

	len = data->var_len;
	
	return (res);
}

char					*handle_float_padding(t_printf *data, char *res)
{
	int		len;

	len = data->var_len;
	
	return (res);
}

char					*handle_string_padding(t_printf *data, char *res)
{
	int		len;
	int		i;
	
	len = data->var_len;
	i = 0;
	if (data->width <= data->var_len)
		return (res);
	res = extend_str(res, len, data->width - len);
	data->var_len = data->width;
	i = len - 1;
	debug_flags(data);
	if (data->left_justify)
		while (++i < data->width)
			res[i] = data->pad_zeros ? '0' : ' ';
	else
	{
		ft_strrev(res);
		while (++i < data->width)
			res[i] = data->pad_zeros ? '0' : ' ';
		ft_strrev(res);
	}
	return (res);
}

char					*handle_char_padding(t_printf *data, char *res)
{
	int		len;

	len = data->var_len;
	return (res);
}