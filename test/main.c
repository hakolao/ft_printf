/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:25:39 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/12 13:28:04 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{

printf("Mine:\n");
ft_printf("'%Z'\n");
printf("Printf:\n");
printf("'%Z'\n");

printf("Mine:\n");
ft_printf("'% hZ'\n");
printf("Printf:\n");
printf("'% hZ'\n");

// printf("Mine:\n");
// ft_printf("'% hZ%'\n");
// printf("Printf:\n");
// printf("'% hZ%'\n");

// printf("Mine:\n");
// ft_printf("'% Z'\n", "test");
// printf("Printf:\n");
// printf("'% Z'\n", "test");

// printf("Mine:\n");
// ft_printf("'% Z '\n", "test");
// printf("Printf:\n");
// printf("'% Z '\n", "test");

// printf("Mine:\n");
// ft_printf("'% Z%s'\n", "test");
// printf("Printf:\n");
// printf("'% Z%s'\n", "test");

// printf("Mine:\n");
// ft_printf("'%jx'\n", -4294967296);
// printf("Printf:\n");
// printf("'%jx'\n", -4294967296);

// printf("Mine:\n");
// ft_printf("'%jx'\n", -4294967297);
// printf("Printf:\n");
// printf("'%jx'\n", -4294967297);

// printf("Mine:\n");
// ft_printf("'%ll#x'\n", 9223372036854775807);
// printf("Printf:\n");
// printf("'%ll#x'\n", 9223372036854775807);

// printf("Mine:\n");
// ft_printf("'% Z'\n", 42);
// printf("Printf:\n");
// printf("'% Z'\n", 42);

// printf("Mine:\n");
// ft_printf("'%5+d'\n", 42);
// printf("Printf:\n");
// printf("'%5+d'\n", 42);

// printf("Mine:\n");
// ft_printf("'%5+d'\n", -42);
// printf("Printf:\n");
// printf("'%5+d'\n", -42);

// printf("Mine:\n");
// ft_printf("'%-5+d'\n", 42);
// printf("Printf:\n");
// printf("'%-5+d'\n", 42);

// printf("Mine:\n");
// ft_printf("'%-5+d'\n", -42);
// printf("Printf:\n");
// printf("'%-5+d'\n", -42);

// printf("Mine:\n");
// ft_printf("'%ju'\n", 4999999999);
// printf("Printf:\n");
// printf("'%ju'\n", 4999999999);

// printf("Mine:\n");
// ft_printf("'%ju'\n", 4294967296);
// printf("Printf:\n");
// printf("'%ju'\n", 4294967296);

// printf("Mine:\n");
// ft_printf("'%U'\n", 4294967295);
// printf("Printf:\n");
// printf("'%U'\n", 4294967295);

// printf("Mine:\n");
// ft_printf("'%hU'\n", 4294967296);
// printf("Printf:\n");
// printf("'%hU'\n", 4294967296);

// printf("Mine:\n");
// ft_printf("'%U'\n", 4294967296);
// printf("Printf:\n");
// printf("'%U'\n", 4294967296);

// printf("Mine:\n");
// ft_printf("'%hhld'\n", 128);
// printf("Printf:\n");
// printf("'%hhld'\n", 128);

// printf("Mine:\n");
// ft_printf("'@main_ftprintf: %####0000 33..1..#00d\\n'\n", 256);
// printf("Printf:\n");
// printf("'@main_ftprintf: %####0000 33..1..#00d\\n'\n", 256);

// printf("Mine:\n");
// ft_printf("'@main_ftprintf: %####0000 33..1d'\n", 256);
// printf("Printf:\n");
// printf("'@main_ftprintf: %####0000 33..1d'\n", 256);

// printf("Mine:\n");
// ft_printf("'@main_ftprintf: %###-#0000 33...12..#0+0d'\n", 256);
// printf("Printf:\n");
// printf("'@main_ftprintf: %###-#0000 33...12..#0+0d'\n", 256);
	return (0);
}
