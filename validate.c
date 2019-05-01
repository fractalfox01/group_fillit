/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 22:19:12 by tvandivi          #+#    #+#             */
/*   Updated: 2019/04/30 17:28:30 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	c_chk(int k, int i, int j, char **block)
{
	int	count;

	count = 0;
	if (k % 4 != 0)
	{
		k++;
		if (is_valid_char(block[i + 1][j]) == 2)
			count++;
	}
	if (i >= 0 && i % 4 != 3)
	{
		if (is_valid_char(block[i - 1][j]) == 2)
			count++;
	}
	return (count);
}

int	check_vertical(int i, int j, char **block)
{
	int	count;
	int	b;
	int	k;
	int dir;

	count = 0;
	b = 0;
	k = 0;
	if (i % 4 == 0 || i % 4 == 3)
	{
		if (i % 4 == 0)
			dir = 1;
		else
			dir = -1;
		b = i + 4;
		i += dir;
		if (is_valid_char(block[i][j]) == 2 && i < b)
			count++;
		return (count);
	}
	k = i;
	return (c_chk(k, i, j, block));
}

int	check_horizonal(int i, int j, char **block)
{
	int count;

	count = 0;
	if (j == 0)
	{
		if (is_valid_char(block[i][j + 1]) == 2)
			return (1);
		else
			return (0);
	}
	if (j == 3)
	{
		if (is_valid_char(block[i][j - 1]) == 2)
			return (1);
		else
			return (0);
	}
	if (is_valid_char(block[i][j - 1]) == 2)
		count++;
	if (is_valid_char(block[i][j + 1]) == 2)
		count++;
	return (count);
}

int	verify_tetra(char **tab, int i, int j, int hash)
{
	int	count;

	count = 0;
	while (++i < 4 && tab)
	{
		while (++j < 4)
		{
			if (tab[i][j] == '.' || tab[i][j] == '#')
			{
				if (tab[i][j] == '#')
				{
					count += check_vertical(i, j, tab);
					count += check_horizonal(i, j, tab);
					hash++;
				}
			}
			else
				return (2);
		}
		j = -1;
	}
	if ((count == 6 || count == 8) && hash == 4)
		return (1);
	return (0);
}

int	verify_file(t_board *main_board)
{
	t_piece *tmp;
	t_piece *nxt;
	int		a;
	int		i;

	i = 2;
	tmp = main_board->tmp_board;
	while (tmp)
	{
		nxt = tmp->next;
		if ((a = verify_tetra(tmp->piece, -1, -1, 0)) == 0 || a == 2)
		{
			if (tmp->p_num != (i - 2) && a != 2)
				return (0);
			else
				return (i);
		}
		i++;
		tmp = nxt;
	}
	return (1);
}
