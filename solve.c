/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 11:19:41 by tvandivi          #+#    #+#             */
/*   Updated: 2019/05/31 11:56:05 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	normalize_blocks(t_board *main_board)
{
	if (main_board)
		return ;
}

t_piece *get_piece(t_board *mst, int cur)
{
	t_piece	*tmp;
	int		max_index;

	tmp = mst->tmp_board;
	max_index = mst->tetra_count;
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

void	generate_solution_board(t_board *main_board, int size)
{
	char    *tmp;
    char    *line;
    int     i;

    i = 0;
    line = ft_strnew(1);
    ft_bzero(line, 1);
    if (main_board && size >= 1)
    {
        main_board->solved_board = (char **)malloc(sizeof(char *) * (size));
        while (i++ < size)
        {
            tmp = ft_strnew((size_t)(size + 1));
            ft_memset(tmp, '.', (size_t)size);
            tmp[size] = 'Z';
            line = ft_strjoin(line, tmp);
            ft_strdel(&tmp);
        }
        main_board->solved_board = ft_strsplit(line, 'Z');
		main_board->board_size = size;
    }

}

int		is_solved(t_board *mst)
{
	if (mst)
	{
		if (mst->tetra_count == mst->valid)
			return (1);
	}
	return (0);
}

void	map_piece(t_board *mst, t_piece *tetra, int col, int row)
{   
    if (mst && tetra)
    {
       mst->solved_board[row + (tetra->sym_arr[1])][col + (tetra->sym_arr[0])] = tetra->p_num + 'A';
	   mst->solved_board[row + (tetra->sym_arr[3])][col + (tetra->sym_arr[2])] = tetra->p_num + 'A';
	   mst->solved_board[row + (tetra->sym_arr[5])][col + (tetra->sym_arr[4])] = tetra->p_num + 'A';
	   mst->solved_board[row + (tetra->sym_arr[7])][col + (tetra->sym_arr[6])] = tetra->p_num + 'A';
	   mst->valid += 1;
    }
}

int     update_coord(t_board *mst, int cur)
{
    int len = mst->board_size;
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

void    zero_tetra(t_board *mst)
{
	t_piece   	*tmp;
	int			i;

    tmp = mst->tmp_board;
    i = 0;
	while (i++ < mst->tetra_count)
    {
        tmp->col = 0;
        tmp->row = 0;
        tmp = tmp->next;
    }
}

int    clear_tetra(t_board *mst)
{
    int i;
    int j;
    int b_max;
	t_piece *tetra;
    
	tetra = get_piece(mst, mst->cur);
	i = tetra->row;
    j = tetra->col;
    b_max = (int)ft_strlen(mst->solved_board[0]);
	if (!(tetra))
		return (0);
	else if (!(tetra->piece))
		return (0);
	mst->solved_board[i + tetra->sym_arr[1]][j + tetra->sym_arr[0]] = '.';
	mst->solved_board[i + tetra->sym_arr[3]][j + tetra->sym_arr[2]] = '.';
	mst->solved_board[i + tetra->sym_arr[5]][j + tetra->sym_arr[4]] = '.';
	mst->solved_board[i + tetra->sym_arr[7]][j + tetra->sym_arr[6]] = '.';
	return (1);
}

int		check_area(t_board *mst, char **solution_board)
{
	int	len;
	t_piece *tetra = get_piece(mst, mst->cur);
	if (!(tetra))
		return (0);
	int	col = tetra->col;
	int	row = tetra->row;
	int good = 0;
	
	len = mst->board_size;
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
			map_piece(mst, tetra, tetra->col, tetra->row);
			return (4);
		}
		else
			return (5);
	}
	return (5);
}

int	check_tmp(t_board *mst, t_piece *tmp)
{
	if (tmp)
	{
		if (tmp->p_num == 0)
		{
			mst->board_size += 1;
			free(mst->solved_board);
			zero_tetra(mst);
			generate_solution_board(mst, mst->board_size);
			mst->cur = 0;
			mst->valid = 0;
			return (1);
		}
	}
	return (0);
}

int	backtrack(t_board *mst)
{
	t_piece *tmp;
	int		len;
	
	tmp = get_piece(mst, mst->cur);
	if (check_tmp(mst, tmp))
		return (0);
	len = mst->board_size;
	if (mst->valid > 0)
		mst->valid -= 1;
	tmp->col = 0;
	tmp->row = 0;
	if (mst->cur > 0)
		mst->cur -= 1;
	//free(tmp);
	tmp = get_piece(mst, mst->cur);
	clear_tetra(mst);
	if (update_coord(mst, mst->cur) == 0)
		backtrack(mst);
	return (0);
}

int		start_mapping(t_board *mst)
{
	int	b = 0;

	if ((b = check_area(mst, mst->solved_board)) == 4)
		mst->cur += 1;
	return (b);
}

// Sample coords from tests/all_pieces.fillit
		// all coord's are relative to the larger board.
		// in this case a 9x9 board:		<- x-plane ->
		// (x y) (x y) (x y) (x y)
		// 0, 0, 1, 0, 0, 1, 1, 1, 			AABBBB...
		// 0, 0, 1, 0, 2, 0, 3, 0, 			AA.......    ^
		// 0, 0, 0, 1, 0, 2, 0, 3, 			.........    |
		// 0, 0, 1, 0, 2, 0, 2, 1, 			.........  y-plane
		// 0, 0, -2, 1, -1, 1, 0, 1, 		.........    |
		// 0, 0, 0, 1, 1, 1, 2, 1, 			.........    v
		// 0, 0, 1, 0, 2, 0, 0, 1, 			.........
		// 0, 0, 0, 1, -1, 2, 0, 2, 		.........
		// 0, 0, 0, 1, 0, 2, 1, 2,			.........
		// 0, 0, 1, 0, 1, 1, 1, 2, 
		// 0, 0, 1, 0, 0, 1, 0, 2, 
		// 0, 0, 1, 0, 2, 0, 1, 1, 
		// 0, 0, 0, 1, 1, 1, 0, 2, 
		// 0, 0, -1, 1, 0, 1, 1, 1, 
		// 0, 0, -1, 1, 0, 1, 0, 2, 
		// 0, 0, 1, 0, -1, 1, 0, 1, 
		// 0, 0, 1, 0, 1, 1, 2, 1, 
		// 0, 0, -1, 1, 0, 1, -1, 2, 
		// 0, 0, 0, 1, 1, 1, 1, 2,

int		tetra_coord(t_board *mst)
{
	t_piece *tmp;

	tmp = get_piece(mst, mst->cur);
	if (tmp->row == (mst->board_size - 1) && tmp->col == (mst->board_size - 1))
		return (1);
	return (0);
}

void	solve(t_board *main_board)
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
