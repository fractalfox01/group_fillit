/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 22:23:45 by tvandivi          #+#    #+#             */
/*   Updated: 2019/05/21 12:50:13 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	*int8_arr_malloc(int *arr)
{
	int	*tab;
	int	i = 0;

	tab = (int *)malloc(sizeof(int) * 8);
	while (i < 8)
	{
		tab[i] = arr[i];
		i++;
	}
	return (tab);
}

t_piece	*add_lst_piece(t_piece *tmp, char *buf, int *arr, int a, int i)
{
	tmp->next = (t_piece *)malloc(sizeof(t_piece) * 1);
	tmp->piece = ft_strsplit(buf, '\n');
	tmp->sym_arr = int8_arr_malloc(arr);
	tmp->p_num = i;
	tmp->col = 0;
	tmp->row = 0;
	tmp->height = 0;
	tmp->width = 0;
	tmp = tmp->next;
	ft_bzero(buf, a);
	return (tmp);
}

