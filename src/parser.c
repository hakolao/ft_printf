/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:05:04 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/06 16:29:22 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						reset_var_data(t_printf *data)
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
	data->length_type = length_none;
	return (TRUE);
}

static char				*parse_middle(t_printf *data, char *fmt)
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

int						parse_input(t_printf *data, char *fmt)
{
	t_printf_lengths	l;

	reset_var_data(data);
	l = fmt_part_lengths(fmt, (t_printf_lengths){0, 0});
	data->middle_len = l.middle_len;
	data->spec_len = l.spec_len;
	if (l.middle_len > 0 &&
		!(data->buffer = parse_middle(data, fmt)))
		return (FALSE);
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
