#include "fillit.h"
#include <stdio.h>

typedef char t_b[4][4];

void	map_piece(int *arr, int x, int y, t_b *board)
{
	int i;
	int arr_x;
	int arr_y;
	int new_x;
	int new_y;

	i = 0;
	arr_x = 0;
	arr_y = 1;
	new_x = x;
	new_y = y;

	(*board)[y][x] = '#';

	while (arr_x <= 6 || arr_y <= 7)
	{
		if (arr[arr_y] != 0)
		{
			new_y = new_y + arr[arr_y];
			if (arr[arr_x] != 0)
			{
				new_x = new_x + arr[arr_x];
			}
		}
		(*board)[new_y][new_x] = '#';
		arr_x = arr_x + 2;
		arr_y = arr_y + 2;
	}
}

// int main()
// {
// 	t_b board = {"....", "....", "....", "...."};
// 	int x = 0;
// 	int y = 0;
// 	int arr[8] = {0, 0, 0, 1, 0, 2, 1, 2};
// 	int *ptr = arr;
// 	int i = -1;
// 	int j = -1;

// 	map_piece(ptr, x, y, &board);
// 	while (j++ < 4)
// 	{
// 		while (i++ < 4)
// 		{
// 			printf("%c", board[j][i]);
// 		}
// 		printf("\n");
// 		i = -1;
// 	}
// 	return (0);
// }


int			*get_coordinates(char **piece)
{
	int i;
	int j;
	int n;
	static int	arr[8];
	int	x_start;
	int y_start;

	j = -1;
	i = -1;
	x_start = 5;
	y_start = 0;
	n = 1;
	while (++i < 4)
	{
		while (++j < 4)
		{
			if (piece[i][j] == '#')
			{
				if (x_start == 5)
				{
					arr[0] = 0;
					arr[1] = 0;
					x_start = j;
					y_start = i;
				}
				else
				{
					arr[++n] = (j - x_start);
					arr[++n] = (i - y_start);
				}
			}
		}
		j = -1;
	}
	return (arr);
}
