/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:25:39 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/15 18:23:47 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		run_the_rest(void)
{
	ft_printf("%hhd\\n", 0);
	ft_printf("%jd\\n", 9223372036854775807);
	ft_printf("%zd\\n", 4294967295);
	ft_printf("%\\n");
	ft_printf("%U\\n", 4294967295);
	ft_printf("%u\\n", 4294967295);
	ft_printf("%o\\n", 40);
	ft_printf("%%#08x\\n", 42);
	ft_printf("%x\\n", 1000);
	ft_printf("%#X\\n", 1000);
	ft_printf("%s\\n", NULL);
	ft_printf("%S\\n", L"ݗݜशব");
	ft_printf("%s%s\\n", "test", "test");
	ft_printf("%s%s%s\\n", "test", "test", "test");
	ft_printf("%C\\n", 15000);
	return (TRUE);
}

int		test_leaks(void)
{
	ft_printf("\\n");
	ft_printf("%%\\n");
	ft_printf("%d\\n", 42);
	ft_printf("%d%d\\n", 42, 41);
	ft_printf("%d%d%d\\n", 42, 43, 44);
	ft_printf("%ld\\n", 2147483647);
	ft_printf("%lld\\n", 9223372036854775807);
	ft_printf("%x\\n", 505);
	ft_printf("%X\\n", 505);
	ft_printf("%p\\n", &ft_printf);
	ft_printf("%20.15d\\n", 54321);
	ft_printf("%-10d\\n", 3);
	ft_printf("% d\\n", 3);
	ft_printf("%+d\\n", 3);
	ft_printf("%010d\\n", 1);
	run_the_rest();
	while (1);
	return (TRUE);
}

int		main(void)
{
	int		lol;
	int		debug_leaks;

	debug_leaks = FALSE;
	lol = 25;
	ft_printf("%.5d Hello jen, '%-25.2e' '%20.26s\n", lol, 0.555, "asdf!");
	printf("%.5d Hello jen, '%-25.2e' '%20.26s\n", lol, 0.555, "asdf!");
	ft_printf("%.5d Hello jen, '%-25.5e' '%20.26s\n", lol, 0.01525, "asdf!");
	printf("%.5d Hello jen, '%-25.5e' '%20.26s\n", lol, 0.01525, "asdf!");
	ft_printf("%-20.7Le  %e\n", 0.0l, 0.0);
	printf("%-20.7Le  %e\n", 0.0l, 0.0);
	ft_printf("%-20.7e\n", 0.004567);
	printf("%-20.7e\n", 0.004567);
	ft_printf("'%5.4Le'\n", 0.0l);
	printf("'%5.4Le'\n", 0.0l);
	ft_printf("%5.7Le\n", 0.004567l);
	printf("%5.7Le\n", 0.004567l);
	ft_printf("%5.7Le\n", 125125.004567l);
	printf("%5.7Le\n", 125125.004567l);
	ft_printf("%-20.7Le  %-20.7Le\n", 0.00000000004567l, 5.004567l);
	printf("%-20.7Le  %-20.7Le\n", 0.00000000004567l, 5.004567l);
	ft_printf("%-20.7Le  %-20.7Le\n", 100.00l, 100000.00l);
	printf("%-20.7Le  %-20.7Le\n", 100.00l, 100000.00l);
	if (debug_leaks)
		test_leaks();
	return (0);
}
