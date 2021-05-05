/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 19:36:38 by ohakola           #+#    #+#             */
/*   Updated: 2021/05/03 16:16:56 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** https://stackoverflow.com/questions/3062746/
** special-simple-random-number-generator
*/

uint32_t	ft_rand(uint32_t seed)
{
	return ((1103515245 * seed + 12345) % (1 << 31));
}
