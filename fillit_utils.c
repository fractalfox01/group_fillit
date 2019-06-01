/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 22:23:45 by tvandivi          #+#    #+#             */
/*   Updated: 2019/06/01 16:10:04 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			*int8_arr_malloc(int *arr)
{
	int	*tab;
	int	i;

	i = 0;
	tab = (int *)malloc(sizeof(int) * 8);
	while (i < 8)
	{
		tab[i] = arr[i];
		i++;
	}
	return (tab);
}

int			*get_coordinates(char **piece, int i, int j)
{
	int			n;
	static int	arr[8];
	int			x_start;
	int			y_start;

	j = -1;
	i = -1;
	x_start = 5;
	y_start = 0;
	n = 1;
	while (++i < 4)
	{
		while (++j < 4)
		{
			if (piece[i][j] == '#')
			{
				if (x_start == 5)
				{
					arr[0] = 0;
					arr[1] = 0;
					x_start = j;
					y_start = i;
				}
				else
				{
					arr[++n] = (j - x_start);
					arr[++n] = (i - y_start);
				}
			}
		}
		j = -1;
	}
	return (arr);
}

t_piece		*add_lst_piece(t_piece *tmp, char *buf, int *arr, int a, int i)
{
	tmp->next = (t_piece *)malloc(sizeof(t_piece) * 1);
	tmp->sym_arr = arr;
	tmp->p_num = i;
	tmp->col = 0;
	tmp->row = 0;
	tmp->height = 0;
	tmp->width = 0;
	tmp = tmp->next;
	ft_bzero(buf, a);
	return (tmp);
}
