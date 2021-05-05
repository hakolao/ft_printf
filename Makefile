# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/01 15:58:30 by ohakola           #+#    #+#              #
#    Updated: 2021/05/05 13:32:15 by ohakola          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libftprintf.a
LIBFT = ./libft
LIBDTOA = ./libdtoa
DIR_SRC = ./
LIBFTFLAGS = -L$(LIBFT) -lft
LIBDTOAFLAGS = -L$(LIBDTOA) -lftdtoa
INCLUDES = -I./include -I$(LIBFT) -I$(LIBDTOA)/include
FLAGS = -Wall -Wextra -Werror -O2
SOURCES = ft_printf.c \
			parse.c \
			parse_specs.c \
			parse_sub_specs.c \
			parse_int.c \
			parse_float.c \
			parse_utils1.c \
			parse_utils2.c \
			parse_utils3.c \
			string_utils.c \
			format.c \
			format_precision.c \
			format_padding.c \
			format_utils.c \
			validate.c \
			libdtoa/ft_dtoa.c \
			libdtoa/ft_dtoa_ld.c \
			libdtoa/format_normal.c \
			libdtoa/format_normal_utils.c \
			libdtoa/format_inf_nan.c \
			libdtoa/format_scientific.c \
			libdtoa/format_scientific_utils.c \
			libdtoa/math_utils.c \
			libdtoa/dragon4.c \
			libdtoa/dragon4_output.c \
			libdtoa/dragon4_values.c \
			libdtoa/big_int_add.c \
			libdtoa/big_int_divide.c \
			libdtoa/big_int_get_set.c \
			libdtoa/big_int_mul.c \
			libdtoa/big_int_mul_modif.c \
			libdtoa/big_int_pow.c \
			libdtoa/big_int_shift.c \
			libdtoa/big_int_utils.c

SRCS = $(addprefix $(DIR_SRC)/,$(SOURCES))
OBJS = $(SOURCES:.c=.o)

all: $(DIR_OBJ) $(NAME)

$(NAME): $(OBJS)
	@rm -rf temp
	@mkdir temp
	@mkdir temp/libdtoa
	@make -C $(LIBFT)
	@cd temp && ar x ../libft/libft.a
	ar rc $(NAME) $(OBJS) temp/*.o
	@ranlib $(NAME)
	@rm -rf temp

%.o: $(DIR_SRC)/%.c
	@$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<

clean:
	@/bin/rm -f $(OBJS)
	@make -C $(LIBFT) clean
	@make -C $(LIBDTOA) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBFT) fclean
	@make -C $(LIBDTOA) fclean

test: all
	@make -C $(LIBDTOA) test
	$(CC) -o test_run test_main/main.c \
		$(INCLUDES) \
		$(NAME)
	./test_run
	@/bin/rm -f main.o
	@/bin/rm -f test_run
	@make -C $(LIBFT) fclean
	@make -C $(LIBDTOA) fclean
	@make fclean

re: fclean all

.PHONY: all, clean, fclean, norm
