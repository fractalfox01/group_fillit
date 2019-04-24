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

char	**error(void)
{
	char	**bad_board;

	bad_board = ft_strsplit("invalid", ' ');
	return (bad_board);
}

void	set_length(t_board *main_board)
{
	t_piece	*tmp;
	t_piece	*nxt;
	int		i;

	i = -1;
	tmp = main_board->tmp_board;
	while (tmp)
	{
		nxt = tmp->next;
		i++;
		tmp = nxt;
	}
	main_board->tetra_count = i;
}

t_piece	*add_lst_piece(t_piece *tmp, char *buf, int i, int a)
{
	t_piece	*nxt;

	tmp->next = (t_piece *)malloc(sizeof(t_piece) * 1);
	nxt = tmp->next;
	tmp->piece = &*ft_strsplit(buf, '\n');
	tmp->p_num = i++;
	tmp = nxt;
	ft_bzero(buf, a);
	return (tmp);
}

void	print_board(t_board *main_board)
{
	int	i;

	i = 0;
	while (i < main_board->tetra_count)
	{
		ft_putstr(main_board->solved_board[i++]);
	}
}

void	print_pieces(t_board *mst)
{
	int		i;
	t_piece	*tmp;
	t_piece	*nxt;

	i = 0;
	tmp = mst->tmp_board;
	while (tmp)
	{
		if (!(tmp->piece))
			break ;
		nxt = tmp->next;
		while (i < 4)
		{
			ft_putstr(tmp->piece[i++]);
			ft_putchar('\n');
		}
		ft_putnbr(tmp->p_num);
		ft_putchar('\n');
		i = 0;
		tmp = nxt;
	}
}
