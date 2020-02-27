/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:10:25 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/27 15:43:53 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_itoa() function transforms an integer base 10
** into a string representation of the number
*/

char				*ft_itoa(int nb)
{
	int		i;
	char	*arr;
	int		sign;

	sign = nb < 0 ? -1 : 1;
	if (!(arr = (char*)ft_memalloc(get_num_len(nb, 10) +
		(sign < 0 ? 1 : 0) + 1)))
		return (NULL);
	if (nb == FALSE)
		arr[0] = '0';
	i = 0;
	while (nb != 0)
	{
		arr[i++] = sign * (nb % 10) + 48;
		nb = nb / 10;
	}
	if (sign == -1)
		arr[i] = '-';
	ft_strrev(arr);
	return (arr);
}

char				*ft_itoa_long(long int nb)
{
	int		i;
	char	*arr;
	int		sign;

	sign = nb < 0 ? -1 : 1;
	if (!(arr = (char*)ft_memalloc(get_num_len(nb, 10) +
		(sign < 0 ? 1 : 0) + 1)))
		return (NULL);
	if (nb == FALSE)
		arr[0] = '0';
	i = 0;
	while (nb != 0)
	{
		arr[i++] = sign * (nb % 10) + 48;
		nb = nb / 10;
	}
	if (sign == -1)
		arr[i] = '-';
	ft_strrev(arr);
	return (arr);
}
