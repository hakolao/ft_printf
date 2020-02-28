# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/01 15:58:30 by ohakola           #+#    #+#              #
#    Updated: 2020/02/28 16:26:40 by ohakola          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = ft_printf.a
LIBFT = ./libft
DIR_SRC = src
DIR_OBJ = temp
HEADERS = incl
LIBFTFLAGS = -L$(LIBFT) -lft
FLAGS = -Wall -Wextra -Werror -O2
SOURCES = ft_printf.c \
			parser.c \
			sub_specifiers.c \
			address.c \
			numbers.c \
			log.c \
			strings.c \
			validate.c

SRCS = $(addprefix $(DIR_SRC)/,$(SOURCES))
OBJS = $(addprefix $(DIR_OBJ)/,$(SOURCES:.c=.o))

all: $(DIR_OBJ) $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(DIR_OBJ):
	@mkdir -p temp

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c $(HEADERS)/ft_printf.h
	@$(CC) $(FLAGS) -I $(HEADERS) -c -o $@ $<

clean:
	@/bin/rm -f $(OBJS)
	@make -C $(LIBFT) clean
	@/bin/rm -rf $(DIR_OBJ)

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

.PHONY: all, $(DIR_OBJ), clean, fclean, norm
