/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:10:41 by ezhukova          #+#    #+#             */
/*   Updated: 2019/06/01 16:08:09 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		start_size(int square)
{
	int ret;

	ret = 0;
	while (((ret * ret) / square) < 1)
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
	if (!(tab))
		return (-1);
	test = ft_strdup("....");
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
	ft_strdel(&test);
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
	ft_strdel(&test);
	return (height);
}

void	set_dimensions(t_board *mst)
{
	t_piece	*tmp;
	int		i;

	i = 1;
	mst->cur = 0;
	mst->valid = 0;
	tmp = mst->tmp_b;
	if (tmp)
	{
		tmp->width = get_width(tmp->piece, 0, 0);
		tmp->height = get_height(tmp->piece, 0, 0);
		tmp->row = 0;
		tmp->col = 0;
		tmp = tmp->next;
		while (i++ < mst->tet_count)
		{
			tmp->width = get_width(tmp->piece, 0, 0);
			tmp->height = get_height(tmp->piece, 0, 0);
			tmp->row = 0;
			tmp->col = 0;
			tmp = tmp->next;
		}
		tmp->next = NULL;
	}
}

void	f_init(t_board *mst)
{
	if (mst)
	{
		generate_solution_board(mst, start_size(mst->tet_count * 4));
		set_dimensions(mst);
	}
}
