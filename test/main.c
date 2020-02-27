/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:25:39 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/27 19:55:07 by ohakola          ###   ########.fr       */
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


	// int number    =  5;
	// char *pointer = "little";

	// printf("Here is a number-%4d-and a-%10s-word.\n", number, pointer);
	return (0);
}
