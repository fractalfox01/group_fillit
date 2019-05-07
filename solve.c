/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 11:19:41 by tvandivi          #+#    #+#             */
/*   Updated: 2019/05/07 16:47:31 by tvandivi         ###   ########.fr       */
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

void    clear_piece(t_board *mst, t_piece *tetra)
{
    int i;
    int j;
    int b_max;

    i = -1;
    j = -1;
    b_max = (int)ft_strlen(mst->solved_board[0]);
    while (++i < b_max)
    {
        while (++j < b_max)
        {
            if (mst->solved_board[i][j] == tetra->p_num + 'A')
                mst->solved_board[i][j] = '.';
        }
    }
}

int     re_seat(t_piece *tetra)
{
    if (tetra)
    {
        return (1);
    }
    return (0);
}

int     update_coord(t_piece *tetra)
{
    if (tetra)
    {
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

int    map_to_main(t_board *mst, t_piece *tetra)
{
    if (mst && tetra)
    {
        return (1);
    }
    return (0);
}

int     try_piece(t_board *mst, t_piece *tetra)
{
    int i;
    int a = 0;

    i = 0;
    if (mst)
    {
        // If tetra == NULL; at end of list.
        if (tetra)
        {
            is_valid(mst);
            return (1);
        }
        // Over 0 means tetra was mapped successfully.
        if (map_to_main(mst, tetra) > 0)
        {
            tetra = get_lst_index(mst, ++i);
            // recursive; try next tetra piece.
            try_piece(mst, tetra);
            return (1);
        }
        else
        {
            // tetra had bad coordinates, clearing piece off board and trying new coordinate.
            clear_piece(mst, tetra);
            // If update_coord() == 1; then update was successful
            if (update_coord(tetra) == 1)
            {
                try_piece(mst, tetra);
                return (1);
            } // update_coord() was unsuccessful. reset last piece.
            else
            {
                tetra = get_lst_index(mst, --i);
                if (re_seat(tetra) == 1)
                {
                    if (tetra->p_num == 0)
                        return (0);
                    try_piece(mst, tetra);
                    return (1);
                }
                else
                {
                    // grow board size by 1
                    clear_solution_board(mst);
                    a++;
                    generate_solution_board(mst, (start_size(mst->tetra_count * 4) + a));
                    tetra = get_lst_index(mst, 0);
                    try_piece(mst, tetra);
                    return (1);
                }
            }
            
        }
        
    }
    return (0);
}

void	solve(t_board *mst)
{
    if (mst)
    {
        try_piece(mst, mst->tmp_board);
    }
}

