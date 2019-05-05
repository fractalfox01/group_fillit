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
	visualizer(mst->tmp_board, put_piece);
}
