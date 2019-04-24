/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:35:26 by tvandivi          #+#    #+#             */
/*   Updated: 2019/04/23 22:30:24 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Bad character found: creates and returns an 'invalid' array. 
*/
char	**error(void)
{
	char	**bad_board;

	bad_board = ft_strsplit("invalid", ' ');
	return (bad_board);
}

/*
** Checks if the character read from file is a valid fillit character.
*/
int		is_valid_char(char c)
{
	if (c == '.')
		return (1);
	if (c == '#')
		return (2);
	if (c == '\n')
		return (3);
	return (0);
}

t_board	*new_board(int size)
{
	t_board new_board;
	t_board *ret;
	char	*blank_board;
	char	*tmp;
	int		i;

	i = 0;
	ret = &new_board;
	blank_board = (char *)malloc(sizeof(char) * 546);
	ft_bzero(blank_board, 545);
	while (i < size)
	{
		tmp = ft_strnew(size + 1);
		ft_memset(tmp, '.', (size_t)(size));
		tmp[size] = 'Z';
		blank_board = ft_strjoin(blank_board, tmp);
		ft_bzero(tmp, size );
		ft_strdel(&tmp);
		i++;
	}
	new_board.solved_board = ft_strsplit(blank_board, 'Z');
	new_board.tmp_board = NULL;
	new_board.tetra_count = (size <= 26) ? size : 26;
	new_board.valid = 1;
	return (ret);
}

int		read_file(char *file, t_board *n_board, int a)
{
	int		fd;
	int		i;
	t_piece	*tmp;
	char	*buf;
	
	fd = open(file, O_RDONLY);
	buf = ft_strnew(21);
	i = 0;
	if (fd > 0)
	{
		n_board->tmp_board = (t_piece *)malloc(sizeof(t_piece) * 1);
		tmp = n_board->tmp_board;
		while ((a = read(fd, buf, 21)) > 0)
		{
			if (a == 20 || a == 21)
				tmp = add_lst_piece(tmp, buf, i, a);
			else
				return (0);
			i++;
		}
	}
	if (!(!(n_board->tmp_board)))
		return (1);
	return (0);
}

void	make_board(t_board *main_board)
{
	if (main_board)
		return ;
}

void	fillit(char *file)
{
	int		i;
	t_board	*main_board;
	
	i = 0;
	main_board = (t_board *)malloc(sizeof(t_board) * 1);
	if (file)
	{
		if(read_file(file, main_board, 0) == 1)
		{
			set_length(main_board);
			if ((i = verify_file(main_board)) > 1)
			{
				ft_putstr("Bad block at: ");
				ft_putnbr(i - 2);
				ft_putchar('\n');
				return ;
			}
		//	make_board(main_board);
			print_pieces(main_board);
		//	print_board(main_board);
		}
		else
			ft_putstr("What exactly are you trying to do?\n");
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		fillit(av[1]);
	}
	return (0);
}
