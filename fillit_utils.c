/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 22:23:45 by tvandivi          #+#    #+#             */
/*   Updated: 2019/05/07 19:32:49 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece	*add_lst_piece(t_piece *tmp, char *buf, int a, int i)
{
	if (!(buf))
	{
		tmp = NULL;
		return (tmp);
	}
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
	int		i;

	head = main_board->tmp_board;
	i = 0;
	if (head)
	{
		head->width = get_width(head->piece, 0, 0);
		head->height = get_height(head->piece, 0, 0);
		head->x = 0;
		head->y = 0;
		tmp = head->next;
		i++;
		while (tmp != NULL)
		{
			tmp->width = get_width(tmp->piece, 0, 0);
			tmp->height = get_height(tmp->piece, 0, 0);
			tmp->x = 0;
			tmp->y = 0;
			tmp = tmp->next;
			i++;
		}
	}
	main_board->tetra_count = i;
}

t_piece		*get_lst_index(t_board *main_board, int index)
{
	t_piece *tmp;
	int		max_index;

	tmp = main_board->tmp_board;
	max_index = main_board->tetra_count;
	if (!(tmp) || index > max_index)
		return (NULL);
	if (index == max_index)
		return (tmp);
	while (tmp)
	{
		if (tmp->p_num == index)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}