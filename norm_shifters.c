#include "fillit.h"

void	shift_left(t_piece *tmp)
{
	int	r;
	int	c;
	int	i;

	r = 0;
	c = 0;
	i = 0;
	while (i < 4)
		if (tmp->piece[i++][0] == '#')
			return ;
	while (r < 4)
	{
		while (c < 4)
		{
			if (tmp->piece[r][c] == '#' && c != 0)
			{
				tmp->piece[r][c - 1] = '#';
				tmp->piece[r][c] = '.';
			}
			c++;
		}
		c = 0;
		r++;
	}
}

void	shift_up(t_piece *tmp)
{
	int	r;
	int	c;
	int	i;

	r = 1;
	c = 0;
	i = 0;
	while (i < 4)
		if (tmp->piece[0][i++] == '#')
			return ;
	while (r < 4)
	{
		while (c < 4)
		{
			if (tmp->piece[r][c] == '#' && r != 0)
			{
				tmp->piece[r - 1][c] = '#';
				tmp->piece[r][c] = '.';
			}
			c++;
		}
		c = 0;
		r++;
	}
}
