#include "fillit.h"

int		f_slv_b(char **slv_b, int size)
{
	int	i;

	i = 0;
	if (slv_b)
	{
		while (i < size)
			ft_strdel(&slv_b[i++]);
		free(slv_b);
		slv_b = NULL;
		return (1);
	}
	return (0);
}

int		f_piece(t_piece *lptr)
{
	int i;

	i = 0;
	if (!(lptr))
		return (0);
	while (i <= 3)
		ft_strdel(&lptr->piece[i++]);
	return (1);
}

void	operation_free(t_board *mst)
{
	t_piece *lptr;
	t_piece *tmp;
	int		i;
	int		len;

	i = 0;
	if (mst)
	{
		i = 0;
		lptr = mst->tmp_b;	
		while (i < mst->tet_count)
		{
			f_piece(lptr);
			if (lptr->sym_arr)
				ft_memdel((void **)&lptr->sym_arr);
			tmp = lptr;
			lptr = lptr->next;
			ft_memdel((void **)tmp);
			free(tmp);
			i++;
		}
		f_slv_b(mst->slv_b, mst->b_size);
		//lptr = NULL;
		free(mst);
		mst = NULL;
		return ;
	}
}
