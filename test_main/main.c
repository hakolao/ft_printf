/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:25:39 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/13 15:17:35 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	ft_printf("'%#.3x'\n", 0);
	printf("'%#.3x'\n", 0);

	ft_printf("'%#.5x'\n", 21);
	printf("'%#.5x'\n", 21);

	ft_printf("'%#x'\n", 4294967295u);
	printf("'%#x'\n", 4294967295u);

	ft_printf("'%#03x'\n", 0);
	printf("'%#03x'\n", 0);

	ft_printf("'%#3x'\n", 0);
	printf("'%#3x'\n", 0);

	ft_printf("'%#3x'\n", 1);
	printf("'%#3x'\n", 1);
	return (0);
}
