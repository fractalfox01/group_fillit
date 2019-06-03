/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 11:19:41 by tvandivi          #+#    #+#             */
/*   Updated: 2019/06/01 16:39:10 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		generate_solution_board(t_board *main_board, int size)
{
	char	*tmp;
	char	*ptr;
	char	*line;
	int		i;

	i = 0;
	line = ft_strnew(1);
	ft_bzero(line, 1);
	if (main_board && size >= 1)
	{
		main_board->slv_b = (char **)malloc(sizeof(char *) * (size));
		while (i++ < size)
		{
			tmp = ft_strnew((size_t)(size));
			ft_memset(tmp, '.', (size_t)size);
			tmp[size] = 'Z';
			ptr = ft_strjoin(line, tmp);
			ft_strdel(&line);
			line = &*ptr;
			ft_strdel(&tmp);
		}
		main_board->slv_b = ft_strsplit(line, 'Z');
		ft_strdel(&line);
		main_board->b_size = size;
	} 
}

void		zero_tetra(t_board *mst)
{
	t_piece		*tmp;
	int			i;

	tmp = mst->tmp_b;
	i = 0;
	while (i++ < mst->tet_count)
	{
		tmp->col = 0;
		tmp->row = 0;
		tmp = tmp->next;
	}
}

int			tetra_coord(t_board *mst)
{
	t_piece *tmp;

	tmp = get_piece(mst, mst->cur);
	if (tmp->row == (mst->b_size - 1) && tmp->col == (mst->b_size - 1))
		return (1);
	return (0);
}

void		solve(t_board *main_board)
{
	int a;
	int	b;

	a = 0;
	b = 1;
	if (main_board)
	{
		while (b)
		{
			if ((b = start_mapping(main_board)) > 0)
			{
				if (b == 4)
					continue;
				if (tetra_coord(main_board) == 1)
					backtrack(main_board);
				else
					update_coord(main_board, main_board->cur);
			}
		}
	}
}
