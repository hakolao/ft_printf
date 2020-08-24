# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/01 15:58:30 by ohakola           #+#    #+#              #
#    Updated: 2020/08/24 22:28:59 by ohakola          ###   ########.fr        #
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
			parse_numbers.c \
			parse_utils.c \
			string_utils.c \
			format.c \
			format_precision.c \
			format_padding.c \
			format_utils.c \
			validate.c

SRCS = $(addprefix $(DIR_SRC)/,$(SOURCES))
OBJS = $(SOURCES:.c=.o)

all: $(DIR_OBJ) $(NAME)

$(NAME): $(OBJS)
	@mkdir temp
	@make -C $(LIBFT)
	@make -C $(LIBDTOA)
	@cd temp && ar x ../libft/libft.a
	@cd temp && ar x ../libdtoa/libftdtoa.a
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
		$(LIBFTFLAGS) \
		$(LIBDTOAFLAGS) \
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
