/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_specifiers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:26:32 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/05 13:51:59 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			parse_flags(t_printf *data, int *i)
{
	while (data->spec[*i] && is_flag(data->spec[*i]))
	{
		if (data->spec[*i] == '-')
			data->left_justify = TRUE;
		else if (data->spec[*i] == '+')
			data->show_sign = TRUE;
		else if (data->spec[*i] == ' ' && !data->show_sign && !data->zerox)
			data->blank_space = TRUE;
		else if (data->spec[*i] == '0' && !data->left_justify)
			data->pad_zeros = TRUE;
		else if (data->spec[*i] == '#')
			data->zerox = TRUE;
		(*i)++;
	}
	return (TRUE);
}

int			parse_width(t_printf *data, int *i)
{
	int			j;
	unsigned 	var;

	j = *i;
	if (*i == data->spec_len - 2  && data->spec[data->spec_len - 2] == '*')
	{
		var = va_arg(data->variables, unsigned);
		data->width = (int)var;
		return (TRUE);
	}
	else if (!ft_isdigit(data->spec[*i]))
		return (FALSE);
	while (j < data->spec_len - 1)
	{
		if (data->spec[j] == '.')
			break ;
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

	if (data->spec[*i] != '.')
		return (FALSE);
	data->has_precision = TRUE;
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

int			parse_lengths(t_printf *data, int *i)
{
	if (data->spec[*i] == 'h' && data->spec[*i + 1] == 'h')
	{
		data->length_type = length_hh;
		(*i) += 2;
		return (TRUE);
	}
	if (data->spec[*i] == 'l' && data->spec[*i + 1] == 'l')
	{
		data->length_type = length_ll;
		(*i) += 2;
		return (TRUE);
	}
	if (data->spec[*i] == 'h')
		data->length_type = length_h;
	if (data->spec[*i] == 'l')
		data->length_type = length_l;
	if (data->spec[*i] == 'j')
		data->length_type = length_j;
	if (data->spec[*i] == 'z')
		data->length_type = length_z;
	if (data->spec[*i] == 't')
		data->length_type = length_t;
	if (data->spec[*i] == 'L')
		data->length_type = length_L;
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
	if (i < data->spec_len - 1)
		parse_lengths(data, &i);
	return (TRUE);
}
