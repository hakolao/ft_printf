/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:25:39 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/14 17:22:28 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	char	*str;
	int		len;

	if (!(str = ft_strnew(50)))
		return (0);
	len = ft_sprintf(str, "%lld", 9223372036854775807);
	ft_printf("stdout: str: %s\n", str);
	ft_printf("stdout: str len: %d\n", len);
	len = ft_dprintf(2, "stderr: %lld\n", 9223372036854775807);
	ft_dprintf(2, "stderr: print len: %d\n", len);
	len = ft_printf("stdout: %lld\n", 9223372036854775807);
	ft_printf("stdout: print len: %d\n", len);
	return (0);
}
