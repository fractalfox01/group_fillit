/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:35:26 by tvandivi          #+#    #+#             */
/*   Updated: 2019/06/03 13:26:13 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		read_file(char *file, t_board *main_board, int i)
{
	int		fd;
	int		a;
	t_piece	*tmp;
	int		*arr;
	char	buf[22];

	fd = open(file, O_RDONLY);
	ft_bzero(buf, 22);
	if (fd < 0)
		return (-1);
	if (fd > 0)
	{
		main_board->tmp_b = (t_piece *)malloc(sizeof(t_piece) * 1);
		tmp = main_board->tmp_b;
		while ((a = read(fd, buf, 21)) == 20 || a == 21)
		{
			if ((a == 20) || ((a == 21) && (buf[20] == '\n')))
			{
				if (verify_piece(tmp, buf) == 1)
					tmp = add_lst_piece(tmp, buf, (arr = get_coordinates(tmp->piece, -1, -1)), a, i++);
				else
					return (-1);
			}
		}
		if (a != 0)
			return (-1);
		return ((main_board->tet_count = i));
	}
	return (0);
}

void	print_mst_board(t_board *mst)
{
	int	i;

	i = 0;
	while (mst->slv_b[i] != NULL)
	{
		ft_putstr(mst->slv_b[i++]);
		ft_putchar('\n');
	}
}

void	operation_free(t_board *mst)
{
	t_piece *lptr;
	t_piece *tmp;
	int		i;
	int		len;

	i = 0;
	if (mst)
	{
		while (i < mst->b_size)
			ft_strdel(&mst->slv_b[i++]);
		free(mst->slv_b);
		i = 0;
		lptr = mst->tmp_b;
		while (lptr->piece)
		{
			while (i < 4)
				ft_strdel(&lptr->piece[i++]);
			i = 0;
			ft_memdel((void **)&lptr->sym_arr);
			tmp = lptr;
			lptr = lptr->next;
			ft_memdel((void **)tmp);
			free(tmp);
		}
		free(lptr);
		free(mst);
		return ;
	}
}

void	fillit(char *file)
{
	t_board	*main_board;

	main_board = (t_board *)malloc(sizeof(t_board) * 1);
	if (file)
	{
		if (read_file(file, main_board, 0) > 0)
		{
			f_init(main_board);
			solve(main_board);
			print_mst_board(main_board);
			operation_free(main_board);
			//system("leaks fillit");
		}
		else
			ft_putstr("error\n");
	}
}
