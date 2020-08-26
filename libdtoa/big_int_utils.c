/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_int_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 22:08:52 by ohakola           #+#    #+#             */
/*   Updated: 2020/08/26 20:28:25 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dtoa.h"

void			big_int_retard_print(t_big_int *b)
{
	size_t		i;

	i = -1;
	while (++i < b->length)
	{
		ft_putnbr_unsigned(b->blocks[i]);
		ft_putstr("*(2^32-1)^");
		ft_putnbr_unsigned(i);
		if (i < b->length - 1)
			ft_putstr(" + ");
	}
	ft_putstr("\n");
}

void			big_int_copy(t_big_int *to_copy, t_big_int *res)
{
	size_t		i;
	uint32_t	length;

	length = to_copy->length;
	i = -1;
	while (++i < length)
		res->blocks[i] = to_copy->blocks[i];
	res->length = length;
}

int32_t			big_int_cmp(t_big_int *lhs, t_big_int *rhs)
{
	int32_t		diff;
	int			i;

	diff = lhs->length - rhs->length;
	if (diff != 0)
		return (diff);
	i = lhs->length;
	while (--i >= 0)
	{
		if (lhs->blocks[i] == rhs->blocks[i])
			continue;
		else if (lhs->blocks[i] > rhs->blocks[i])
			return (1);
		else
			return (-1);
	}
	return (0);
}

t_bool			big_int_is_zero(t_big_int *b)
{
	return (b->length == 0);
}
