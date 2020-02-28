/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:25:39 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/28 16:15:18 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int test;

	test = 44;
	ft_putstr("\nTEST2:--------->\n");
	ft_printf ("Characters: %c %c \n", 'a', 65);
	ft_printf ("Decimals: %-+50d %ld\n", 1977, 650000L);
	ft_printf ("Decimals: %+50d %ld\n", 1977, 650000L);
	ft_printf ("Preceding with blanks: %10d \n", 24242);
	ft_printf ("Preceding with zeros: %010d \n", 1111);
	ft_printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
	ft_printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	ft_printf ("Width trick: %*x \n", 5, 10);
	ft_printf ("address: %p \n", &test);
	ft_printf ("%s \n", "A string\n");

	ft_putstr("PRINTF:----------->\n");
	// printf ("Characters: %c %c \n", 'a', 65);
	printf ("Decimals: %-+50d %ld\n", 1977, 650000L);
	printf ("Decimals: %+50d %ld\n", 1977, 650000L);
	printf ("Preceding with blanks: %10d \n", 24242);
	printf ("Preceding with zeros: %010d \n", 1111);
	printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
	printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	printf ("Width trick: %*x \n", 5, 10);
	printf ("address: %p \n", &test);
	printf ("%s \n", "A string\n");
	return (0);
}
