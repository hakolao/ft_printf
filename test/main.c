/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:25:39 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/06 11:50:21 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	ft_printf("%lu\n", -42UL);
	printf("%lu\n", -42UL);

	ft_printf("%+u\n", 4294967295U);
	printf("%+u\n", 4294967295U);

	ft_printf("% u\n", 4294967295);
	printf("% u\n", 4294967295);

	ft_printf("@moulitest: %.d %.0d\n", 42, 43);
	printf("@moulitest: %.d %.0d\n", 42, 43);

	ft_printf("@moulitest: %.10d\n", -42);
	printf("@moulitest: %.10d\n", -42);

	ft_printf("%03.2d\n", -1);
	printf("%03.2d\n", -1);

	ft_printf("%03.2d\n", 1);
	printf("%03.2d\n", 1);

	ft_printf("@moulitest: %5.x %5.0x\n", 0, 0);
	printf("@moulitest: %5.x %5.0x\n", 0, 0);

	ft_printf("%4.15d\n", 42);
	printf("%4.15d\n", 42);

	ft_printf("%hhd\n", -129);
	printf("%hhd\n", -129);

	ft_printf("%hd\n", 32768);
	printf("%hd\n", 32768);

	ft_printf("%hd\n", 32767);
	printf("%hd\n", 32767);

	ft_printf("%0+5d", -42);
	printf("%0+5d", -42);
	return (0);
}
