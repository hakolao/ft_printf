/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_specifiers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:26:32 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/27 20:21:22 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			parse_sub_specifiers(t_printf *data)
{
	int		i;

	if (data->spec[data->spec_len - 2] == '*')
		data->use_prev_var = TRUE;
	i = 0;
	while (i < data->spec_len - 1)
	{
		i++;
	}
	return (TRUE);
}
