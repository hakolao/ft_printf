/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 22:13:51 by ohakola           #+#    #+#             */
/*   Updated: 2020/08/25 00:17:23 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "oh_test.h"
#include "ft_dtoa.h"

const char	*just_another_test(void)
{
	double	d1;
	char	*res;

	d1 = 10.15;
	res = ft_dtoa((t_dtoa_params){.format = FORMAT_NORM,
		.precision = 1, .value = d1});
	OH_ASSERT("dtoa long number wrong 1",
		ft_strequ(res, "10.2"));
	ft_strdel(&res);
	d1 = 1444565444646.6465424242242;
	res = ft_dtoa((t_dtoa_params){.format = FORMAT_NORM,
		.precision = 6, .value = d1});
	OH_ASSERT("dtoa long number wrong 2",
		ft_strequ(res, "1444565444646.646484"));
	ft_strdel(&res);
	return (0);
}
