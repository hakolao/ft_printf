/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 19:25:49 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/14 22:03:04 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** https://www.codeproject.com/Tips/311714/Natural-Logarithms-and-Exponent
*/

long double		ft_ln(long double nb)
{
	long double	n;
	long double	p;
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
	a = n;
	n = (((p / (ft_exp(n - 1.0))) + ((n - 1.0) * FT_MATH_E)) / FT_MATH_E);
	count = 0;
	while(n != a && count < 30)
	{
		a = n;
		n = (((p / (ft_exp(n - 1.0))) + ((n - 1.0) * FT_MATH_E)) / FT_MATH_E);
		count++;
	}
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
