/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:26:26 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/06 11:39:20 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*add_to_str(char *str, size_t new_size)
{
	char	*tmp;

	if (!(tmp = ft_strnew(new_size)))
		return (NULL);
	tmp = ft_strcpy(tmp, str);
	ft_strdel(&str);
	str = tmp;
	return (str);
}

char					*add_char_to_beg(char *str, char c, size_t new_size)
{
	str = add_to_str(str, new_size);
	ft_strrev(str);
	str[new_size - 1] = c;
	ft_strrev(str);
	return (str);
}

char					*add_str_to_beg(char *str, char *add)
{
	char					*res;

	res = ft_strjoin(add, str);
	ft_strdel(&str);
	return (res);
}

char					*handle_precision(t_printf *data, char *res, int len)
{
	int		i;
	int		end;
	char	c;

	c = data->spec[data->spec_len - 1];
	if (data->has_precision && is_int_specifier(c))
	{
		i = len;
		res = add_to_str(res, data->width);
		ft_strrev(res);
		end = res[len - 1] == '-' ? data->precision + 1 : data->precision;
		while (i < end)
			res[i++] = '0';
		res[i] = '\0';
		if (res[len - 1] == '-')
		{
			res[len - 1] = '0';
			res[i - 1] = '-';
		}
		ft_strrev(res);
	}
	return (res);
}

char					*handle_padding(t_printf *data, char *res, int len)
{
	int		i;
	int		first_zero;
	int		has_minus;
	int		minus;
	char	c;

	i = len;
	c = data->c;
	if (data->width > 0 && len < data->width)
	{
		res = add_to_str(res, data->width);
		if (!data->left_justify)
		{
			ft_strrev(res);
			while (i < data->width)
				res[i++] = data->pad_zeros ? '0' : ' ';
			ft_strrev(res);
		}
		else
			while (i < data->width)
				res[i++] = data->pad_zeros ? '0' : ' ';
		if (data->pad_zeros && data->zerox && (c == 'x' || c == 'X'))
		{
			i = -1;
			while (++i < data->width)
				if (res[i] == 'x')
					res[i] = '0';
			res[1] = 'x';
		}
	}
	i = data->width;
	first_zero = 0;
	has_minus = FALSE;
	minus = 0;
	while (i > 0)
	{
		if (res[i] == '0')
			first_zero = i;
		else if (res[i] == '-')
		{
			minus = i;
			has_minus = TRUE;
		}
		i--;
	}
	if (has_minus)
	{
		res[first_zero] = '-';
		res[minus] = '0';
	}
	return (res);
}
