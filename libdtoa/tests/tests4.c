/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 22:13:51 by ohakola           #+#    #+#             */
/*   Updated: 2021/05/05 12:30:16 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "oh_test.h"
#include "ft_dtoa.h"

const char	*just_another_test1(void)
{
	double	d1;
	char	*res;

	d1 = 10.15;
	res = ft_dtoa((t_dtoa_params){.format = FORMAT_NORM,
		.precision = 1, .value = d1});
	OH_ASSERT("dtoa long number wrong 1",
		ft_strequ(res, "10.2"));
	ft_strdel(&res);
	d1 = -0.999999;
	res = ft_dtoa((t_dtoa_params){.format = FORMAT_NORM,
		.precision = -1, .value = d1});
	OH_ASSERT("dtoa long number wrong 333",
		ft_strequ(res, "-0.999999"));
	ft_strdel(&res);
	d1 = -0.999999;
	res = ft_dtoa((t_dtoa_params){.format = FORMAT_NORM,
		.precision = 6, .value = d1});
	OH_ASSERT("dtoa long number wrong 444",
		ft_strequ(res, "-0.999999"));
	ft_strdel(&res);
	return (0);
}

const char	*just_another_test2(void)
{
	double		d1;
	long double	d2;
	char		*res;

	d1 = 0;
	*((unsigned long *)(&d1)) = 0x7FF0000000000000;
	res = ft_dtoa((t_dtoa_params){.format = FORMAT_NORM,
		.precision = 6, .value = d1});
	OH_ASSERT("dtoa inf wrong 54",
		ft_strequ(res, "inf"));
	ft_strdel(&res);
	d1 = (double)INT32_MIN;
	res = ft_dtoa((t_dtoa_params){.format = FORMAT_NORM,
		.precision = 6, .value = d1});
	OH_ASSERT("dtoa int min wrong 444",
		ft_strequ(res, "-2147483648.000000"));
	ft_strdel(&res);
	d2 = 1444565444646.6465424242242L;
	res = ft_dtoa_ld((t_dtoa_params){.format = FORMAT_NORM,
		.precision = 6, .value_ld = d2});
	OH_ASSERT("dtoa long number wrong 2",
		ft_strequ(res, "1444565444646.646542"));
	ft_strdel(&res);
	return (0);
}
