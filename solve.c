/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 11:19:41 by tvandivi          #+#    #+#             */
/*   Updated: 2019/05/19 15:26:56 by tvandivi         ###   ########.fr       */
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
	if (!(tmp) || cur > max_index)
		return (NULL);
	if (cur == max_index)
		return (NULL);
	while (tmp)
	{
		if (tmp->p_num == index)
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
        main_board->solved_board = (char **)malloc(sizeof(char *) * (size + 1));
        while (i++ < size)
        {
            tmp = ft_strnew((size_t)(size + 1));
            ft_memset(tmp, '.', (size_t)size);
            tmp[size] = 'Z';
            line = ft_strjoin(line, tmp);
            free(tmp);
            ft_bzero(tmp, (size_t)size);
        }
        main_board->solved_board = ft_strsplit(line, 'Z');
    }

}

int		is_solved(t_board *mst)
{
	if (mst)
	{
		mst->tetra_count == mst->valid;
		return (1);
	}
	return (0);
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
        }
        else
            tetra->col += 1;
        return (1);
    }
    return (0);
}

int		check_area(t_board *mst, char **solution_board)
{
	int	len;
	t_piece *tetra = get_piece(mst, mst->cur);
	int	col = tetra->col;
	int	row = tetra->row;
	int	rs = tetra->row;
	int	cs = tetra->col;
	int good = 0;
	
	len = mst->board_size;
	if (mst)
	{
		///

		while ((row - rs) < tetra->height && (row) < len)
        {
            while ((col - cs) < tetra->width && (col - cs) < len)
            {
                if (solution_board[row][col] == '.' && tetra->piece[(row - rs)][(col - cs)] != '.')
                {
                    good++;
                }
                else if (solution_board[row][col] != '.' && tetra->piece[(row - rs)][(col - cs)] != '.')
                    break ;
                col++;
            }
            col = cs;
            row++;
        }
        if (good == 4)
			return (good);
		return (1);
	}
	return (good);
}

int		start_mapping(t_board *mst)
{
	int	b = 0;

	if (is_solved(mst) == 1)
		return (0);
	while ((b = check_area(mst, mst->solved_board)) > 0)
	{
		if (b == 4)
		{
			//mst->valid += 1;
			map_tetra_to_main(mst, mst->cur, tetra->col, tetra->row);
			break ;
		}
		if (b == 1)
			update_coord(mst, mst->cur);
		else
		{// grab cur in bt; - 1; reset current row/col increase previous
			backtrack();
		}
		
	}
	mst->cur += 1;
	start_mapping(mst);
}

void	solve(t_board *main_board)
{
	if (main_board)
	{
		while (1)
		{
			if (start_mapping(main_board) == 0)
				break;
		}
	}
}
