# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/01 15:58:30 by ohakola           #+#    #+#              #
#    Updated: 2020/03/04 16:33:58 by ohakola          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libftprintf.a
LIBFT = ./libft
DIR_SRC = src
HEADERS = incl
LIBFTFLAGS = -L$(LIBFT) -lft
FLAGS = -Wall -Wextra -O2
SOURCES = ft_printf.c \
			parser.c \
			sub_specifiers.c \
			address.c \
			numbers.c \
			log.c \
			strings.c \
			validate.c

SRCS = $(addprefix $(DIR_SRC)/,$(SOURCES))
OBJS = $(SOURCES:.c=.o)

all: $(DIR_OBJ) $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: $(DIR_SRC)/%.c
	@$(CC) $(FLAGS) -I $(HEADERS) -c -o $@ $<

clean:
	@/bin/rm -f $(OBJS)
	@make -C $(LIBFT) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBFT) fclean

norm:
	norminette $(HEADERS) $(LIBFT) $(DIR_SRC)

test: all
	@make -C $(LIBFT)
	@$(CC) -o test_run test/main.c $(NAME) $(FLAGS) $(LIBFTFLAGS) -I$(HEADERS)
	./test_run
	@/bin/rm -f main.o
	@/bin/rm -f test_run

re: fclean all

.PHONY: all, clean, fclean, norm
