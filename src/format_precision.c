/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:50:00 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/10 14:17:11 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*handle_int_precision(t_printf *data, char *res)
{
	int		len;

	len = data->var_len;
	
	return (res);
}

char					*handle_string_precision(t_printf *data, char *res)
{
	if (data->has_precision)
		data->var_len = data->precision;
	return (res);
}

char					*handle_char_precision(t_printf *data, char *res)
{
	int		len;

	len = data->var_len;
	
	return (res);
}