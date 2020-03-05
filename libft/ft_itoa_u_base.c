/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:06:11 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/05 15:06:34 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_itoa_u_base(unsigned int nb, unsigned int base)
{
	int		i;
	char	*arr;
	int		sign;
	char	*bases;

	sign = 1;
	if (base > 16 || base < 1)
		return (NULL);
	bases = "0123456789abcdef";
	if (!(arr = (char*)ft_memalloc(get_num_len(nb, 10) + 1)))
		return (NULL);
	if (nb == FALSE)
		arr[0] = '0';
	i = 0;
	while (nb != 0)
	{
		arr[i++] = bases[sign * (nb % base)];
		nb = nb / base;
	}
	ft_strrev(arr);
	return (arr);
}
