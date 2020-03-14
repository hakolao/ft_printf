/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:25:06 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/14 21:58:16 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double		ft_exp(long double exp)
{
	long double	x;
	long double	p;
	long double	frac;
	long double	i;
	long double	l;

	x = exp;
	frac = x;
	p = (1.0 + x);
	i = 1.0;
	do
	{
		i++;
		frac *= (x/ i);
		l = p;
		p += frac;
	}while(l != p);
	return (p);
}

long double		ft_powl(long double nb, long double pow)
{
	return (ft_exp(pow * ft_ln(nb)));
}
