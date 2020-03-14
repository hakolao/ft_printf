/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 19:25:49 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/14 19:49:05 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double		ft_ln(long double nb)
{
	long double		prev_sum;
	long double		frac;
	long double		frac_2;
	long double		sum;
	long double		denom;

	prev_sum = 0.0;
	frac = (nb - 1) / (nb + 1);
	frac_2 = frac * frac;
	denom = 1.0;
	sum = frac;
	while ( sum != prev_sum )
	{
		prev_sum = sum;
		denom += 2.0;
		frac *= frac_2;
		sum += frac / denom;
	}
	return (2.0 * sum);
}

long double		ft_log10(long double nb)
{
	return ft_ln(nb) / LN10;
}
