/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:01:12 by ohakola           #+#    #+#             */
/*   Updated: 2020/08/26 23:22:56 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DTOA_H
# define FT_DTOA_H

# include <stdint.h>

# include "libft.h"

/*
** Max length of big int array (blocks)
*/

# define MAX_BI_BLOCKS 1023
# define DTOA_BUF_SIZE 2048

/*
** Log base 10 of 2 as long double.
*/

# define LOG10_2 0.30102999566398119521373889472449

/*
** Format type, whether value is to be formatted like: 123.123 or 1.23123e002
*/

typedef enum			e_dtoa_format
{
	FORMAT_NORM,
	FORMAT_SCI
}						t_dtoa_format;

/*
** Dtoa's cutoff mode, None: no cutoff at all, all decimals are printed,
** total length uses cutoff number to account for count of all digits in the
** output. Fraction length cuts the number by counting number of decimal digits.
*/

typedef enum			e_cutoff_mode
{
	CUTOFF_NONE,
	CUTOFF_TOTAL_LENGTH,
	CUTOFF_FRACTION_LENGTH
}						t_cutoff_mode;

/*
** Input parameters to dtoa.
*/

typedef struct			s_dtoa_params
{
	long double		value;
	t_dtoa_format	format;
	int32_t			precision;
}						t_dtoa_params;

/*
** Big integer struct where integer is represented in base 2^32. Each block
** is a bit of 32 bit integer. So e.g. [123, 456, 789] =
** 123 * (2^32)^0 + 456 * (2^32)^1 + 789 * (2^32)^2 = 1.455448108E22
*/

typedef struct			s_big_int
{
	uint32_t		length;
	uint32_t		blocks[MAX_BI_BLOCKS];
}						t_big_int;

/*
** Mantissa: 2^52 + float mantissa
** Exponent: float exponent in base 2 ((exponent - 1023 - 52))
** mantissa_high_bit_index: Index of the highest mantissa bit
** Cutoff num: Where digit array is cut off (e.g. by precision)
** Out exponent: Base 10 exponent of the first digit (e.g. used in sci format)
*/

typedef struct			s_dragon4_params
{
	uint64_t		mantissa;
	int32_t			exponent;
	uint32_t		mantissa_high_bit_index;
	t_bool			has_unequal_margins;
	t_cutoff_mode	cutoff_mode;
	uint32_t		cutoff_num;
	char			*buf;
	uint32_t		buf_size;
	int32_t			*out_exponent;
}						t_dragon4_params;

/*
** Dtoa
*/
char					*ft_dtoa(t_dtoa_params params);
int						ft_dtoa_buf(t_dtoa_params params, char *buf,
						int buf_size);

/*
** Format
*/
uint32_t				format_normal(t_dragon4_params params,
						int32_t precision);
uint32_t				format_scientific(t_dragon4_params params,
						int32_t precision);

/*
** Dragon4
*/
uint32_t				dragon4(t_dragon4_params params);
uint32_t				output_without_cutoff(t_dragon4_params params,
						t_big_int *scale, t_big_int *scaled_value,
						t_big_int scaled_margins[2]);
uint32_t				output_with_cutoff(t_dragon4_params params,
						t_big_int *scale, t_big_int *scaled_value);
void					normalized_initial_state(t_dragon4_params params,
						t_big_int *scale, t_big_int *scaled_value,
						t_big_int scaled_margins[2]);
void					denormalized_initial_state(t_dragon4_params
						params, t_big_int *scale, t_big_int *scaled_value,
						t_big_int scaled_margins[2]);
void					scale_values_by_digit_exponent(t_big_int *scale,
						t_big_int *scaled_value, t_big_int scaled_margins[2],
						int32_t *digit_exponent);
void					prepare_values_for_division(t_big_int *scale,
						t_big_int *scaled_value, t_big_int scaled_margins[2]);

/*
** Math utils
*/
uint32_t				log_base2_32(uint32_t val);
uint32_t				log_base2_64(uint64_t val);

/*
** Big Int ops
*/
void					big_int_copy(t_big_int *to_copy, t_big_int *res);
void					big_int_set_zero(t_big_int *b);
t_bool					big_int_is_zero(t_big_int *b);
void					big_int_set_u64(t_big_int *b, uint64_t val);
void					big_int_set_u32(t_big_int *b, uint32_t val);
uint32_t				big_int_get_u32(t_big_int *b);
int32_t					big_int_cmp(t_big_int *lhs, t_big_int *rhs);
void					big_int_add(t_big_int *lhs, t_big_int *rhs,
						t_big_int *res);
void					big_int_mul(t_big_int *lhs, t_big_int *rhs,
						t_big_int *res);
void					big_int_mul_u32(t_big_int *lhs, uint32_t rhs,
						t_big_int *res);
void					big_int_mul_2(t_big_int *lhs, t_big_int *res);
void					big_int_mul_2_modif(t_big_int *mod);
void					big_int_mul_10_modif(t_big_int *mod);
void					big_int_retard_print(t_big_int *b);
void					big_int_pow_10(uint32_t exponent, t_big_int *res);
void					big_int_mul_pow_10(t_big_int *lhs,
						uint32_t exponent, t_big_int *res);
void					big_int_pow_2(uint32_t exponent, t_big_int *res);
uint32_t				big_int_divide_to_output_digit(t_big_int *dividend,
						t_big_int *divisor);
void					big_int_shift_left(uint32_t shift, t_big_int *big);

#endif
