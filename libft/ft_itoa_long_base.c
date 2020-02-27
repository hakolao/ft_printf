/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:31:31 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/27 15:39:34 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		get_arr_size(long int nb, int base, int sign)
{
	size_t	sign_add;

	sign_add = sign < 0 ? 1 : 0;
	return (get_num_len(ABS(nb), base) + sign_add + 1);
}

char				*ft_itoa_long_base(long int nb, int base)
{
	int		i;
	char	*arr;
	int		sign;
	char	*bases;

	sign = nb < 0 ? -1 : 1;
	if (base > 16 || base < 1)
		return (NULL);
	bases = "0123456789abcdef";
	if (!(arr = (char*)ft_memalloc(get_arr_size(nb, base, sign))))
		return (NULL);
	if (nb == FALSE)
		arr[0] = '0';
	i = 0;
	while (nb != 0)
	{
		arr[i++] = bases[sign * (nb % base)];
		nb = nb / base;
	}
	if (sign == -1 && base == TRUE)
		arr[i] = '-';
	ft_strrev(arr);
	return (arr);
}
