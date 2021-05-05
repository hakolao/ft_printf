/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:34:33 by ohakola           #+#    #+#             */
/*   Updated: 2021/05/03 16:18:06 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_memcmp() function compares byte string s1 against byte string s2.
** Both strings are assumed to be n bytes long.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1cpy;
	const unsigned char	*s2cpy;

	s1cpy = (const unsigned char *)s1;
	s2cpy = (const unsigned char *)s2;
	while (n--)
	{
		if (*s1cpy++ != *s2cpy++)
			return (*(s1cpy - 1) - *(s2cpy - 1));
	}
	return (0);
}
