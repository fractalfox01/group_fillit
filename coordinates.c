#include "fillit.h"
#include <stdio.h>

/*
   0123   x/j
 0 .##.
 1 .##.
 2 ....
 3 ....
 
   0123   x/j
 0 ....
 1 .#..
 2 .#..
 3 .##.

 y/i

 00100111
 01234567
 */





int	*get_coordinates(char piece[4][4])
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


char *resultToString(int result[8])
{
	char *stringResult;
	stringResult = malloc(1 * 17);
	stringResult[0] = '[';
	int i = -1;
	while (++i < 8)
	{
		stringResult[2 * i + 1] = '0' + result[i];
		stringResult[2 * i + 2] = ',';
	}
	stringResult[16] = ']';

	return (stringResult);
}

int get_coordinates_test(char piece[4][4], int result[8])
{
	int i = 0;
	int *ptr;
	ptr = get_coordinates(piece);
	while (i < 8)
	{
		//printf("%d\n", ptr[i]);
		if (result[i] != ptr[i])
		{
			printf("Test failed: current: %s expected: %s\n", resultToString(ptr), resultToString(result));
			return (1);
		}
		i++;
	}
	return (0);
}

int main()
{
	char piece[4][4] = {"....", ".#..", ".#..", ".##."};
	int result[8] = {0, 0, 0, 1, 0, 2, 1, 3};
	if (get_coordinates_test(piece, result) == 0){
		printf("Test passed\n");
	}
	char piece2[4][4] =  {".##.", ".##.", "....", "...."};
	int result2[8] = {0, 0, 1, 0, 0, 1, 1, 1};
	if (get_coordinates_test(piece2, result2) == 0){
		printf("Test passed\n");
	}
	return (0);
}


