/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:25:39 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/26 15:26:12 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	int		okko;
	char	*pokko;
	char	*format;
	char	*format2;

	okko = 55;
	pokko = "lol";
	format = "Some diffe %+-05hhd rent %% %w radices: %d %x %o %#x %#o \n";
	format2 = "%% %w radices: %d %x %o %#x %#o \n";
	ft_putstr("TEST:---------->\n");
	ft_putendl("Format1:");
	ft_putendl(format);
	ft_putendl("");
	ft_printf(format, okko);
	ft_putendl("\n\nFormat2:");
	ft_putendl(format2);
	ft_putendl("");
	ft_printf(format2, okko, pokko);
	return (0);
}