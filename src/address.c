/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:07:57 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/28 14:40:09 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*parse_address(t_printf *data)
{
	char					*hex;
	char					*res;

	hex = ft_itoa_uintmax_base(va_arg(data->variables, long long int), 16);
	res = ft_strjoin("0x", hex);
	ft_strdel(&hex);
	return (res);
}
