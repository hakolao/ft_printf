/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:25:39 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/14 16:45:13 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	ft_printf("'{%*3.3d}'\n", 2, 0);
	printf("'{%*3.3d}'\n", 2, 0);

	ft_printf("'{%3.-3d}'\n", 2);
	printf("'{%3.-3d}'\n", 2);

	ft_printf("'{%*33d}'\n", 2, 0);
	printf("'{%*33d}'\n", 2, 0);

	ft_printf("'{%33d}'\n", 2, 0);
	printf("'{%33d}'\n", 2, 0);

	ft_printf("'{%**33d}'\n", 2, 4, 5);
	printf("'{%**33d}'\n", 2, 4, 5);

	ft_printf("'{%*d}'\n", -5, 42);
	printf("'{%*d}'\n", -5, 42);

	ft_printf("'%0+5d'\n", 42);
	printf("'%0+5d'\n", 42);

	ft_printf("'%-10x'\n", 42);
	printf("'%-10x'\n", 42);
	return (0);
}
