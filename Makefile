# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/04 15:07:57 by ezhukova          #+#    #+#              #
#    Updated: 2019/06/07 09:09:40 by tvandivi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:	$(NAME)

NAME = fillit

SRC = fillit.c fillit_utils.c free_utils.c main.c solve.c \
	validate.c initialize.c backtrack.c mapping.c

FLAGS = -Wall -Wextra -Werror

OBJ = fillit.o fillit_utils.o free_utils.o main.o solve.o \
	validate.o initialize.o backtrack.o mapping.o

all: $(NAME)

$(NAME):
	make -C libft/ all
	gcc $(FLAGS) -Llibft/ -lft -Ilibft/ $(SRC) -o $(NAME) 

clean:
	make -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
