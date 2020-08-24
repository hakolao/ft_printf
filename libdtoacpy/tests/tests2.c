/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 17:29:57 by ohakola           #+#    #+#             */
/*   Updated: 2020/08/24 19:36:56 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "oh_test.h"
#include "ft_dtoa.h"

const char	*test_big_int_mul3(void)
{
	t_big_int	big3;
	t_big_int	big4;
	t_big_int	res;

	big3.length = 2;
	big3.blocks[0] = 4294967294U;
	big3.blocks[1] = 1234567033;
	big4.length = 3;
	big4.blocks[0] = 4294967294U;
	big4.blocks[1] = 4294967294U;
	big4.blocks[2] = 4294967294U;
	big_int_mul(&big3, &big4, &res);
	OH_ASSERT("multiply big ints fail6", res.length == 5);
	OH_ASSERT("multiply big ints fail7", res.blocks[0] == 4);
	OH_ASSERT("multiply big ints fail8", res.blocks[1] == 1825833230);
	OH_ASSERT("multiply big ints fail9", res.blocks[2] == 3060400263);
	OH_ASSERT("multiply big ints fail10", res.blocks[3] == 3060400259);
	OH_ASSERT("multiply big ints fail11", res.blocks[4] == 1234567033);
	return (0);
}

const char	*test_big_int_pow10(void)
{
	t_big_int	big1;
	t_big_int	res;

	big1.length = 2;
	big1.blocks[0] = 4294967294U;
	big1.blocks[1] = 1234567033;
	big_int_mul_pow_10(&big1, 5, &res);
	OH_ASSERT("multiply big int with pow 10 fail1",
		big_int_cmp(&res,
			&(t_big_int){3, {4294767296, 2163443775, 28744}}) == 0);
	return (0);
}

const char	*test_big_int_pow2(void)
{
	t_big_int	res;

	big_int_pow_2(156, &res);
	OH_ASSERT("big int pow 2 fail1",
		big_int_cmp(&res,
			&(t_big_int){5, {0, 0, 0, 0, 268435456}}) == 0);
	big_int_pow_2(50, &res);
	OH_ASSERT("big int pow 2 fail2",
		big_int_cmp(&res,
			&(t_big_int){2, {0, 262144}}) == 0);
	return (0);
}

const char	*test_big_int_divide1(void)
{
	t_big_int	big1;
	t_big_int	big2;
	uint32_t	res;

	big1.length = 2;
	big1.blocks[0] = 4294967294U;
	big1.blocks[1] = 1234567033;
	big2.length = 2;
	big2.blocks[0] = 4294967294U;
	big2.blocks[1] = 124424233;
	res = big_int_divide_to_output_digit(&big1, &big2);
	OH_ASSERT("big int div fail1", res == 9);
	return (0);
}

const char	*test_big_int_divide2(void)
{
	t_big_int	big3;
	t_big_int	big4;
	uint32_t	res;

	big3.length = 3;
	big3.blocks[0] = 12344521;
	big3.blocks[1] = 124521;
	big3.blocks[2] = 12442;
	big4.length = 3;
	big4.blocks[0] = 20202222;
	big4.blocks[1] = 22222;
	big4.blocks[2] = 9999;
	res = big_int_divide_to_output_digit(&big3, &big4);
	OH_ASSERT("big int div fail2", res == 1);
	big3.length = 3;
	big3.blocks[0] = 12344521;
	big3.blocks[1] = 124521;
	big3.blocks[2] = 124422424;
	big4.length = 3;
	big4.blocks[0] = 20202222;
	big4.blocks[1] = 22222;
	big4.blocks[2] = 9999;
	res = big_int_divide_to_output_digit(&big3, &big4);
	OH_ASSERT("big int div fail3", (int32_t)res == (int32_t)0xFFFFFFFF);
	return (0);
}
