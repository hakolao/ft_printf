/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:01:12 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/27 12:53:42 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef struct		s_printf
{
	va_list		variables;
	char		*format;
	char		*result;
	char		*error;
	char		**symbols;
	int			len;
	int			fd;
}					t_printf;

typedef struct		s_printf_lengths
{
	int			middle_len;
	int			spec_len;
	int			sub_spec_len;
}					t_printf_lengths;

int					ft_printf(const char *format, ...);

/*
** Validation
*/

int					is_allowed_specifier(char c);
int					is_allowed_sub_specifier(char c);
int					is_char_specifier(char c);
int					is_float_specifier(char c);
int					is_int_specifier(char c);
t_printf_lengths	ft_printf_lengths(char *fmt, t_printf_lengths lengths);

/*
** Log
*/
int					log_err(char *str, char *strerror);

/*
**  Parsing
*/
char				*parse_int(char c, int var);

#endif
