/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 22:23:45 by tvandivi          #+#    #+#             */
/*   Updated: 2019/04/30 17:27:35 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece	*add_lst_piece(t_piece *tmp, char *buf, int a)
{
	t_piece	*nxt;
	int i;

	i = 0;
	tmp->next = (t_piece *)malloc(sizeof(t_piece) * 1);
	nxt = tmp->next;
	tmp->piece = &*ft_strsplit(buf, '\n');
	tmp->p_num = i++;
	tmp = nxt;  // the same as tmp = tmp->next
	ft_bzero(buf, a);
	return (tmp);
}

