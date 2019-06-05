# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezhukova <ezhukova@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/04 15:07:57 by ezhukova          #+#    #+#              #
#    Updated: 2019/06/04 17:25:59 by ezhukova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:	$(NAME)

NAME = fillit

SRC = fillit.c fillit_utils.c free_utils.c main.c solve.c \
		validate.c initialize.c backtrack.c mapping.c

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft/
	gcc $(FLAGS) -Llibft/ -lft -Ilibft/ $(SRC) -o $(NAME) 

clean:
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	rm $(NAME)

re: fclean all