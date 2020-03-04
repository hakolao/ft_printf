/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:07:57 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/04 16:43:09 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*parse_address(t_printf *data)
{
	return (add_str_to_beg(ft_itoa_uintmax_base(va_arg(data->variables,
		long long int), 16), "0x"));
}
