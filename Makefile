# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndriver <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/17 10:55:32 by ndriver           #+#    #+#              #
#    Updated: 2018/09/11 11:39:19 by ndriver          ###   ########.fr        #
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

all: $(NAME)

clean:
	@make clean -C $(LIB)

fclean:
	@make fclean -C $(LIB)
	@$(RM) $(NAME)


re: fclean all
