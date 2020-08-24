/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 18:59:18 by ohakola           #+#    #+#             */
/*   Updated: 2020/08/24 19:43:23 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "oh_test.h"
#include "ft_dtoa.h"

const char	*test_big_int_cpy(void)
{
	t_big_int	big1;
	t_big_int	big2;
	uint32_t	i;

	big1.length = 10;
	i = -1;
	while (++i < big1.length)
		big1.blocks[i] = i;
	big_int_copy(&big1, &big2);
	OH_ASSERT("size of copied big int is not 10", big2.length == 10);
	i = -1;
	while (++i < big1.length)
		OH_ASSERT("wrongly copied big int!", big2.blocks[i] == big1.blocks[i]);
	return (0);
}

const char	*test_big_int_add1(void)
{
	t_big_int	big1;
	t_big_int	big2;
	t_big_int	res;

	big1.length = 2;
	big1.blocks[0] = 4294967294U;
	big1.blocks[1] = 1234567033;
	big2.length = 2;
	big2.blocks[0] = 4294967294U;
	big2.blocks[1] = 124424233;
	big_int_add(&big1, &big2, &res);
	OH_ASSERT("adding big ints fail1", res.length == 2);
	OH_ASSERT("adding big ints fail2", res.blocks[0] == 4294967292);
	OH_ASSERT("adding big ints fail3", res.blocks[1] == 1358991267);
	return (0);
}

const char	*test_big_int_add2(void)
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
	big_int_add(&big3, &big4, &res);
	OH_ASSERT("adding big ints fail4", res.length == 3);
	OH_ASSERT("adding big ints fail5", res.blocks[0] == 4294967292);
	OH_ASSERT("adding big ints fail6", res.blocks[1] == 1234567032);
	OH_ASSERT("adding big ints fail7", res.blocks[2] == 4294967295);
	return (0);
}

const char	*test_big_int_mul1(void)
{
	t_big_int	big1;
	t_big_int	big2;
	t_big_int	res;

	big1.length = 2;
	big1.blocks[0] = 4294967294U;
	big1.blocks[1] = 1234567033;
	big2.length = 2;
	big2.blocks[0] = 4294967294U;
	big2.blocks[1] = 124424233;
	big_int_mul(&big1, &big2, &res);
	OH_ASSERT("multiply big ints fail1", res.length == 4);
	OH_ASSERT("multiply big ints fail2", res.blocks[0] == 4);
	OH_ASSERT("multiply big ints fail3", res.blocks[1] == 1576984760);
	OH_ASSERT("multiply big ints fail4", res.blocks[2] == 2429848067);
	OH_ASSERT("multiply big ints fail5", res.blocks[3] == 35765128);
	big_int_mul_u32(&big1, 4294967294U, &res);
	OH_ASSERT("multiply big ints fail12", res.length == 3);
	OH_ASSERT("multiply big ints fail13", res.blocks[0] == 4);
	OH_ASSERT("multiply big ints fail14", res.blocks[1] == 1825833226);
	OH_ASSERT("multiply big ints fail15", res.blocks[2] == 1234567033);
	return (0);
}

const char	*test_big_int_mul2(void)
{
	t_big_int	big1;
	t_big_int	big2;
	t_big_int	res;
	t_big_int	res2;

	big1.length = 2;
	big1.blocks[0] = 4294967294U;
	big1.blocks[1] = 1234567033;
	big_int_copy(&big1, &big2);
	big_int_mul_u32(&big1, 2, &res);
	big_int_mul_2(&big2, &res2);
	OH_ASSERT("multiply big ints fail16", big_int_cmp(&res, &res2) == 0);
	big_int_mul_2_modif(&big1);
	OH_ASSERT("multiply big ints fail17", big_int_cmp(&big1, &res) == 0);
	big_int_copy(&big1, &big2);
	big_int_mul_u32(&big1, 10, &res);
	big_int_mul_10_modif(&big2);
	OH_ASSERT("multiply big ints fail18", big_int_cmp(&big2, &res) == 0);
	return (0);
}
