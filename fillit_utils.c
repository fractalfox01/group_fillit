/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 22:23:45 by tvandivi          #+#    #+#             */
/*   Updated: 2019/05/05 11:06:14 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece	*add_lst_piece(t_piece *tmp, char *buf, int a, int i)
{
	tmp->next = (t_piece *)malloc(sizeof(t_piece) * 1);
	tmp->piece = ft_strsplit(buf, '\n');
	tmp->p_num = i;
	tmp = tmp->next;
	ft_bzero(buf, a);
	return (tmp);
}

int		get_width(char **tab, int row, int col)
{
	int		width;
	char	*test;

	width = 0;
	test = ft_strdup("....");
	if (tab == NULL)
		return (0);
	while (row < 4)
	{
		while (col < 4)
		{
			if (tab[row][col] == '#')
			{
				if (test[col] == '.')
					test[col] = '#';
			}
			col++;
		}
		col = 0;
		row++;
	}
	col = 0;
	while (test[col] != '\0')
		if (test[col++] == '#')
			width++;
	return (width);
}

int		get_height(char **tab, int row, int col)
{
	int		height;
	char	*test;

	height = 0;
	test = ft_strdup("....");
	if (tab == NULL)
		return (0);
	while (row < 4)
	{
		while (col < 4)
		{
			if (tab[row][col] == '#')
			{
				if (test[row] == '.')
					test[row] = '#';
			}
			col++;
		}
		col = 0;
		row++;
	}
	col = 0;
	while (test[col] != '\0')
		if (test[col++] == '#')
			height++;
	return (height);
}

void	set_dimensions(t_board *main_board)
{
	t_piece	*tmp;
	t_piece *head;

	head = main_board->tmp_board;
	if (head)
	{
		head->width = get_width(head->piece, 0, 0);
		head->height = get_height(head->piece, 0, 0);
		tmp = head->next;
		while (tmp)
		{
			tmp->width = get_width(tmp->piece, 0, 0);
			tmp->height = get_height(tmp->piece, 0, 0);
			tmp = tmp->next;
		}
	}
}
