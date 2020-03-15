/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:05:04 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/15 13:32:12 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int						reset_var_data(t_printf *data)
{
	data->left_justify = FALSE;
	data->pad_zeros = FALSE;
	data->show_sign = FALSE;
	data->blank_space = FALSE;
	data->has_precision = FALSE;
	data->zerox = FALSE;
	data->width = 0;
	data->precision = 6;
	data->middle_len = 0;
	data->spec_len = 0;
	data->var_len = 0;
	data->type = length_none;
	data->is_negative = FALSE;
	data->is_zero_res = FALSE;
	return (TRUE);
}

static void						set_spec_len(t_fmt_specs *lengths,
								char *fmt, int i)
{
	while (fmt[i] && is_sub_specifier(fmt[i]))
	{
		lengths->spec_len++;
		i++;
	}
	if (fmt[i])
		lengths->spec_len++;
	else
		lengths->spec_len = 0;
}

static t_fmt_specs				fmt_part_lengths(char *fmt, t_fmt_specs lengths)
{
	int					i;
	char				*next;

	i = 0;
	next = ft_strchr(fmt, '%');
	if (!next)
	{
		i = -1;
		while (fmt[++i])
			lengths.middle_len++;
		return (lengths);
	}
	if (fmt && next && next - fmt > 0)
	{
		i = next - fmt;
		lengths.middle_len = next - fmt;
	}
	i++;
	set_spec_len(&lengths, fmt, i);
	return (lengths);
}

static char						*parse_middle(t_printf *data, char *fmt)
{
	int		i;

	data->buffer = extend_str(data->buffer, data->len, data->middle_len);
	i = -1;
	while (++i < data->middle_len)
		data->buffer[data->len + i] = fmt[i];
	data->len += data->middle_len;
	data->buffer[data->len] = '\0';
	return (data->buffer);
}

int								parse_input(t_printf *data, char *fmt)
{
	t_fmt_specs	l;

	reset_var_data(data);
	l = fmt_part_lengths(fmt, (t_fmt_specs){0, 0});
	data->middle_len = l.middle_len;
	data->spec_len = l.spec_len;
	if (l.middle_len > 0)
		data->buffer = parse_middle(data, fmt);
	if (l.spec_len > 0 &&
		parse_spec_variable_pair(data, fmt + l.middle_len + 1))
		fmt += l.middle_len + 1 + l.spec_len;
	else if (l.middle_len > 0)
		fmt += l.middle_len;
	else if (*fmt == '%')
		fmt += 1;
	return (*fmt && (l.spec_len > 0 || l.middle_len > 0) ?
			parse_input(data, fmt) : TRUE);
}
