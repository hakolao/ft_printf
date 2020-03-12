/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:27:31 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/12 14:05:31 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				log_err(char *str, char *strerror)
{
	ft_putstr("\033[0;31m");
	ft_putstr_fd(strerror, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(str, 2);
	ft_putstr("\033[0m");
	return (1);
}

int				debug_flags(t_printf *data)
{
	printf("spec len: %d "
			"left_justify: %d\n"
			"pad_zeros: %d "
			"show_sign: %d "
			"blank_space: %d "
			"zerox: %d\n"
			"width: %d "
			"length type: %d "
			"is_negative: %d\n"
			"has_precision: %d\n"
			"precision: %d\n",
			data->spec_len,
			data->left_justify,
			data->pad_zeros,
			data->show_sign,
			data->blank_space,
			data->zerox,
			data->width,
			data->type,
			data->is_negative,
			data->has_precision,
			data->precision);
	return (TRUE);
}
