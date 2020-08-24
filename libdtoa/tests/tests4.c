/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 22:13:51 by ohakola           #+#    #+#             */
/*   Updated: 2020/08/24 22:16:00 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "oh_test.h"
#include "ft_dtoa.h"

const char	*just_another_test(void)
{
	double	d1;
	char	*res;

	d1 = 1444565444646.6465424242242;
	res = ft_dtoa((t_dtoa_params){.format = FORMAT_NORM,
		.precision = 6, .value = d1});
	OH_ASSERT("dtoa long number wrong 1",
		ft_strequ(res, "1444565444646.6465424242242"));
	ft_strdel(&res);
	return (0);
}
