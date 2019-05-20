FLAGS= -g -Wall -Wextra -Werror

SRC= fillit.c\
	 fillit_utils.c\
	 main.c\
	 validate.c\
	 print_util.c\
	 normalize.c\
	 norm_shifters.c\
	 to_alpha.c\
	 board_gen.c\
	 solve.c\
	 libft/ft_putchar.c\
	 libft/ft_putstr.c\
	 libft/ft_memset.c\
	 libft/ft_strjoin.c\
	 libft/ft_bzero.c\
	 libft/ft_strsplit.c\
	 libft/ft_strnew.c\
	 libft/ft_memalloc.c\
	 libft/ft_putnbr.c\
	 libft/ft_memdel.c\
	 libft/ft_memcpy.c\
	 ../../libft/ft_strbuild.c\
	 libft/ft_strdup.c\
	 libft/ft_strlen.c\
	 ../../libft/ft_wordcount.c\
	 libft/ft_strncpy.c\
	 ../../libft/ft_strxlen.c

all:
	gcc $(FLAGS) $(SRC) -o fillit

clean:
	@rm fillit || echo 'Already removed fillit'

fclean: clean
	@rm -r fillit.dSYM || echo 'Already removed fillit.dSYM'

re: fclean all

fc: fclean
