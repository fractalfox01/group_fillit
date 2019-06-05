/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:56:39 by ezhukova          #+#    #+#             */
/*   Updated: 2019/06/04 18:55:12 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		map_pc(t_board *mst, t_piece *t, int c, int r)
{
	if (mst && t)
	{
		mst->slv_b[r + (t->sym_arr[1])][c + (t->sym_arr[0])] = t->p_num + 'A';
		mst->slv_b[r + (t->sym_arr[3])][c + (t->sym_arr[2])] = t->p_num + 'A';
		mst->slv_b[r + (t->sym_arr[5])][c + (t->sym_arr[4])] = t->p_num + 'A';
		mst->slv_b[r + (t->sym_arr[7])][c + (t->sym_arr[6])] = t->p_num + 'A';
		mst->valid += 1;
	}
}

int			c_h(char **s_b, t_piece *t, int c, int r)
{
	if (s_b[r + (t->sym_arr[1])][c + (t->sym_arr[0])] == '.' && \
		s_b[r + (t->sym_arr[3])][c + (t->sym_arr[2])] == '.' && \
		s_b[r + (t->sym_arr[5])][c + (t->sym_arr[4])] == '.' && \
		s_b[r + (t->sym_arr[7])][c + (t->sym_arr[6])] == '.')
		return (1);
	return (0);
}

int			area_helper(int l, t_piece *t, int c, int r)
{
	if ((((r + t->sym_arr[1])) > (l - 1) || ((c + t->sym_arr[0])) > l) || \
		(((r + t->sym_arr[3])) > (l - 1) || ((c + t->sym_arr[2])) > l) || \
		(((r + t->sym_arr[5])) > (l - 1) || ((c + t->sym_arr[4])) > l) || \
		(((r + t->sym_arr[7])) > (l - 1) || ((c + t->sym_arr[6])) > l))
		return (5);
	return (0);
}

int			check_area(t_board *mst, char **s_b)
{
	int		l;
	t_piece	*t;
	int		c;
	int		r;

	t = get_piece(mst, mst->cur);
	if (!(t))
		return (0);
	r = t->row;
	c = t->col;
	l = mst->b_size;
	if (mst && s_b)
	{
		if (area_helper(l, t, c, r))
			return (5);
		if (c_h(s_b, t, c, r))
		{
			map_pc(mst, t, t->col, t->row);
			return (4);
		}
		else
			return (5);
	}
	return (5);
}

int			start_mapping(t_board *mst)
{
	int	b;

	b = 0;
	if ((b = check_area(mst, mst->slv_b)) == 4)
		mst->cur += 1;
	return (b);
}
