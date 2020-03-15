/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:25:39 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/15 17:06:11 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int		okko = 25;

	ft_printf("%.5d Hello jen, '%-25.2e' '%20.26s\n", okko, 0.555, "asdf!");
	printf("%.5d Hello jen, '%-25.2e' '%20.26s\n", okko, 0.555, "asdf!");
	ft_printf("%.5d Hello jen, '%-25.5e' '%20.26s\n", okko, 0.01525, "asdf!");
	printf("%.5d Hello jen, '%-25.5e' '%20.26s\n", okko, 0.01525, "asdf!");
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
	ft_printf("%-20.7Le  %-20.7Le\n", 0.004567l, 5.004567l);
	printf("%-20.7Le  %-20.7Le\n", 0.004567l, 5.004567l);
	ft_printf("%-20.7Le  %-20.7Le\n", 100.00l, 100000.00l);
	printf("%-20.7Le  %-20.7Le\n", 100.00l, 100000.00l);
	return (0);
}
