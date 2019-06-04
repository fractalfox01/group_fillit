/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:35:26 by tvandivi          #+#    #+#             */
/*   Updated: 2019/06/04 12:29:52 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		read_file(char *file, t_board *main_board, int i, int flag)
{
	int		fd;
	int		a;
	t_piece	*tmp;
	char	buf[22];

	fd = open(file, O_RDONLY);
	ft_bzero(buf, 22);
	if (fd < 0)
		return (-1);
	if (fd > 0)
	{
		main_board->tmp_b = (t_piece *)malloc(sizeof(t_piece) * 1);
		tmp = main_board->tmp_b;
		while ((a = read(fd, buf, 21)) == 20 || a == 21)
		{
			if (!(tmp = r_h(tmp, buf, a, i++)))
				return (-1);
			if (a == 20)
				flag = 0;
		}
		if (a != 0 || flag)
			return (-1);
		return ((main_board->tet_count = i));
	}
	return (0);
}

void	print_mst_board(t_board *mst)
{
	int	i;

	i = 0;
	while (mst->slv_b[i] != NULL)
	{
		ft_putstr(mst->slv_b[i++]);
		ft_putchar('\n');
	}
}

void	fillit(char *file)
{
	t_board	*main_board;

	main_board = (t_board *)malloc(sizeof(t_board) * 1);
	if (file)
	{
		if (read_file(file, main_board, 0, 1) > 0)
		{
			f_init(main_board);
			if (main_board->tet_count < 27)
			{
				solve(main_board);
				print_mst_board(main_board);
			}
			else
				ft_putstr("error\n");
			operation_free(main_board);
			system("leaks fillit");
		}
		else
			ft_putstr("error\n");
	}
}
