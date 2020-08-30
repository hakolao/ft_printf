/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_int_divide.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 22:18:43 by ohakola           #+#    #+#             */
/*   Updated: 2020/08/30 21:13:55 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dtoa.h"

static void		divide_out(t_big_int *dividend, t_big_int *divisor,
				uint32_t quotient, uint32_t length)
{
	uint64_t	borrow;
	uint64_t	carry;
	uint64_t	product;
	uint32_t	i;
	uint64_t	diff;

	borrow = 0;
	carry = 0;
	i = -1;
	while (++i < length)
	{
		product = (uint64_t)divisor->blocks[i] *
			(uint64_t)quotient + carry;
		carry = product >> 32;
		diff = (uint64_t)dividend->blocks[i] -
			(product & 0xFFFFFFFF) - borrow;
		borrow = (diff >> 32) & 1;
		dividend->blocks[i] = diff & 0xFFFFFFFF;
	}
	while (length > 0 && dividend->blocks[length - 1] == 0)
		length--;
	dividend->length = length;
}

static void		divide_remaining(t_big_int *dividend, t_big_int *divisor,
				uint32_t length)
{
	uint64_t	borrow;
	uint64_t	diff;
	uint32_t	i;

	i = -1;
	borrow = 0;
	while (++i < length)
	{
		diff = (uint64_t)dividend->blocks[i] -
			(uint64_t)divisor->blocks[i] - borrow;
		borrow = (diff >> 32) & 1;
		dividend->blocks[i] = diff & 0xFFFFFFFF;
	}
	while (length > 0 && dividend->blocks[length - 1] == 0)
		length--;
	dividend->length = length;
}

uint32_t		big_int_divide_to_output_digit(t_big_int *dividend,
				t_big_int *divisor)
{
	uint32_t	length;
	uint32_t	quotient;

	if (!big_int_is_zero(divisor) &&
		divisor->blocks[divisor->length - 1] >= 8 &&
		divisor->blocks[divisor->length - 1] < 0xFFFFFFFF &&
		dividend->length <= divisor->length)
	{
		length = divisor->length;
		if (dividend->length < divisor->length)
			return (0);
		quotient = dividend->blocks[length - 1] /
			divisor->blocks[length - 1];
		if (!(quotient <= 9))
			return (0xFFFFFFFF);
		if (quotient != 0)
			divide_out(dividend, divisor, quotient, length);
		if (big_int_cmp(dividend, divisor) >= 0)
		{
			divide_remaining(dividend, divisor, length);
			quotient++;
		}
		return (quotient);
	}
	return (0xFFFFFFFF);
}
