/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:25:39 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/06 10:43:08 by ohakola          ###   ########.fr       */
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
	return (0);
}
