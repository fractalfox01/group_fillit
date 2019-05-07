#include "fillit.h"

// void	alf(t_piece *tetra)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	while (i < 4)
// 	{
// 		while (j < 4)
// 		{
// 			if (tetra->piece[i][j] == '#')
// 				tetra->piece[i][j] = tetra->p_num + 65;
// 			j++;
// 		}
// 		j = 0;
// 		i++;
// 	}
// }

// void	to_alpha(t_board *main_board, void (*f)(t_piece *elem))
// {
// 	t_piece	*tmp;
// 	t_piece	*head;

// 	head = main_board->tmp_board;
// 	if (head)
// 	{
// 		f(head);
// 		tmp = head->next;
// 		while (tmp)
// 		{
// 			if (tmp->piece == NULL)
// 				break ;
// 			f(tmp);
// 			tmp = tmp->next;
// 		}
// 	}
// }

// void	alf(t_piece *tetra)
// {

// }

// void	alf(t_piece *tetra)
// {

// }

void	to_alpha(t_board *mst)
{
	t_piece *tmp;
	int		i;
	int		r;
	int		c;

	i = 0;
	r = -1;
	c = -1;
	tmp = mst->tmp_board;
	while (i < (mst->tetra_count - 1))
	{
		tmp = get_lst_index(mst, i);
		while (++r < 4)
		{
			while (++c < 4)
			{
				if (tmp->piece[r][c] == '#')
					tmp->piece[r][c] = (i + 'A');
			}
			c = -1;
		}
		r = -1;
		i++;
	}
}
