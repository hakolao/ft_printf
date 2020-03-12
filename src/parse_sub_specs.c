/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sub_specs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:26:32 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/12 18:49:45 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			parse_flags(t_printf *data, int *i)
{
	int	j;

	while (data->spec[*i] && is_flag(data->spec[*i]))
	{
		if (data->spec[*i] == '-')
			data->left_justify = TRUE;
		else if (data->spec[*i] == '+')
			data->show_sign = TRUE;
		else if (data->spec[*i] == ' ')
			data->blank_space = TRUE;
		else if (data->spec[*i] == '0' && !data->left_justify)
			data->pad_zeros = TRUE;
		else if (data->spec[*i] == '#')
			data->zerox = TRUE;
		(*i)++;
	}
	j = *i;
	while (data->spec[j] && is_sub_specifier(data->spec[j]))
	{
		if (data->spec[j] == '+')
			data->show_sign = TRUE;
		j++;
	}
	return (TRUE);
}

int			parse_width(t_printf *data, int *i)
{
	int			j;
	unsigned	var;

	j = *i;
	if (*i == data->spec_len - 2 && data->spec[data->spec_len - 2] == '*')
	{
		var = va_arg(data->variables, unsigned);
		data->width = (int)var;
		return (TRUE);
	}
	else if (!ft_isdigit(data->spec[*i]))
		return (FALSE);
	while (j < data->spec_len - 1)
	{
		if (data->spec[j] == '.' ||
			!ft_isdigit(data->spec[j]))
			break ;
		j++;
	}
	data->width = ft_atoi(data->spec + *i);
	(*i) = j;
	return (TRUE);
}

int			parse_precision(t_printf *data, int *i)
{
	int			j;
	unsigned	var;

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
	(*i) = j;
	return (TRUE);
}

int			parse_lengths(t_printf *data, int *i)
{
	char	c;

	c = data->spec[*i];
	while (c && (c == 'h' || c == 'l' || c == 'j' || c == 'z' ||
			c == 't' || c == 'L'))
	{
		c = data->spec[*i];
		if (*i - 1 >= 0 && c == 'h' && data->spec[*i - 1] == 'h')
			data->type = data->type > length_hh && data->type != length_h ?
				data->type : length_hh;
		else if (c == 'h')
			data->type = data->type > length_h ? data->type : length_h;
		else if (*i - 1 >= 0 && c == 'l' && data->spec[*i - 1] == 'l')
			data->type = data->type > length_ll && data->type != length_l ?
				data->type : length_ll;
		else if (c == 'l')
			data->type = data->type > length_l ? data->type : length_l;
		else if (c == 'j')
			data->type = data->type > length_j ? data->type : length_j;
		else if (c == 'z')
			data->type = data->type > length_z ? data->type : length_z;
		else if (c == 't')
			data->type = data->type > length_t ? data->type : length_t;
		else if (c == 'L')
			data->type = data->type > length_L ? data->type : length_L;
		(*i)++;
	}
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
	if (data->width > data->precision &&
		is_int_specifier(data->spec[data->spec_len - 1]))
		data->blank_space = FALSE;
	return (TRUE);
}
