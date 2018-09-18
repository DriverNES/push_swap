# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndriver <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/17 10:55:32 by ndriver           #+#    #+#              #
#    Updated: 2018/09/18 11:41:12 by ndriver          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1= checker

NAME2= push_swap

all:	$(NAME1) $(NAME2)

lib:	
	make re -C ./libft/
	make clean -C ./libft/

SRC1=	./srcs/checker.c ./srcs/algo.c ./srcs/checks.c ./srcs/initialize.c ./srcs/maxmin.c \
		./srcs/push_and_print.c ./srcs/rev_rotate.c ./srcs/rotate.c ./srcs/swap.c

SRC2=	./srcs/push_swap.c ./srcs/algo.c ./srcs/checks.c ./srcs/initialize.c ./srcs/maxmin.c \
		./srcs/push_and_print.c ./srcs/rev_rotate.c ./srcs/rotate.c ./srcs/swap.c

OBJ1= $(SRC1:./srcs/*.c=.o)

OBJ2= $(SRC2:./srcs/*.c=.o)

$(NAME1):
		$(lib)
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
