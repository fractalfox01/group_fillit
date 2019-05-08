/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 11:19:41 by tvandivi          #+#    #+#             */
/*   Updated: 2019/05/08 15:03:15 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     check_spot(t_board *mst, t_piece *tetra, int row, int col)
{
    int s_max;
    int c_s;
    int r_s;
    int good;

    c_s = col;
    r_s = row;
    good = 0;
    s_max = ft_strlen((mst->solved_board[0]));
    if (mst && tetra)
    {
        while (row < s_max && (row - r_s) < tetra->height)
        {
            while (col < s_max && (col - c_s) < tetra->width)
            {
                if (tetra->piece[(row - r_s)][(col - c_s)] != '.' && mst->solved_board[row][col] == '.')
                    good++;
                col++;
            }
            col = c_s;
            row++;
        }
    }
    return (good);
}

int    clear_piece(t_board *mst, t_piece *tetra)
{
    int i;
    int j;
    int b_max;

    i = -1;
    j = -1;
    b_max = (int)ft_strlen(mst->solved_board[0]);
	if (!(tetra))
		return (0);
	else if (!(tetra->piece))
		return (0);
	while (++i < b_max)
    {
        while (++j < b_max)
        {
            if (mst->solved_board[i][j] == tetra->p_num + 'A')
                mst->solved_board[i][j] = '.';
        }
        j = -1;
    }
	return (1);
}

int     re_seat(t_board *mst, t_piece *tetra)
{
    int len = ft_strlen(mst->solved_board[0]);
    if (tetra)
    {
        if (tetra->y == (len + 1) && tetra->x == (len + 1))
            return (0);
        else if (tetra->x == (len + 1))
        {
            tetra->x = 0;
            tetra->y += 1;
        }
        else if (tetra-> y == (len + 1))
            return (0);
        else
            tetra->x += 1;
        return (1);
    }
    return (0);
}

int     update_coord(t_board *mst, t_piece *tetra)
{
    int len = ft_strlen(mst->solved_board[0]);
    if (tetra)
    {
        if ((tetra->x) == (len + 1) && (tetra->y) == (len + 1))
            return (0);
        else if ((tetra->x) == (len + 1))
        {
            tetra->x = 0;
            tetra->y += 1;
        }
        else if ((tetra->y) == (len + 1))
            return (0);
        else
            tetra->x += 1;
        return (1);
    }
    return (0);
}

int     is_valid(t_board *mst)
{
    if (mst)
    {
        return (1);
    }
    return (0);
}

void    map_it(t_board *mst, t_piece *tetra)
{
    int col = tetra->x;
    int row = tetra->y;
    int cs = col;
    int rs = row;
    
    if (mst && tetra)
    {
        while ((row - rs) < tetra->height)
        {
            while ((col - cs) < tetra->width)
            {
                if (mst->solved_board[row][col] == '.' && tetra->piece[(row - rs)][(col - cs)] != '.')
                    mst->solved_board[row][col] = tetra->p_num + 'A';
                col++;
            }
            col = cs;
            row++;
        }
    }
}

int    map_to_main(t_board *mst, t_piece *tetra)
{
    int col = tetra->x;
    int row = tetra->y;
    int cs = col;
    int rs = row;
    int good = 0;

    if (mst && tetra)
    {
        while ((row - rs) < tetra->height && row < (int)ft_strlen(mst->solved_board[0]))
        {
            while ((col - cs) < tetra->width)
            {
                if (mst->solved_board[row][col] == '.' && tetra->piece[(row - rs)][(col - cs)] != '.')
                {
                    good++;
                }
                col++;
            }
            col = cs;
            row++;
        }
        if (good == 4)
        {
            map_it(mst, tetra);
            return (1);
        }
    }
    return (0);
}

int     try_piece(t_board *mst, t_piece *tetra, int i)
{
    int a = 0;
    int b = 0;

    if (mst)
    {
        // If tetra == NULL; at end of list.
        if (!(tetra))
        {
            is_valid(mst);
            return (1);
        }
        // Over 0 means tetra was mapped successfully.
        if (map_to_main(mst, tetra) > 0)
        {
            i += 1;
            tetra = NULL;
            tetra = get_lst_index(mst, i);
            // recursive; try next tetra piece.
            try_piece(mst, tetra, i);
            return (1);
        }
        else
        {
            // tetra had bad coordinates, clearing piece off board and trying new coordinate.
            //clear_piece(mst, tetra);
            // If update_coord() == 1; then update was successful
            if ((b = update_coord(mst, tetra)) == 1)
            {
                try_piece(mst, tetra, i);
                return (1);
            } // update_coord() was unsuccessful. reset last piece.
            else
            {
				tetra->x = 0;
				tetra->y = 0;
                i--;
                tetra = get_lst_index(mst, i);
                while (clear_piece(mst, tetra) == 0)
					tetra = get_lst_index(mst, --i);
                if (tetra->p_num == 0 && tetra->y >= (int)ft_strlen(mst->solved_board[0]))
                {
                    clear_solution_board(mst);
                    a++;
                    generate_solution_board(mst, (start_size(mst->tetra_count * 4) + a));
                    tetra = get_lst_index(mst, 0);
                    try_piece(mst, tetra, i);
                }
                else
				{
					re_seat(mst, tetra);
                    try_piece(mst, tetra, i);
				}
				return (1);
            }
            return (0);
        }
        
    }
    return (0);
}

void	solve(t_board *mst)
{
    static int i = 0;
    
    if (mst)
    {
        while (1)
        {
            if (try_piece(mst, mst->tmp_board, i) == 1)
                break ;
        }
    }
}

