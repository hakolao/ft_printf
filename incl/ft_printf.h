/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:01:12 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/26 15:14:18 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef struct	s_printf
{
	va_list		variables;
	char		*format;
	char		*result;
	char		*error;
	char		**symbols;
	int			len;
	int			fd;
}				t_printf;

int				ft_printf(const char *format, ...);

/*
** Validation
*/

int				is_allowed_specifier(char c);
int				is_allowed_sub_specifier(char c);

#endif