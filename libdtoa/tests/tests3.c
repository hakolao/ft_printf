/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 17:30:47 by ohakola           #+#    #+#             */
/*   Updated: 2020/08/26 23:48:15 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "oh_test.h"
#include "ft_dtoa.h"

const char	*test_big_int_shift(void)
{
	t_big_int	big1;

	big1.length = 2;
	big1.blocks[0] = 245667;
	big1.blocks[1] = 12424;
	big_int_shift_left(54, &big1);
	OH_ASSERT("big int shift fail1",
		big_int_cmp(&big1,
			&(t_big_int){4, {0, 3904897024, 570425583, 12}}) == 0);
	big1.length = 2;
	big1.blocks[0] = 245667;
	big1.blocks[1] = 12424;
	big_int_shift_left(128, &big1);
	OH_ASSERT("big int shift fail1",
		big_int_cmp(&big1,
			&(t_big_int){6, {0, 0, 0, 0, 245667, 12424}}) == 0);
	return (0);
}

const char	*test_new_ceil_and_floor(void)
{
	double	d1;

	d1 = 5.50;
	OH_ASSERT("ceil does not work1", ft_ceil(d1) == 6.0);
	OH_ASSERT("floor does not work2", ft_floor(d1) == 5.0);
	d1 = 5224525.2212421;
	OH_ASSERT("ceil does not work3", ft_ceil(d1) == 5224526.00);
	OH_ASSERT("floor does not work4", ft_floor(d1) == 5224525.00);
	d1 = -5.50;
	OH_ASSERT("ceil does not work5", ft_ceil(d1) == -5.00);
	OH_ASSERT("floor does not work6", ft_floor(d1) == -6.00);
	d1 = -5122515.2212421;
	OH_ASSERT("ceil does not work7", ft_ceil(d1) == -5122515.00);
	OH_ASSERT("floor does not work8", ft_ceil(d1) == -5122515.00);
	return (0);
}

const char	*test_dtoa_normal(void)
{
	double	d1;
	char	*res;

	d1 = 8.12345676;
	res = ft_dtoa((t_dtoa_params){.format = FORMAT_NORM,
		.precision = 5, .value = d1});
	OH_ASSERT("dtoa wrong 1", ft_strequ(res, "8.12346"));
	ft_strdel(&res);
	d1 = -8.12345676;
	res = ft_dtoa((t_dtoa_params){.format = FORMAT_NORM,
		.precision = 15, .value = d1});
	OH_ASSERT("dtoa wrong 2", ft_strequ(res, "-8.123456760000000"));
	ft_strdel(&res);
	d1 = -0.0;
	res = ft_dtoa((t_dtoa_params){.format = FORMAT_NORM,
		.precision = 15, .value = d1});
	OH_ASSERT("dtoa wrong 3", ft_strequ(res, "-0.000000000000000"));
	ft_strdel(&res);
	d1 = -0.0922042000;
	res = ft_dtoa((t_dtoa_params){.format = FORMAT_NORM,
		.precision = 4, .value = d1});
	OH_ASSERT("dtoa wrong 4", ft_strequ(res, "-0.0922"));
	ft_strdel(&res);
	return (0);
}

const char	*test_dtoa_scientific1(void)
{
	double	d1;
	char	*res;

	d1 = 8.12345676;
	res = ft_dtoa((t_dtoa_params){.format = FORMAT_SCI,
		.precision = 5, .value = d1});
	OH_ASSERT("dtoa sci wrong 1", ft_strequ(res, "8.12346e+000"));
	ft_strdel(&res);
	d1 = -8.12345676;
	res = ft_dtoa((t_dtoa_params){.format = FORMAT_SCI,
		.precision = 15, .value = d1});
	OH_ASSERT("dtoa sci wrong 2", ft_strequ(res, "-8.123456760000000e+000"));
	ft_strdel(&res);
	d1 = -0.0;
	res = ft_dtoa((t_dtoa_params){.format = FORMAT_SCI,
		.precision = 15, .value = d1});
	OH_ASSERT("dtoa sci wrong 3", ft_strequ(res, "-0.000000000000000e+000"));
	ft_strdel(&res);
	return (0);
}

const char	*test_dtoa_scientific2(void)
{
	double	d1;
	char	*res;

	d1 = -0.0922042000;
	res = ft_dtoa((t_dtoa_params){.format = FORMAT_SCI,
		.precision = 4, .value = d1});
	OH_ASSERT("dtoa sci wrong 4", ft_strequ(res, "-9.2204e-002"));
	ft_strdel(&res);
	d1 = 922042.282592;
	res = ft_dtoa((t_dtoa_params){.format = FORMAT_SCI,
		.precision = 11, .value = d1});
	OH_ASSERT("dtoa sci wrong 4", ft_strequ(res, "9.22042282592e+005"));
	ft_strdel(&res);
	return (0);
}
