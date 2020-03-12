/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:25:39 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/12 20:14:18 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	// ft_printf("'%-5+d'\n", -42);
	// printf("'%-5+d'\n", -42);

	// ft_printf("'%-5+d'\n", 42);
	// printf("'%-5+d'\n", 42);

	// ft_printf("'%ll#x'\n", 9223372036854775807);
	// printf("'%ll#x'\n", 9223372036854775807);

	// ft_printf("'%-+10.5d'\n", 4242);
	// printf("'%-+10.5d'\n", 4242);

	// ft_printf("'@moulitest: %5.x %5.0x'\n", 0, 0);
	// printf("'@moulitest: %5.x %5.0x'\n", 0, 0);

	// ft_printf("'@moulitest: %.d %.0d'\n", 0, 0);
	// printf("'@moulitest: %.d %.0d'\n", 0, 0);

	ft_printf("'%0+5d'\n", 42);
	printf("'%0+5d'\n", 42);

	return (0);
}
