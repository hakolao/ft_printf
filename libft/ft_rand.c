/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:11:37 by ohakola           #+#    #+#             */
/*   Updated: 2020/09/11 16:11:53 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** https://stackoverflow.com/questions/3062746/
** special-simple-random-number-generator
*/

int			ft_rand(int seed)
{
	seed = (1103515245 * seed + 12345) % (1 << 31);
	return (seed);
}
