/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:35:26 by tvandivi          #+#    #+#             */
/*   Updated: 2019/05/19 14:37:08 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int			*get_coordinates(char **piece)
{
	int i;
	int j;
	int n;
	static int	arr[8];
	int	x_start;
	int y_start;

	j = -1;
	i = -1;
	x_start = 5;
	y_start = 0;
	n = 1;
	while (++i < 4)
	{
		while (++j < 4)
		{
			if (piece[i][j] == '#')
			{
				if (x_start == 5)
				{
					arr[0] = 0;
					arr[1] = 0;
					x_start = j;
					y_start = i;
				}
				else
				{
					arr[++n] = (j - x_start);
					arr[++n] = (i - y_start);
				}
			}
		}
		j = -1;
	}
	return (arr);
}

int		read_file(char *file, t_board *main_board)
{
	int		fd;
	int		i;
	int		a;
	t_piece	*tmp;
	int		*arr;
	char	buf[22];

	i = 0;
	fd = open(file, O_RDONLY);
	ft_bzero(buf, 22);
	if (fd < 0)
		return (-1);
	if (fd > 0)
	{
		main_board->tmp_board = (t_piece *)malloc(sizeof(t_piece) * 1);
		tmp = main_board->tmp_board;
		while ((a = read(fd, buf, 21)) == 20 || a == 21)
		{
			if ((a == 20) || ((a == 21) && (buf[20] == '\n')))
			{
				if (verify_piece(tmp, buf) == 1)
				{
					arr = get_coordinates(tmp->piece);
					tmp = add_lst_piece(tmp, buf, arr, a, i);
					i++;
				}
				else 
					return (-1);
			}
		}
		return ((main_board->tetra_count = i));
	}
	return (0);
}

void	print_pieces(t_board *mst)
{
	t_piece *tmp;
	int		i;
	int		k;

	tmp = mst->tmp_board;
	i = 0;
	k = 0;
	while (tmp)
	{
		if (tmp->piece)
		{
			while (k < 8)
			{
				ft_putnbr(tmp->sym_arr[k++]);
				ft_putstr(", ");
			}
			ft_putchar('\n');
			k = 0;
		}
		tmp = tmp->next;
	}
}

int     start_size(int square)
{
    int ret;

    ret = 0;
    while (((ret * ret)/square) < 1)
    {
        ret++;
    }
    return (ret);
}

int		get_width(char **tab, int row, int col)
{
	int		width;
	char	*test;

	width = 0;
	test = ft_strdup("....");
	if (!(tab))
		return (-1);
	while (row < 4)
	{
		while (col < 4)
		{
			if (tab[row][col] == '#')
				if (test[col] == '.')
					test[col] = '#';
			col++;
		}
		col = 0;
		row++;
	}
	col = 0;
	while (test[col] != '\0')
		if (test[col++] == '#')
			width++;
	return (width);
}

int		get_height(char **tab, int row, int col)
{
	int		height;
	char	*test;

	height = 0;
	test = ft_strdup("....");
	if (!(tab))
		return (-1);
	while (row < 4)
	{
		while (col < 4)
		{
			if (tab[row][col] == '#')
				if (test[row] == '.')
					test[row] = '#';
			col++;
		}
		col = 0;
		row++;
	}
	col = 0;
	while (test[col] != '\0')
		if (test[col++] == '#')
			height++;
	return (height);
}


void	set_dimensions(t_board *mst)
{
	t_piece	*tmp;
	t_piece	*head;
	int		i;

	i = 1;
	head = mst->tmp_board;
	if (head)
	{
		head->width = get_width(head->piece, 0, 0);
		head->height = get_height(head->piece, 0, 0);
		tmp = head->next;
		while (++i < mst->tetra_count)
		{
			tmp->width = get_width(tmp->piece, 0, 0);
			tmp->height = get_height(tmp->piece, 0, 0);
			tmp = tmp->next;
		}
		mst->tetra_count = (i - 1);
	}
}

void	f_init(t_board *mst)
{
	if (mst)
	{
		generate_solution_board(mst, start_size(mst->tetra_count * 4));
		set_dimensions(mst);
	}
}

void	fillit(char *file)
{
	t_board	*main_board;

	main_board = (t_board *)malloc(sizeof(t_board) * 1);
	if (file)
	{
		if (read_file(file, main_board) > 0)
		{
			printf("File read...\n\nInitializing Solution Board...\n\n");
			f_init(main_board);
			printf("initialization complete...\n\nWorking on a solution...\n\n");
			solve(main_board);
			printf("Solution Found...\n\nPrinting solution board...\n\n");
			print_pieces(main_board);
		}
		else
			ft_putstr("What exactly are you trying to do?\n");
	}
}
