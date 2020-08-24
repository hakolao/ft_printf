/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_int_pow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 22:14:37 by ohakola           #+#    #+#             */
/*   Updated: 2020/08/24 20:13:41 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dtoa.h"

uint32_t		g_power_of_10_u32[8] = {1, 10, 100, 1000, 10000, 100000,
	1000000, 10000000};

t_big_int		g_power_of_10_big[6] = {(t_big_int){1, {100000000}},
		(t_big_int){2, {0x6fc10000, 0x002386f2}},
		(t_big_int){4, {0x00000000, 0x85acef81, 0x2d6d415b, 0x000004ee}},
		(t_big_int){7, {0x00000000, 0x00000000, 0xbf6a1f01, 0x6e38ed64,
			0xdaa797ed, 0xe93ff9f4, 0x00184f03}},
		(t_big_int){14, {0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x2e953e01, 0x03df9909, 0x0f1538fd, 0x2374e42f, 0xd3cff5ec,
			0xc404dc08, 0xbccdb0da, 0xa6337f19, 0xe91f2603, 0x0000024e}},
		(t_big_int){27, {0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x982e7c01,
			0xbed3875b, 0xd8d99f72, 0x12152f87, 0x6bde50c6, 0xcf4a6e70,
			0xd595d80f, 0x26b2716e, 0xadc666b0, 0x1d153624, 0x3c42d35a,
			0x63ff540e, 0xcc5573c0, 0x65f9ef17, 0x55bc28f2, 0x80dcc7f7,
			0xf46eeddc, 0x5fdcefce, 0x000553f7}}};

void			big_int_pow_10(uint32_t exponent, t_big_int *res)
{
	t_big_int	curr;
	t_big_int	next;
	t_big_int	swap;
	uint32_t	table_index;

	big_int_set_u32(&curr, g_power_of_10_u32[exponent & 0x7]);
	exponent >>= 3;
	table_index = 0;
	while (exponent != 0)
	{
		if (exponent & 1)
		{
			big_int_mul(&curr, &g_power_of_10_big[table_index], &next);
			swap = curr;
			curr = next;
			next = swap;
		}
		table_index++;
		exponent >>= 1;
	}
	*res = curr;
}

void			big_int_mul_pow_10(t_big_int *lhs, uint32_t exponent,
				t_big_int *res)
{
	t_big_int	curr;
	t_big_int	next;
	t_big_int	swap;
	uint32_t	table_index;

	if ((exponent & 0x7) != 0)
		big_int_mul_u32(lhs, g_power_of_10_u32[exponent & 0x7], &curr);
	else
		curr = *lhs;
	exponent >>= 3;
	table_index = 0;
	while (exponent != 0)
	{
		if (exponent & 1)
		{
			big_int_mul(&curr, &g_power_of_10_big[table_index], &next);
			swap = curr;
			curr = next;
			next = swap;
		}
		table_index++;
		exponent >>= 1;
	}
	*res = curr;
}

void			big_int_pow_2(uint32_t exponent, t_big_int *res)
{
	uint32_t	block_i;
	uint32_t	bit_i;
	size_t		i;

	block_i = exponent / 32;
	i = -1;
	while (++i <= block_i)
		res->blocks[i] = 0;
	res->length = block_i + 1;
	bit_i = (exponent % 32);
	res->blocks[block_i] |= (1 << bit_i);
}
