/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:07:57 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/27 15:49:56 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char					*parse_address(t_printf *data)
{
	char					*hex;
	char					*beg;
	char					*res;

	hex = ft_itoa_uintmax_base(va_arg(data->variables, long long int), 16);
	beg = "0x";
	res = ft_strjoin(beg, hex);
	ft_strdel(&hex);
	return (res);
}
