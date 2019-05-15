/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinatesTests.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhukova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 15:03:59 by ezhukova          #+#    #+#             */
/*   Updated: 2019/05/09 15:04:05 by ezhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fillit.h"

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
 3 .##. */


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
	int result[8] = {0, 0, 0, 1, 0, 2, 1, 2};
	if (get_coordinates_test(piece, result) == 0)
	{
		printf("Test passed\n");
	}
	char piece2[4][4] =  {".##.", ".##.", "....", "...."};
	int result2[8] = {0, 0, 1, 0, 0, 1, 1, 1};
	if (get_coordinates_test(piece2, result2) == 0)
	{
		printf("Test passed\n");
	}
	char piece3[4][4] =  {"....", "..##", ".##.", "...."};
	int result3[8] = {0, 0, 1, 0, -1, 1, 0, 1};
	if (get_coordinates_test(piece3, result3) == 0)
	{
		printf("Test passed\n");
	}
	return (0);
}