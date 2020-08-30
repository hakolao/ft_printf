# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/01 15:58:30 by ohakola           #+#    #+#              #
#    Updated: 2020/08/30 18:33:33 by ohakola          ###   ########.fr        #
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
			format_inf_nan.c \
			format_scientific.c \
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
	ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: $(DIR_SRC)/%.c
	@$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

TEST_SRCS =$(wildcard $(DIR_TESTS)/*.c)
test: all
	@make -C $(LIBFT)
	$(CC) -o test_run $(TEST_SRCS) -L$(LIBFT) -lft $(FLAGS) $(INCLUDES) \
		 -I ./tests/include $(NAME)
	./test_run
	@/bin/rm -f main.o
	@/bin/rm -f test_run
	@make -C $(LIBFT) fclean
	@make fclean

re: fclean all

.PHONY: all, clean, fclean, norm
