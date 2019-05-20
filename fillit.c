/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:35:26 by tvandivi          #+#    #+#             */
/*   Updated: 2019/05/10 18:48:38 by tvandivi         ###   ########.fr       */
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
			else
				return (-1);
		}
		tmp->next = NULL;
	}
	if (!(!(main_board->tmp_board)))
		return (1);
	return (0);
}

int		fillit_init(t_board *main_board)
{
	set_dimensions(main_board);
	normalize(main_board);
	to_alpha(main_board);
	generate_solution_board(main_board, start_size(main_board->tetra_count * 4));
	return (1);
}

void	fillit(char *file)
{
	t_board	*main_board;

	main_board = (t_board *)malloc(sizeof(t_board) * 1);
	if (file && main_board)
	{
		if (read_file(file, main_board) == 1)
		{
			if (fillit_init(main_board))
			{
				// print_pieces(main_board);
				// ft_putchar('\n');
				// print_board(main_board);
				solve(main_board);
				ft_putstr("\nReturn\n");
				print_mst_board(main_board);
				ft_putstr("\n\n");
				print_res_board(main_board);
			}
		}
		else
			ft_putstr("What exactly are you trying to do?\n");
	}
}
