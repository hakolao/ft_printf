/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sub_specs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:26:32 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/12 21:28:33 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		parse_flags(t_printf *data)
{
	int		i;

	i = 0;
	while (data->spec[i] && is_sub_specifier(data->spec[i]))
	{
		if (data->spec[i] == '-')
			data->left_justify = TRUE;
		else if (data->spec[i] == '+')
			data->show_sign = TRUE;
		else if (data->spec[i] == ' ' && (data->blank_space = TRUE))
			data->pad_zeros = FALSE;
		else if (ft_isdigit(data->spec[i]) && data->spec[i] != '0')
		{
			while (ft_isdigit(data->spec[i]))
				i++;
			i--;
		}
		else if (data->spec[i] == '0' && !data->left_justify &&
			!data->blank_space && (data->pad_zeros = TRUE))
		{
			if (i > 0 && data->spec[i - 1] == '.')
				data->pad_zeros = FALSE;
		}
		else if (data->spec[i] == '#')
			data->zerox = TRUE;
		i++;
	}
	return (TRUE);
}

static int		parse_precision(t_printf *data, char *dot)
{
	unsigned	var;

	data->has_precision = TRUE;
	data->precision = 0;
	if (ft_isdigit(*(dot + 1)))
	{
		data->precision = ft_atoi(dot + 1);
		return (TRUE);
	}
	else if (*(dot + 1) == '*')
	{
		var = va_arg(data->variables, unsigned);
		data->precision = (int)var;
		return (TRUE);
	}
	return (TRUE);
}

static int		parse_width_and_precision(t_printf *data)
{
	int			i;
	char		*dot;
	int			diff;
	unsigned	var;

	i = 0;
	dot = ft_strchr(data->spec, '.');
	diff = dot - data->spec;
	if (dot)
	{
		if (diff > 0 && ft_isdigit(data->spec[diff - 1]))
		{
			i = diff;
			while (i > 0 && ft_isdigit(data->spec[i - 1]))
				i--;
			data->width = ft_atoi(data->spec + i);
			return (parse_precision(data, dot));
		}
		else if (diff > 0 && data->spec[diff - 1] == '*')
		{
			var = va_arg(data->variables, unsigned);
			data->width = (int)var;
			return (parse_precision(data, dot));
		}
		else
			return (parse_precision(data, dot));
	}
	while (data->spec[i] && is_sub_specifier(data->spec[i]))
	{
		if (ft_isdigit(data->spec[i]) && data->spec[i] != '0')
		{
			data->width = ft_atoi(data->spec + i);
			return (TRUE);
		}
		i++;
	}
	return (TRUE);
}

int			parse_lengths(t_printf *data)
{
	int			i;
	char		s;

	i = 0;
	s = data->spec[i];
	while (s && is_sub_specifier(s))
	{
		s = data->spec[i];
		if (i - 1 >= 0 && s == 'h' && data->spec[i - 1] == 'h')
			data->type = data->type > length_hh && data->type != length_h ?
				data->type : length_hh;
		else if (s == 'h')
			data->type = data->type > length_h ? data->type : length_h;
		else if (i - 1 >= 0 && s == 'l' && data->spec[i - 1] == 'l')
			data->type = data->type > length_ll && data->type != length_l ?
				data->type : length_ll;
		else if (s == 'l')
			data->type = data->type > length_l ? data->type : length_l;
		else if (s == 'j')
			data->type = data->type > length_j ? data->type : length_j;
		else if (s == 'z')
			data->type = data->type > length_z ? data->type : length_z;
		else if (s == 't')
			data->type = data->type > length_t ? data->type : length_t;
		else if (s == 'L')
			data->type = data->type > length_L ? data->type : length_L;
		i++;
	}
	return (TRUE);
}

int			parse_sub_specifiers(t_printf *data)
{
	int		i;

	i = 0;
	parse_flags(data);
	parse_width_and_precision(data);
	parse_lengths(data);
	if (data->width > data->precision && is_int_specifier(data->c))
		data->blank_space = FALSE;
	return (TRUE);
}
