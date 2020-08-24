/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_int_shift.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 22:17:57 by ohakola           #+#    #+#             */
/*   Updated: 2020/08/24 19:20:55 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dtoa.h"

static void		shift_aligned_left(uint32_t shift_blocks, t_big_int *big)
{
	int32_t		i;

	i = -1;
	while (++i < (int32_t)shift_blocks)
		big->blocks[big->length + i] = big->blocks[i];
	while (--i >= 0)
		big->blocks[i] = 0;
	big->length += shift_blocks;
}

static void		shift_misaligned_left(uint32_t shift_blocks,
				uint32_t shift_bits, t_big_int *big)
{
	int32_t			in_i;
	uint32_t		out_i;
	uint32_t		high_bits;
	uint32_t		low_bits;

	in_i = big->length - 1;
	out_i = big->length + shift_blocks;
	big->length += shift_blocks + 1;
	high_bits = 0;
	low_bits = big->blocks[in_i] >> (32 - shift_bits);
	while (in_i > 0)
	{
		big->blocks[out_i] = high_bits | low_bits;
		high_bits = big->blocks[in_i] << shift_bits;
		in_i--;
		out_i--;
		low_bits = big->blocks[in_i] >> (32 - shift_bits);
	}
	big->blocks[out_i] = high_bits | low_bits;
	big->blocks[out_i - 1] = big->blocks[in_i] << shift_bits;
	out_i = -1;
	while (++out_i < shift_blocks)
		big->blocks[out_i] = 0;
	if (big->blocks[big->length - 1] == 0)
		big->length--;
}

void			big_int_shift_left(uint32_t shift, t_big_int *big)
{
	uint32_t		shift_blocks;
	uint32_t		shift_bits;

	shift_blocks = shift / 32;
	shift_bits = shift % 32;
	if (shift_bits == 0)
		shift_aligned_left(shift_blocks, big);
	else
		shift_misaligned_left(shift_blocks, shift_bits, big);
}
