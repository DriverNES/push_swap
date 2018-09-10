# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arcohen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/12 11:43:46 by arcohen           #+#    #+#              #
#    Updated: 2018/07/24 13:33:40 by arcohen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc -o
FLAGS = -Wall -Wextra -Werror
INC = -I ./includes/
LIB = ./libft/
SRC = ./srcs/*.c

RM = rm -rf

$(NAME):
	@make -C $(LIB)
	@$(CC) $(NAME) $(FLAGS) $(SRC) $(INC) -L libft/ -lft
	@echo "-- push_swap compiled successfully --"

all: $(NAME)

clean:
	@make clean -C $(LIB)

fclean:
	@make fclean -C $(LIB)
	@$(RM) $(NAME)

re: fclean all
