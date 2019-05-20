/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 22:23:45 by tvandivi          #+#    #+#             */
/*   Updated: 2019/05/19 13:52:25 by tvandivi         ###   ########.fr       */
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
	tmp = tmp->next;
	ft_bzero(buf, a);
	return (tmp);
}

