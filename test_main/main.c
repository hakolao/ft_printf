/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:25:39 by ohakola           #+#    #+#             */
/*   Updated: 2020/08/27 13:18:39 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		run_the_rest(void)
{
	// ft_printf("%hhd\n", 0);
	// ft_printf("%jd\n", 9223372036854775807);
	// ft_printf("%zd\n", 4294967295);
	// ft_printf("%\n");
	// ft_printf("%U\n", 4294967295);
	// ft_printf("%u\n", 4294967295);
	// ft_printf("%o\n", 40);
	// ft_printf("%%#08x\n", 42);
	// ft_printf("%x\n", 1000);
	// ft_printf("%#X\n", 1000);
	// ft_printf("%s\n", NULL);
	// ft_printf("%S\n", L"ݗݜशব");
	// ft_printf("%s%s\n", "test", "test");
	// ft_printf("%s%s%s\n", "test", "test", "test");
	// ft_printf("%C\n", 15000);
	// ft_printf("%b\n", 0);
	// ft_printf("%+016.10b\n", 55);
	// ft_printf("%+016.10b\n", -55);
	// ft_printf("%.*p\n", -3, 0);
	// ft_printf("%f\n", -0.0);
	// ft_printf("%.0f\n", -0.0);
	// ft_printf("%.0f\n", 0.0);
	// ft_printf("%.0f\n", 0.0);
	return (true);
}

#include <stdio.h>

static int		run_first(void)
{
	// ft_printf("\n");
	// ft_printf("%%\n");
	// ft_printf("%d\n", 42);
	// ft_printf("%d%d\n", 42, 41);
	// ft_printf("%d%d%d\n", 42, 43, 44);
	// ft_printf("%ld\n", 2147483647);
	// ft_printf("%lld\n", 9223372036854775807);
	// ft_printf("%x\n", 505);
	// ft_printf("%X\n", 505);
	// ft_printf("%p\n", &ft_printf);
	// ft_printf("%20.15d\n", 54321);
	// ft_printf("%-10d\n", 3);
	// ft_printf("%010d\n", 1);
	// ft_printf("%-20.7Le  %-20.7Le\n", 100.00l, 100000.00l);
	// ft_printf("%.5d Hello jen, '%-25.2e' '%20.26s\n", 25, 0.555, "asdf!");
	// ft_printf("%.5d Hello jen, '%-25.5e' '%20.26s\n", 25, 0.01525, "asdf!");
	// ft_printf("%+042u\n", 56);
	// ft_printf("%+052.42u\n", -56);
	// ft_printf("%+14.2u\n", 56);
	// ft_printf("%+14.3u\n", 56);
	// ft_printf("%0 42u\n", 56);
	// ft_printf("%0 42hhu\n", 5656);
	// ft_printf("%+052.20f\n", 55.0999995);
	// ft_printf("%#42.25f\n", 55.0999995);
	ft_printf("{%f}{%lf}{%Lf}\n",  1444565444646.6465424242242, 1444565444646.6465424242242, 1444565444646.6465424242242l);
	printf("{%f}{%lf}{%Lf}\n",  1444565444646.6465424242242, 1444565444646.6465424242242, 1444565444646.6465424242242l);
	ft_printf("{%f}{%lf}{%Lf}\n", -1444565444646.6465424242242454654, -1444565444646.6465424242242454654, -1444565444646.6465424242242454654l);
	printf("{%f}{%lf}{%Lf}\n", -1444565444646.6465424242242454654, -1444565444646.6465424242242454654, -1444565444646.6465424242242454654l);
	return (true);
}

int				main(void)
{
	int		debug_leaks;

	debug_leaks = false;
	run_first();
	run_the_rest();
	if (debug_leaks)
		while (1)
			;
	return (0);
}
