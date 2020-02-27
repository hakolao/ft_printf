/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_specifiers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:26:32 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/27 21:10:31 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			parse_flags(t_printf *data, int *i)
{
	if (!is_allowed_flag(data->spec[*i]))
		return (FALSE);
	if (data->spec[*i] == '-')
		data->left_justify = TRUE;
	else if (data->spec[*i] == '+')
		data->show_sign = TRUE;
	else if (data->spec[*i] == ' ')
		data->blank_space = TRUE;
	else if (data->spec[*i] == '0')
		data->pad_zeros = TRUE;
	(*i)++;
	return (TRUE);
}

int			parse_width(t_printf *data, int *i)
{
	int	j;

	j = *i;
	while (j < data->spec_len - 1 &&
		is_allowed_width_spec(data->spec[j]))
	{
		if (ft_isdigit(data->spec[j]))
			j++;
		else
			break ;
	}
	data->width = ft_atoi(data->spec + *i);
	//ToDo set use_prev_var here? if * or something
	(*i) += j;
	return (TRUE);
}

int			parse_sub_specifiers(t_printf *data)
{
	int		i;

	if (data->spec[data->spec_len - 2] == '*')
		data->use_prev_var = TRUE;
	i = 0;
	while (i < data->spec_len - 1)
	{
		parse_flags(data, &i);
		i++;
	}
	return (TRUE);
}
