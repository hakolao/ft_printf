/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:25:39 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/10 15:55:43 by ohakola          ###   ########.fr       */
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
	return (0);
}
