/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:01:12 by ohakola           #+#    #+#             */
/*   Updated: 2020/03/10 14:13:51 by ohakola          ###   ########.fr       */
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
	char		c;
	int			spec_len;
	int			middle_len;
	int			var_len;
	char		*buffer;
	int			len;
	int			fd;
	int			left_justify;
	int			pad_zeros;
	int			show_sign;
	int			blank_space;
	int			zerox;
	int			width;
	int			precision;
	int			has_precision;
	int			length_type;
}					t_printf;

typedef struct		s_printf_lengths
{
	int			middle_len;
	int			spec_len;
}					t_printf_lengths;

enum			e_lengths
{
	length_none,
	length_hh,
	length_h,
	length_l,
	length_ll,
	length_j,
	length_z,
	length_t,
	length_L
};

int					ft_printf(const char *format, ...);

/*
** Validation
*/

int					is_specifier(char c);
int					is_sub_specifier(char c);
int					is_float_specifier(char c);
int					is_int_specifier(char c);
int					is_flag(char c);

/*
** Log
*/
int					log_err(char *str, char *strerror);
int					debug_flags(t_printf *data);

/*
**  Parsing
*/
int					reset_var_data(t_printf *data);
int					parse_input(t_printf *data, char *fmt);
int					parse_sub_specifiers(t_printf *data);
char				*parse_spec_variable_pair(t_printf *data, char *fmt);

/*
** Number parsing
*/
char				*parse_int(t_printf *data);
char				*parse_float(t_printf *data);
char				*parse_address(t_printf *data);

/*
** String utils
*/
char				*add_to_str(char *str, size_t new_size);
char				*add_char_to_beg(char *str, char c, size_t new_size);
char				*add_str_to_beg(char *str, char *add);
char				*extend_str(char *str, int size_in, int add_size);

/*
** Format
*/
t_printf_lengths	fmt_part_lengths(char *fmt, t_printf_lengths lengths);
char				*handle_padding(t_printf *data, char *res);
char				*handle_precision(t_printf *data, char *res);
char				*handle_formatting(t_printf *data, char *res);
char				*handle_int_padding(t_printf *data, char *res);
char				*handle_string_padding(t_printf *data, char *res);
char				*handle_char_padding(t_printf *data, char *res);
char				*handle_int_precision(t_printf *data, char *res);
char				*handle_string_precision(t_printf *data, char *res);
char				*handle_char_precision(t_printf *data, char *res);

#endif
