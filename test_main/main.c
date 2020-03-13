/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:25:39 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/13 16:41:18 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	ft_printf("'this %#o number'\n", 0);
	printf("'this %#o number'\n", 0);

	ft_printf("'@moulitest: %#.o %#.0o'\n", 0, 0);
	printf("'@moulitest: %#.o %#.0o'\n", 0, 0);

	ft_printf("'@moulitest: %#.o %#.0o'\n", 1, 1);
	printf("'@moulitest: %#.o %#.0o'\n", 1, 1);

	ft_printf("'@moulitest: %#.d %#.0d'\n", 1, 1);
	printf("'@moulitest: %#.d %#.0d'\n", 1, 1);

	ft_printf("'@moulitest: %#.x %#.0x'\n", 0, 0);
	printf("'@moulitest: %#.x %#.0x'\n", 0, 0);

	ft_printf("'@moulitest: %5.o %5.0o'\n", 0, 0);
	printf("'@moulitest: %5.o %5.0o'\n", 0, 0);

	ft_printf("'%#.5o'\n", 21);
	printf("'%#.5o'\n", 21);
	return (0);
}
