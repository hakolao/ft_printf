/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 19:25:49 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/14 23:41:39 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** https://www.codeproject.com/Tips/311714/Natural-Logarithms-and-Exponent
*/

long double		ft_ln(long double nb)
{
	long double	n;
	long double	p;
	long double	l;
	long double	r;
	long double	a;
	long double	count;

	p = nb;
	n = 0.0;
	while(p >= FT_MATH_E)
	{
		p /= FT_MATH_E;
		n++;
	}
	n += (p / FT_MATH_E);
	p = nb;
	count = 0;
	do
	{
		a = n;
		l = (p / (ft_exp(n - 1.0)));
		r = ((n - 1.0) * FT_MATH_E);
		n = ((l + r) / FT_MATH_E);
		count++;
	} while ((n != a && count < 30));
	return (n);
}

long double		ft_log10(long double nb)
{
	return ft_ln(nb) / LN10;
}

long double		ft_log(double nb, double base)
{
	return (ft_ln(nb) / ft_ln(base));
}
