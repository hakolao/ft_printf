/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:26:26 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/28 16:40:30 by ohakola          ###   ########.fr       */
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
