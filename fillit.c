/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:35:26 by tvandivi          #+#    #+#             */
/*   Updated: 2019/04/24 11:35:18 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		read_file(char *file, t_board *main_board)
{
	int		fd;
	int		i;
	int		a;
	t_piece	*tmp;
	char	buf[22];

	i = 0;
	fd = open(file, O_RDONLY);
	ft_bzero(buf, 22);
	if (fd < 0)
		return (-1);
	if (fd > 0)
	{
		main_board->tmp_board = (t_piece *)malloc(sizeof(t_piece) * 1);
		tmp = main_board->tmp_board;
		while ((a = read(fd, buf, 21)) == 20 || a == 21)
		{
			if ((a == 20) || ((a == 21) && (buf[20] == '\n')))
			{
				if (verify_piece(buf) == 1)
				{
					tmp = add_lst_piece(tmp, buf, a, i);
					i++;
				}
				else 
					return (-1);
			}
		}
	}
	if (!(!(main_board->tmp_board)))
		return (1);
	return (0);
}


void	fillit(char *file)
{
	t_board	*main_board;

	main_board = (t_board *)malloc(sizeof(t_board) * 1);
	if (file)
	{
		if (read_file(file, main_board) == 1)
		{
			printf("Reading file");
		}
		else
			ft_putstr("What exactly are you trying to do?\n");
	}
}
