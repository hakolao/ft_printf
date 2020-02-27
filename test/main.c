/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:25:39 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/27 20:25:22 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int			okko;
	long long int	lol;
	long long int	lol2;
	int				lol3;
	char		*format;

	okko = 55;
	lol = -25509090909090905;
	lol2 = 30303;
	lol3 = -30303;
	format = "Hello number %ld, are %10d you %010d bigger than %u, or perhaps %#o?\n"
			"Or should I call you? %#x, %X?\n"
			"Address neg: %p, pos: %p, %p, mistake %w\n"
			"what about these? %% %%\n"
			"You'll float too? %4.2f, %+.0f %rtf\n"
			"Chars lol: %s, %c %hhs\n";
	ft_putstr("TEST1:---------->\n");
	ft_putendl("format:");
	ft_putendl(format);
	ft_putendl("");
	ft_printf(format, 650000L, 399, 12345, -15, -32, -14, 120,
	lol, lol2, lol3,
	0.15, -15.0055536, 0.12345,
	"okko", 'c', "lol");
	ft_putstr("PRINTF:---------->\n");
	printf(format, 650000L, 399, 12345, -15, -32, -14, 120,
	lol, lol2, lol3,
	0.15, -15.0055536, 0.12345,
	"okko", 'c', "lol");


	ft_putstr("\nTEST2:--------->\n");
	ft_printf ("Characters: %c %c \n", 'a', 65);
	ft_printf ("Decimals: %d %ld\n", 1977, 650000L);
	ft_printf ("Preceding with blanks: %10d \n", 1977);
	ft_printf ("Preceding with zeros: %010d \n", 1977);
	ft_printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
	ft_printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	ft_printf ("Width trick: %*x \n", 5, 10);
	ft_printf ("%s \n", "A string\n");

	ft_putstr("PRINTF:----------->\n");
	printf ("Characters: %c %c \n", 'a', 65);
	printf ("Decimals: %d %ld\n", 1977, 650000L);
	printf ("Preceding with blanks: %10d \n", 1977);
	printf ("Preceding with zeros: %010d \n", 1977);
	printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
	printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	printf ("Width trick: %*x \n", 5, 10);
	printf ("%s \n", "A string\n");
	return (0);
}
