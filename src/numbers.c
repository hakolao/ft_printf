/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:52:00 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/27 13:01:03 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*parse_int(char c, int var)
{
	char	*res;
	int		i;

	res = NULL;
	if (c == 'd' || c == 'i')
		res = ft_itoa(var);
	else if (c == 'u')
		res = ft_itoa((unsigned int)var);
	else if (c == 'o')
		res = ft_itoa_base((unsigned int)var, 8);
	else if (c == 'x' || c == 'X')
	{
		res = ft_itoa_base((unsigned int)var, 16);
		if (c == 'X')
		{
			i = -1;
			while (res[++i])
				res[i] = ft_toupper(res[i]);
		}
	}
	return (res);
}
