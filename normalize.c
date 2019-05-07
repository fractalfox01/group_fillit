#include "fillit.h"

void	norm_left(t_piece *tmp)
{
	int	w;
	int	i;

	i = 0;
	w = tmp->width;
	if (w == 4)
		return ;
	if (w == 3)
		while (i++ < 1)
			shift_left(tmp);
	if (w == 2)
		while (i++ < 2)
			shift_left(tmp);
	if (w == 1)
		while (i++ < 3)
			shift_left(tmp);
}

void	norm_up(t_piece *tmp)
{
	int	h;
	int	i;

	i = 0;
	h = tmp->height;
	if (h == 4)
		return ;
	if (h == 3)
		while (i++ < 1)
			shift_up(tmp);
	if (h == 2)
		while (i++ < 2)
			shift_up(tmp);
	if (h == 1)
		while (i++ < 3)
			shift_up(tmp);
}

void	tetra_lstiter(t_piece *head, void (*f)(t_piece *tetra))
{
	t_piece	*tmp;

	if (head)
	{
		f(head);
		tmp = head->next;
		while (tmp)
		{
			f(tmp);
			tmp = tmp->next;
		}
	}
}

void	normalize(t_board *main_board)
{
	if (!(main_board->tmp_board))
		ft_putstr("Normalizer Error...\n");
	tetra_lstiter(main_board->tmp_board, norm_left);
	tetra_lstiter(main_board->tmp_board, norm_up);
}

// void	alf(t_piece *tetra)
// {

// }

// void	to_alpha(t_board *mst)
// {
// 	t_piece *tmp;
// 	int		i;
// 	int		r;
// 	int		c;

// 	i = 0;
// 	r = -1;
// 	c = -1;
// 	tmp = mst->tmp_board;
// 	while (i < (mst->tetra_count - 2))
// 	{
// 		tmp = get_lst_index(mst, i);
// 		while (++r < 4)
// 		{
// 			while (++c < 4)
// 			{
// 				if (tmp->piece[r][c] == '#')
// 					tmp->piece[r][c] == (i + 'A');
// 			}
// 			c = 0;
// 		}
// 	}
// }