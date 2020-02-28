/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_specifiers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:26:32 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/28 14:31:48 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			parse_flags(t_printf *data, int *i)
{
	printf("parsing flags: %s\n", data->spec + *i);
	while (data->spec[*i] && is_allowed_flag(data->spec[*i]))
	{
		if (data->spec[*i] == '-')
			data->left_justify = TRUE;
		else if (data->spec[*i] == '+')
			data->show_sign = TRUE;
		else if (data->spec[*i] == ' ')
			data->blank_space = TRUE;
		else if (data->spec[*i] == '0')
			data->pad_zeros = TRUE;
		(*i)++;
	}
	return (TRUE);
}

int			parse_width(t_printf *data, int *i)
{
	int			j;
	unsigned 	var;

	j = *i;
	printf("parsing width: %s\n", data->spec + *i);
	if (*i == data->spec_len - 2  && data->spec[data->spec_len - 2] == '*')
	{
		var = va_arg(data->variables, unsigned);
		data->width = (int)var;
		return (TRUE);
	}
	while (j < data->spec_len - 1)
	{
		if (!ft_isdigit(data->spec[j]))
			return (FALSE);
		j++;
	}
	data->width = ft_atoi(data->spec + *i);
	(*i) += j;
	return (TRUE);
}

int			parse_precision(t_printf *data, int *i)
{
	int			j;
	unsigned 	var;

	printf("parsing precision: %s\n", data->spec + *i);
	if (data->spec[*i] != '.')
		return (FALSE);
	(*i)++;
	if (*i == data->spec_len - 2 && data->spec[*i] == '*')
	{
		var = va_arg(data->variables, unsigned);
		data->precision = (int)var;
		(*i)++;
		return (TRUE);
	}
	j = *i;
	while (j < data->spec_len - 1)
	{
		if (!ft_isdigit(data->spec[j]))
			return (FALSE);
		j++;
	}
	data->precision = ft_atoi(data->spec + *i);
	(*i) += j;
	return (TRUE);
}

int			parse_sub_specifiers(t_printf *data)
{
	int		i;

	i = 0;
	if (i < data->spec_len - 1)
		parse_flags(data, &i);
	if (i < data->spec_len - 1)
		parse_width(data, &i);
	if (i < data->spec_len - 1)
		parse_precision(data, &i);
	printf("SPEC: %s\n", data->spec);
	debug_flags(data);
	return (TRUE);
}