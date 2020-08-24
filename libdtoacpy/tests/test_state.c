/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 19:58:24 by ohakola           #+#    #+#             */
/*   Updated: 2020/08/24 19:48:15 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "oh_test.h"

t_test_state	test_state_create(t_bool success, const char *result, int id)
{
	t_test_state	state;

	state = (t_test_state){.success = success, .result = result, .id = id};
	return (state);
}

void			update_test_state(const char *(*test)(void))
{
	const char		*message;
	t_test_state	state;

	message = test();
	g_tests_run++;
	state = test_state_create(message ? false : true,
		message, g_tests_run - 1);
	g_test_states[g_tests_run - 1] = state;
	ft_putstr(" test: ");
	ft_putnbr(state.id);
	ft_putstr(" ");
	ft_putstr(state.success ? "Success" : state.result);
	ft_putstr("\n");
}
