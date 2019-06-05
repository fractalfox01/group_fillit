/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhukova <ezhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 22:19:12 by tvandivi          #+#    #+#             */
/*   Updated: 2019/06/04 18:16:54 by ezhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		check_vertical(int i, int j, char **tab)
{
	int	count;

	count = 0;
	if (i == 0)
	{
		if (tab[i + 1][j] == '#')
			count++;
	}
	if (i == 3)
	{
		if (tab[i - 1][j] == '#')
			count++;
	}
	if (i == 1 || i == 2)
	{
		if (tab[i + 1][j] == '#')
			count++;
		if (tab[i - 1][j] == '#')
			count++;
	}
	return (count);
}

int		check_horizonal(int i, int j, char **tab)
{
	int	count;

	count = 0;
	if (j == 0)
	{
		if (tab[i][j + 1] == '#')
			count++;
	}
	if (j == 3)
	{
		if (tab[i][j - 1] == '#')
			count++;
	}
	if (j == 1 || j == 2)
	{
		if (tab[i][j - 1] == '#')
			count++;
		if (tab[i][j + 1] == '#')
			count++;
	}
	return (count);
}

/*int		count_hashes(char **tab, int i, int j, int *count)
{
	int hash;

	hash = 0;
	if (tab[i][j] == '#')
	{
		*count += check_horizonal(i, j, tab);
		*count += check_vertical(i, j, tab);
		hash++;
	}
	return (hash);
}*/

int		verify_piece(t_piece *piece, char *buf, int i, int j)
{
	char	**tab;
	int		count;
	int		hash;

	hash = 0;
	count = 0;
	if (buf[4] != '\n' || buf[9] != '\n' || buf[14] != '\n' || buf[19] != '\n')
		return (-1);
	tab = ft_strsplit(buf, '\n');
	piece->piece = &*tab;
	while (++i < 4)
	{
		while (++j < 4)
		{
			if (tab[i][j] == '.' || tab[i][j] == '#')
			{
				//hash = count_hashes(tab, i, j, &count);
				if (tab[i][j] == '#')
				{
					count += check_horizonal(i, j, tab);
					count += check_vertical(i, j, tab);
					hash++;
				}
			}
			else
				return (-1);
		}
		j = -1;
	}
	if ((count == 6 || count == 8) && hash == 4)
		return (1);
	return (0);
}
