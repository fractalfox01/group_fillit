/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhukova <ezhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 22:23:45 by tvandivi          #+#    #+#             */
/*   Updated: 2019/06/04 17:41:38 by ezhukova         ###   ########.fr       */
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

int			h1(int *arr, int i)
{
	arr[0] = 0;
	arr[1] = 0;
	return (i);
}

int			*get_coordinates(char **piece, int i, int j, int s_x)
{
	int			n;
	static int	arr[8];
	int			s_y;

	s_y = 0;
	n = 1;
	while (++i < 4)
	{
		while (++j < 4)
		{
			if (piece[i][j] == '#')
			{
				if (s_x == 5)
				{
					s_y = h1(arr, i);
					s_x = j;
					continue ;
				}
				arr[++n] = (j - s_x);
				arr[++n] = (i - s_y);
			}
		}
		j = -1;
	}
	return (arr);
}

t_piece		*add_lst_pce(t_piece *tmp, char *buf, int *arr, int i)
{
	tmp->next = (t_piece *)malloc(sizeof(t_piece) * 1);
	tmp->sym_arr = int8_arr_malloc(arr);
	tmp->p_num = i;
	tmp->col = 0;
	tmp->row = 0;
	tmp->height = 0;
	tmp->width = 0;
	tmp = tmp->next;
	ft_bzero(buf, ft_strlen(buf));
	return (tmp);
}

t_piece		*r_h(t_piece *tmp, char *buf, int a, int i)
{
	int *arr;

	if (((a == 20) || (a == 21)) && (verify_piece(tmp, buf, -1, -1) == 1))
		arr = get_coordinates(tmp->piece, -1, -1, 5);
	else
		return (NULL);
	tmp = add_lst_pce(tmp, buf, arr, i);
	return (tmp);
}
