/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:25:39 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/13 13:19:03 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	// ft_printf("%' 05i'\n", 43);
	// printf("%' 05i'\n", 43);

	// ft_printf("'@main_ftprintf: %####0000 33..1..#00d\\n'\n", 256);
	// printf("'@main_ftprintf: %####0000 33..1..#00d\\n'\n", 256);

	// ft_printf("'@main_ftprintf: % ####033..1..#00d\\n'\n", 256);
	// printf("'@main_ftprintf: % ####033..1..#00d\\n'\n", 256);

	// ft_printf("'@main_ftprintf: % ####000033..1..#00+d\\n'\n", 256);
	// printf("'@main_ftprintf: % ####000033..1..#00+d\\n'\n", 256);

	// ft_printf("'@main_ftprintf: % 0 000033d\\n'\n", 256);
	// printf("'@main_ftprintf: % 0 000033d\\n'\n", 256);

	// ft_printf("'@main_ftprintf: %0 000033-d\\n'\n", 256);
	// printf("'@main_ftprintf: %0 000033-d\\n'\n", 256);

	ft_printf("'% 10.5d'\n", 4242);
	printf("'% 10.5d'\n", 4242);

	ft_printf("'% d'\n", 42);
	printf("'% d'\n", 42);

	ft_printf("'%010s is a string'\n", "this");
	printf("'%010s is a string'\n", "this");

	ft_printf("'%05c'\n", 42);
	printf("'%05c'\n", 42);
	return (0);
}
