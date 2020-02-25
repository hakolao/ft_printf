/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:25:39 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/25 16:55:15 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	int		okko;
	char	*pokko;
	char	*format;

	okko = 55;
	pokko = "lol";
	format = "Some different %% %w radices: %d %x %o %#x %#o \n";
	ft_putstr("TEST:---------->\n");
	ft_putendl("Format:");
	ft_putendl(format);
	ft_putendl("");
	ft_printf(format, okko);
	return (0);
}