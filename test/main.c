/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:25:39 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/04 17:57:45 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{

	ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
	// printf("@moulitest: %#.x %#.0x\n", 0, 0);

	ft_printf("@moulitest: %.x %.0x\n", 0, 0);
	// printf("@moulitest: %.x %.0x\n", 0, 0);

	ft_printf("@moulitest: %5.x %5.0x\n", 0, 0);
	// printf("@moulitest: %5.x %5.0x\n", 0, 0);
	return (0);
}
