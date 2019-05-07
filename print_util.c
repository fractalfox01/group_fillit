#include "fillit.h"

void	put_piece(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}

void	visualizer(t_piece *head, void (*f)(char **tab))
{
	t_piece	*tmp;

	if (head)
	{
		f(head->piece);
		ft_putstr("width: ");
		ft_putnbr(head->width);
		ft_putstr("\nheight: ");
		ft_putnbr(head->height);
        tmp = head->next;
        while (tmp->piece)
		{
			ft_putchar('\n');
			f(tmp->piece);
			ft_putstr("width: ");
			ft_putnbr(tmp->width);
			ft_putstr("\nheight: ");
			ft_putnbr(tmp->height);
			tmp = tmp->next;
		}
	}
}

void	print_pieces(t_board *mst)
{
	t_piece *tmp;
	int		i;
	int		k;

	tmp = mst->tmp_board;
	i = 0;
	k = 0;
	while (tmp)
	{
		if (tmp->piece)
		{
			while (k < 4)
			{
				ft_putstr(tmp->piece[k++]);
				ft_putchar('\n');
			}
			ft_putchar('\n');
			k = 0;
		}
		tmp = tmp->next;
	}
}

void	print_board(t_board *main_board)
{
	int		i;
	
	i = 0;
	while (main_board->solved_board[i] != NULL)
	{
		ft_putstr(main_board->solved_board[i++]);
		ft_putchar('\n');
	}
}