/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 19:23:49 by ohakola           #+#    #+#             */
/*   Updated: 2020/08/27 15:15:38 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "oh_test.h"
#include "tests.h"

int g_tests_run = 0;
t_test_state g_test_states[MAX_TESTS];

static void			all_tests(void)
{
	OH_RUN_TEST(test_big_int_cpy);
	OH_RUN_TEST(test_big_int_add1);
	OH_RUN_TEST(test_big_int_add2);
	OH_RUN_TEST(test_big_int_mul1);
	OH_RUN_TEST(test_big_int_mul2);
	OH_RUN_TEST(test_big_int_mul3);
	OH_RUN_TEST(test_big_int_pow10);
	OH_RUN_TEST(test_big_int_pow2);
	OH_RUN_TEST(test_big_int_divide1);
	OH_RUN_TEST(test_big_int_divide2);
	OH_RUN_TEST(test_big_int_shift);
	OH_RUN_TEST(test_new_ceil_and_floor);
	OH_RUN_TEST(test_dtoa_normal);
	OH_RUN_TEST(test_dtoa_scientific1);
	OH_RUN_TEST(test_dtoa_scientific2);
	OH_RUN_TEST(just_another_test1);
	OH_RUN_TEST(just_another_test2);
}

static void			print_result(t_bool success, int failures)
{
	ft_putstr("===========\n");
	if (!success)
	{
		ft_putnbr(failures);
		ft_putstr(" out of ");
		ft_putnbr(g_tests_run);
		ft_putstr(" TESTS FAILED\n");
	}
	else
	{
		ft_putstr("ALL ");
		ft_putnbr(g_tests_run);
		ft_putstr(" TESTS_PASSED\n");
	}
}

int					main(void)
{
	t_bool				success;
	int					failures;
	int					i;

	all_tests();
	success = true;
	failures = 0;
	i = -1;
	while (++i < g_tests_run)
	{
		if (!g_test_states[i].success)
		{
			success = false;
			failures++;
		}
	}
	print_result(success, failures);
	return (!success);
}
