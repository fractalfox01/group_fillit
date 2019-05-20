/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 11:19:41 by tvandivi          #+#    #+#             */
/*   Updated: 2019/05/10 19:11:11 by tvandivi         ###   ########.fr       */
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
        if ((tetra->x + 1) == (len) && (tetra->y + 1) == (len))
            return (-1);
        else if ((tetra->x + 1) == (len))
        {
            tetra->x = 0;
            tetra->y += 1;
        }
        else if (tetra->y == (len + 1) && tetra->x == (len + 1))
            return (0);
        else
            tetra->x += 1;
        return (1);
    }
    return (0);
}

void    clear_mst(t_board *mst, int row, int col)
{
    int len;

    len = start_size(mst->tetra_count);
    while (row < len)
    {
        while (col < len)
        {
            mst->solved_board[row][col] = '.';
            col++;
        }
        col = 0;
        row++;
    }
}

int     check_square(t_board *mst, int row, int col)
{
    int f = 0;
    int s = 0;
    int len = ft_strlen(mst->solved_board[0]);
    int tmp = ft_strlen(mst->found_valid[0]);
    if (len == tmp)
    {
        while (f == s && row < len)
        {
            while (col < len)
            {
                if (mst->solved_board[row][col] == '.')
                    f++;
                if (mst->found_valid[row][col] == '.')
                    s++;
                col++;
            }
            col = row;
            while (row < len)
            {
                if (mst->solved_board[row][col] == '.')
                    f++;
                if (mst->found_valid[row][col] == '.')
                    s++;
                row++;
            }
            row = (col + 1);
            col = row;
        }
        if (f == s)
            return (0);
        if (f < s)
            return (-1);
        return (1);
    }
    else if (len > tmp)
    {
        return (1);
    }
    else if (len < tmp)
    {
        return (-1);
    }
    return (2);
}

void    map_rev(t_board *mst)
{
    int row;
    int col;
    int len;

    row = 0;
    col = 0;
    len = (int)ft_strlen(mst->solved_board[0]);
    while (row < len)
    {
        while (col < len)
        {
            mst->solved_board[row][col] = mst->found_valid[row][col];
            //mst->found_valid[row][col] = '.';
            col++;
        }
        col = 0;
        row++;
    }
}

void    map_board(t_board *mst)
{
    int row;
    int col;
    int len;

    row = 0;
    col = 0;
    len = (int)ft_strlen(mst->solved_board[0]);
    while (row < len)
    {
        while (col < len)
        {
            mst->found_valid[row][col] = mst->solved_board[row][col];
            mst->solved_board[row][col] = '.';
            col++;
        }
        col = 0;
        row++;
    }
}

void    reset_tetra_coord(t_board *mst, int i)
{
    t_piece	*tmp;
	t_piece *head;
    int     f_max;

	head = mst->tmp_board;
    f_max = (int)ft_strlen(mst->solved_board[0]);
	if (head)
	{
        if (head->p_num == i)
        {
            if ((head->x + 1) < f_max)
                head->x += 1;
            else if ((head->y + 1) < f_max)
                head->y += 1;
            else
                i++;
        }
        else
        {
            head->x = 0;
            head->y = 0;
        }
		tmp = head->next;
		while (tmp != NULL)
		{
            if (tmp->p_num == i)
            {
                if ((tmp->x + 1) < f_max)
                    tmp->x += 1;
                else if ((tmp->y + 1) < f_max)
                    tmp->y += 1;
                else
                    i++;        
            }
            else
            {
                tmp->x = 0;
                tmp->y = 0;
            }
			tmp = tmp->next;
		}
	}
}

int     is_valid(t_board *mst, t_piece *tetra, int a)
{
    int len;
    int i;
	int	size;
    int b;
  //  size_t size = ft_strlen(mst->solved_board[0]) * ft_strlen(mst->solved_board[0]);

	size = ft_strlen(mst->solved_board[0]);
    len = 0;
    i = 0;
    b = 0;
	tetra = get_lst_index(mst, 0);
	if (mst)
    {
        ft_putstr("IsValid\n");
        print_mst_board(mst);
        if (tetra->x == size && tetra->y == size)
        {
	    // backtracked out of options; increase board size by 1;
            clear_solution_board(mst);
            a++;
            generate_solution_board(mst, (start_size((mst->tetra_count * 4) + 1)));
            return (42);
        }
        if (mst->found_valid == NULL)
        {
            len = ft_strlen(mst->solved_board[0]);
            generate_new_board(mst, (int)ft_strlen(mst->solved_board[0]));
            map_board(mst);
            generate_solution_board(mst, start_size(mst->tetra_count * 4));
            reset_tetra_coord(mst, 0);
            print_res_board(mst);
            return (2);
        }
        else
        {
            if ((b = check_square(mst, 0, 0)) == 0)
                return (0);
            else if (b == 1)
            {
                map_rev(mst);
                ft_memdel((void **)mst->found_valid);
                mst->found_valid = NULL;
                ft_memdel((void **)mst->solved_board);
                //generate_solution_board(mst, start_size(mst->tetra_count * 4) + a);
                return (1);
            }
            else
            {
                ft_memdel((void **)mst->found_valid);
                mst->found_valid = NULL;
                return (0);
            }
            
        }
        
        return (2);
    }
    return (2);
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
        while ((row - rs) < tetra->height && (row) < (int)ft_strlen(mst->solved_board[0]))
        {
            while ((col - cs) < tetra->width && (col - cs) < (int)ft_strlen(mst->solved_board[0]))
            {
                if (mst->solved_board[row][col] == '.' && tetra->piece[(row - rs)][(col - cs)] != '.')
                {
                    good++;
                }
                else if (mst->solved_board[row][col] != '.' && tetra->piece[(row - rs)][(col - cs)] != '.')
                    return (0);
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

void    zero_out(t_board *mst)
{
    t_piece	*tmp;
	t_piece *head;
	int		i;

	head = mst->tmp_board;
	i = 0;
	if (head)
	{
		head->x = 0;
		head->y = 0;
		tmp = head->next;
		i++;
		while (tmp != NULL)
		{
			tmp->x = 0;
			tmp->y = 0;
			tmp = tmp->next;
			i++;
		}
	}
}

int     try_piece(t_board *mst, t_piece *tetra, int i)
{
    int a = 0;
    int b = 0;

    if (mst)
    {
        // If tetra == NULL; at end of list.
        if (void_tetra(mst, tetra, a, i) != 0)
            return (1);
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
            else if (b == 0)
            {
				tetra->x = 0;
				tetra->y = 0;
                i--;
                tetra = get_lst_index(mst, i);
                while (clear_piece(mst, tetra) == 0)
					tetra = get_lst_index(mst, --i);
                if (tetra->p_num == 0 && tetra->y >= (int)ft_strlen(mst->solved_board[0]))
                {
                    a++;
                    is_valid(mst, tetra, a);
                    return (1);
                }
                else
				{
					re_seat(mst, tetra);
                    try_piece(mst, tetra, i);
				}
				return (1);
            }
            else
            {
                is_valid(mst, tetra, a);
                return (0);
            }
            
            return (0);
        }
        
    }
    return (0);
}

int     void_tetra(t_board *mst, t_piece *tetra, int a, int i)
{
    int b;

    b = 0;
    if (!(tetra))
    {
        a++;
        if ((b = is_valid(mst, tetra, a)) == 2)
            return (0);
        if (b == 1)
        {
            i = 0;
            tetra = get_lst_index(mst, i);
            try_piece(mst, tetra, i);
            return (1);
        }
        return (1);
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

