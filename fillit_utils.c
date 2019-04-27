/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 22:23:45 by tvandivi          #+#    #+#             */
/*   Updated: 2019/04/24 10:11:33 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece	*add_lst_piece(t_piece *tmp, char *buf, int a)
{
	int i;

	i = 0;
	tmp->next = (t_piece *)malloc(sizeof(t_piece) * 1);
	tmp->piece = ft_strsplit(buf, '\n');
	tmp->p_num = i++;
	//printf("%c\n", tmp->piece[0][2]);
	tmp = tmp->next;
	ft_bzero(buf, a);
	return (tmp);
}

