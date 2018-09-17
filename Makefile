# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndriver <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/17 10:55:32 by ndriver           #+#    #+#              #
#    Updated: 2018/09/13 12:40:31 by ndriver          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1= checker

NAME2= push_swap

all:	$(NAME1) $(NAME2)

lib:	
	make re -C ./libft/
	make clean -C ./libft/

SRC1= ./srcs/checker.c ./srcs/z.c ./srcs/algo.c ./srcs/first.c

SRC2= ./srcs/push_swap.c ./srcs/z.c ./srcs/algo.c ./srcs/first.c

OBJ1= $(SRC1:./srcs/*.c=.o)

OBJ2= $(SRC2:./srcs/*.c=.o)

$(NAME1):
		gcc -Wall -Werror -Wextra -g -c $(SRC1)
		gcc -g -o $(NAME1) $(OBJ1) -L. ./libft/libft.a

$(NAME2):
		gcc -Wall -Werror -Wextra -g -c $(SRC2)
		gcc -g -o $(NAME2) $(OBJ2) -L. ./libft/libft.a

clean:
		rm -f *.o

fclean:		clean
		rm -rf $(NAME1)
		rm -rf $(NAME2)

re:		fclean all
		make clean
