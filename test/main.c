/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:25:39 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/11 13:44:33 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{

	ft_printf("%5.2s is a string\n", "this");
	printf("%5.2s is a string\n", "this");

	ft_printf("'%-08.2f'\n", 10.3456);
	printf("'%-08.2f'\n", 10.3456);

	ft_printf("'%8.4f'\n", 10.3456);
	printf("'%8.4f'\n", 10.3456);

	ft_printf("'%08.4d'\n", 10);
	printf("'%08.4d'\n", 10);

	ft_printf("'%018o'\n", 10);
	printf("'%018o'\n", 10);

	ft_printf("'%#08.4x'\n", 10);
	printf("'%#08.4x'\n", 10);

	ft_printf("'%03.2d'\n", -1);
	printf("'%03.2d'\n", -1);

	ft_printf("'%+03.2d'\n", 1);
	printf("'%+03.2d'\n", 1);

	ft_printf("'@moulitest: %.10d'\n", -42);
	printf("'@moulitest: %.10d'\n", -42);

	ft_printf("'@moulitest: %.d %.0d'\n", 42, 43);
	printf("'@moulitest: %.d %.0d'\n", 42, 43);

	ft_printf("'%.2x'\n", 5427);
	printf("'%.2x'\n", 5427);

	ft_printf("'%#015x'\n", 42);
	printf("'%#015x'\n", 42);
	return (0);
}
