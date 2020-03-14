/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sub_specs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:26:32 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/14 16:49:13 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		parse_flags(t_printf *data)
{
	int		i;
	int		found_zero;

	i = 0;
	found_zero = 0;
	while (data->spec[i] && is_sub_specifier(data->spec[i]))
	{
		if (data->spec[i] == '-')
			data->left_justify = TRUE;
		else if (data->spec[i] == '+')
			data->show_sign = TRUE;
		else if (data->spec[i] == ' ')
			data->blank_space = TRUE;
		else if (data->spec[i] == '0' &&
			!found_zero && (data->pad_zeros = TRUE))
		{
			found_zero = TRUE;
			if (data->spec[i + 1] == '0' && !(data->pad_zeros = FALSE))
				found_zero = FALSE;
			else if (i - 1 > 0 && data->spec[i - 1] == '.' &&
				!(data->pad_zeros = FALSE))
				found_zero = FALSE;
			while (ft_isdigit(data->spec[i]))
				i++;
			i--;
		}
		else if (ft_isdigit(data->spec[i]))
		{
			while (ft_isdigit(data->spec[i]))
				i++;
			i--;
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
	}
	else if (*(dot + 1) == '*')
	{
		var = va_arg(data->variables, unsigned);
		data->precision = (int)var;
	}
	return (TRUE);
}

static int		parse_width(t_printf *data, int	start)
{
	int			i;
	int			has_width;
	int			var;

	i = start;
	has_width = FALSE;
	while (i >= 0 && is_sub_specifier(data->spec[i]))
	{
		if (ft_isdigit(data->spec[i]) && !has_width)
		{
			while (i >= 0 && ft_isdigit(data->spec[i]))
				i--;
			data->width = ft_atoi(data->spec + i + 1);
			has_width = TRUE;
		}
		if (data->spec[i] == '*')
		{
			var = va_arg(data->variables, int);
			if (var < 0)
				data->left_justify = TRUE;
			data->width = !has_width ? ABS(var) : data->width;
		}
		i--;
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
	char		*dot;
	int			diff;

	parse_flags(data);
	dot = ft_strchr(data->spec, '.');
	diff = dot - data->spec;
	if (dot)
	{
		parse_width(data, diff - 1);
		parse_precision(data, dot);
	}
	else
		parse_width(data, data->spec_len - 2);
	parse_lengths(data);
	return (TRUE);
}
