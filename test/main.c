/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:25:39 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/27 12:39:43 by ohakola          ###   ########.fr       */
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
	format = "Hello numbebr %d, are you bigger than %i, or perhaps %o?\n"
			"Or should I call you missing? %x with actually missing %X?";
	ft_putstr("TEST1:---------->\n");
	ft_putendl("Format1:");
	ft_putendl(format);
	ft_putendl("");
	ft_printf(format, 1, 15, 32, 100);
	return (0);
}
