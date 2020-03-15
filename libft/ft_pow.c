/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:25:06 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/15 17:03:42 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** https://www.codeproject.com/Tips/311714/Natural-Logarithms-and-Exponent
*/

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
	i = 2.0;
	frac *= (x / i);
	l = p;
	p += frac;
	while (l != p)
	{
		i++;
		frac *= (x / i);
		l = p;
		p += frac;
	}
	return (p);
}

long double		ft_powl(long double base, long double pow)
{
	return (ft_exp(pow * ft_ln(base)));
}

long double		ft_powl_int(long double nb, int pow)
{
	int			i;
	long double	res;

	i = 0;
	res = 1;
	while (i < pow)
	{
		res = res * nb;
		i++;
	}
	return (res);
}

int				ft_exp_base(long double nb, int base)
{
	int				i;
	long long int	nb_int;

	i = 0;
	nb = ft_abs_long_double(nb);
	if (nb > 1)
	{
		nb_int = (long long int)nb;
		while (nb_int >= base)
		{
			nb_int = nb_int / base;
			i++;
		}
		return (i);
	}
	while (nb < 1 && nb > 0)
	{
		nb = nb * (long double)base;
		i++;
	}
	return (-i);
}
