/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itorgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:08:07 by ohakola           #+#    #+#             */
/*   Updated: 2021/05/03 16:37:53 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Converts integer value of an rgb value
** to an rgb struct with separate ints for
** all the separate colors.
*/

t_rgb	*ft_itorgb(int rgb_val)
{
	t_rgb	*rgb;

	rgb = (t_rgb *)malloc(sizeof(t_rgb));
	if (rgb == NULL)
		return (NULL);
	rgb->r = (rgb_val >> 16) & 255;
	rgb->g = (rgb_val >> 8) & 255;
	rgb->b = rgb_val & 255;
	return (rgb);
}
