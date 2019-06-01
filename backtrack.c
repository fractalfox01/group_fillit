/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhukova <ezhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:38:53 by ezhukova          #+#    #+#             */
/*   Updated: 2019/05/31 16:48:54 by ezhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece		*get_piece(t_board *mst, int cur)
{
	t_piece	*tmp;
	int		max_index;

	tmp = mst->tmp_b;
	max_index = mst->tet_count;
	if (cur > max_index)
		cur = max_index + 1;
	if (!(tmp) || cur >= max_index)
		return (NULL);
	while (tmp)
	{
		if (tmp->p_num == cur)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

int			update_coord(t_board *mst, int cur)
{
	int len = mst->b_size;
	t_piece *tetra = get_piece(mst, cur);
	if (len)
	{
		if ((tetra->col) == (len - 1) && (tetra->row + 1) < len)
		{
			tetra->col = 0;
			tetra->row += 1;
			return (1);
		}
		else if ((tetra->col + 1) < len)
		{
			tetra->col += 1;
			return (1);
		}
	}
	return (0);
}

int			clear_tetra(t_board *mst)
{
	int i;
	int j;
	int b_max;
	t_piece *tetra;

	tetra = get_piece(mst, mst->cur);
	i = tetra->row;
	j = tetra->col;
	b_max = (int)ft_strlen(mst->slv_b[0]);
	if (!(tetra))
		return (0);
	else if (!(tetra->piece))
		return (0);
	mst->slv_b[i + tetra->sym_arr[1]][j + tetra->sym_arr[0]] = '.';
	mst->slv_b[i + tetra->sym_arr[3]][j + tetra->sym_arr[2]] = '.';
	mst->slv_b[i + tetra->sym_arr[5]][j + tetra->sym_arr[4]] = '.';
	mst->slv_b[i + tetra->sym_arr[7]][j + tetra->sym_arr[6]] = '.';
	return (1);
}

int	check_tmp(t_board *mst, t_piece *tmp)
{
	if (tmp)
	{
		if (tmp->p_num == 0)
		{
			mst->b_size += 1;
			free(mst->slv_b);
			zero_tetra(mst);
			generate_solution_board(mst, mst->b_size);
			mst->cur = 0;
			mst->valid = 0;
			return (1);
		}
	}
	return (0);
}

int		backtrack(t_board *mst)
{
	t_piece *tmp;
	int		len;

	tmp = get_piece(mst, mst->cur);
	if (check_tmp(mst, tmp))
		return (0);
	len = mst->b_size;
	if (mst->valid > 0)
		mst->valid -= 1;
	tmp->col = 0;
	tmp->row = 0;
	if (mst->cur > 0)
		mst->cur -= 1;
	tmp = get_piece(mst, mst->cur);
	clear_tetra(mst);
	if (update_coord(mst, mst->cur) == 0)
		backtrack(mst);
	return (0);
}