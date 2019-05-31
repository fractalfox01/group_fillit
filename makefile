SRC= fillit.c fillit_utils.c main.c solve.c validate.c libft/*.c

all:
	gcc -g $(SRC) -o fillit

clean:
	rm fillit

fclean: clean
	@rm -r fillit.dSYM 2>/dev/null || echo "not found..."

re: fclean all
