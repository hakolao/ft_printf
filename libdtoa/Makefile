# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/01 15:58:30 by ohakola           #+#    #+#              #
#    Updated: 2021/05/05 12:48:52 by ohakola          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libftdtoa.a
LIBFT = ../libft
DIR_SRC = ./
DIR_TESTS = ./tests
INCLUDES = -I./include -I$(LIBFT)
LIBFTFLAGS = -L$(LIBFT) -lft
FLAGS = -Wall -Wextra -Werror -O2
SOURCES = ft_dtoa.c \
			ft_dtoa_ld.c \
			format_normal.c \
			format_normal_utils.c \
			format_inf_nan.c \
			format_scientific.c \
			format_scientific_utils.c \
			math_utils.c \
			dragon4.c \
			dragon4_output.c \
			dragon4_values.c \
			big_int_add.c \
			big_int_divide.c \
			big_int_get_set.c \
			big_int_mul.c \
			big_int_mul_modif.c \
			big_int_pow.c \
			big_int_shift.c \
			big_int_utils.c

SRCS = $(addprefix $(DIR_SRC)/,$(SOURCES))
OBJS = $(SOURCES:.c=.o)

all: $(DIR_OBJ) $(NAME)

$(NAME): $(OBJS)
	@rm -rf temp
	@mkdir temp
	@make -C $(LIBFT)
	@cd temp && ar x ../$(LIBFT)/libft.a
	ar rc $(NAME) $(OBJS) temp/*.o
	@ranlib $(NAME)

%.o: $(DIR_SRC)/%.c
	@$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<

clean:
	@/bin/rm -rf temp
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

TEST_SRCS =$(wildcard $(DIR_TESTS)/*.c)
test: all
	@make -C $(LIBFT)
	$(CC) -o test_run $(TEST_SRCS) -L$(LIBFT) -lft $(FLAGS) $(INCLUDES) \
		 -I ./tests/include $(NAME) -Wno-strict-aliasing
	./test_run
	@/bin/rm -f main.o
	@/bin/rm -f test_run
	@make -C $(LIBFT) fclean
	@make fclean

re: fclean all

.PHONY: all, clean, fclean, norm
