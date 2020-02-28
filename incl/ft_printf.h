/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:01:12 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/28 13:41:42 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct		s_printf
{
	va_list		variables;
	char		*format;
	char		*spec;
	int			spec_len;
	char		*result;
	char		*error;
	char		**symbols;
	int			len;
	int			fd;
	int			left_justify;
	int			pad_zeros;
	int			show_sign;
	int			blank_space;
	int			zerox;
	int			width;
	int			precision;
}					t_printf;

typedef struct		s_printf_lengths
{
	int			middle_len;
	int			spec_len;
}					t_printf_lengths;

int					ft_printf(const char *format, ...);
int					reset_bools(t_printf *data);

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
char				*parse_int(t_printf *data);
char				*parse_float(t_printf *data);
char				*parse_address(t_printf *data);
int					parse_variables(t_printf *data, char *fmt);
int					parse_sub_specifiers(t_printf *data);
int					is_allowed_flag(char c);
int					is_allowed_width_spec(char c);

#endif
