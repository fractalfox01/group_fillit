#include "fillit.h"
#include <stdio.h>


##..
....
....
....

x = 0
y = 0

   0123   x/j
 0 ....
 1 .#..
 2 .#..
 3 .##.

0,0,0,1,0,2,1,2

char		**map_piece(int *arr, int x, int y, char **board)
{
	int i;
	int arr_x;
	int arr_y;

	i = 0;
	arr_x = 0;
	arr_y = 1;
	while (i < 7)
	{
		// already checked if empty
		if (board[y][x] == '.')
		{
			board[y][x] = '#';
		}
		
		while (arr_x <= 6 || arr_y <= 7)
		{
			if (arr[arr_x = arr_x + 2] != 0)
			{
				board[y][x++] = '#'
			}
			if (arr[arr_y = arr_y + 2] != 0)
			{
				board[y++][x] = '#'
			}
		}


		while (arr_x <= 6)
		{
			if (arr[arr_x] != 0)
			{
				board[y][x++] = '#';
			}
			arr_x = arr_x + 2;
		}



		i++;
	}
}	





int			*get_coordinates(char piece[4][4])
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
