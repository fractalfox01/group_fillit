/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhukova <ezhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:56:39 by ezhukova          #+#    #+#             */
/*   Updated: 2019/06/04 17:38:28 by ezhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		map_pc(t_board *mst, t_piece *tetra, int col, int row)
{
	if (mst && tetra)
	{
		mst->slv_b[row + (tetra->sym_arr[1])][col + (tetra->sym_arr[0])] = tetra->p_num + 'A';
		mst->slv_b[row + (tetra->sym_arr[3])][col + (tetra->sym_arr[2])] = tetra->p_num + 'A';
		mst->slv_b[row + (tetra->sym_arr[5])][col + (tetra->sym_arr[4])] = tetra->p_num + 'A';
		mst->slv_b[row + (tetra->sym_arr[7])][col + (tetra->sym_arr[6])] = tetra->p_num + 'A';
		mst->valid += 1;
	}
}

int			check_area(t_board *mst, char **solution_board)
{
	int	len;
	t_piece *tetra = get_piece(mst, mst->cur);
	if (!(tetra))
		return (0);
	int	col = tetra->col;
	int	row = tetra->row;
	int good = 0;

	len = mst->b_size;
	if (mst && solution_board)
	{
		if ((((row + tetra->sym_arr[1])) > (len - 1) || ((col + tetra->sym_arr[0])) > len) || \
		(((row + tetra->sym_arr[3])) > (len - 1) || ((col + tetra->sym_arr[2])) > len) || \
		(((row + tetra->sym_arr[5])) > (len - 1) || ((col + tetra->sym_arr[4])) > len) || \
		(((row + tetra->sym_arr[7])) > (len - 1) || ((col + tetra->sym_arr[6])) > len))
			return (5);
		if (solution_board[row + (tetra->sym_arr[1])][col + (tetra->sym_arr[0])] == '.' && \
		solution_board[row + (tetra->sym_arr[3])][col + (tetra->sym_arr[2])] == '.' && \
		solution_board[row + (tetra->sym_arr[5])][col + (tetra->sym_arr[4])] == '.' && \
		solution_board[row + (tetra->sym_arr[7])][col + (tetra->sym_arr[6])] == '.')
		{
			good = 4;
			map_pc(mst, tetra, tetra->col, tetra->row);
			return (4);
		}
		else
			return (5);
	}
	return (5);
}

int		start_mapping(t_board *mst)
{
	int	b;

	b = 0;
	if ((b = check_area(mst, mst->slv_b)) == 4)
		mst->cur += 1;
	return (b);
}