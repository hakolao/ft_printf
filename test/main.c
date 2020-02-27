/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:25:39 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/27 13:50:52 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int		okko;
	char	*pokko;
	char	*format_int;
	char	*format_char;

	okko = 55;
	pokko = "lol";
	format_int = "Hello numbebr %d, are you bigger than %u, or perhaps %o?\n"
			"Or should I call you missing? %x with actually missing::: %X, %d, %d, %d, %d?\n";
	ft_putstr("TEST1:---------->\n");
	ft_putendl("Format_int:");
	ft_putendl(format_int);
	ft_putendl("");
	ft_printf(format_int, -1, -15, -32, -14);
	ft_putstr("PRINTF:---------->\n");
	printf(format_int, -1, -15, -32, -14);

	format_char = "Hello there %s,  would you like to add a %c?\n";
	ft_putstr("TEST2:---------->\n");
	ft_putendl("Format_chars:");
	ft_putendl(format_char);
	ft_putendl("");
	ft_printf(format_char, "okko", 'h');
	ft_putstr("PRINTF:---------->\n");
	printf(format_char, "okko", 'h');
	return (0);
}
