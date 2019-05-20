/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhukova <ezhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:20:00 by ezhukova          #+#    #+#             */
/*   Updated: 2019/03/08 16:57:41 by ezhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		counter;
	int		length;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	counter = 0;
	while (ft_findelem(s, c, &i) > 0)
		counter++;
	if (!(array = (char **)malloc(sizeof(char *) * counter + 1)))
		return (NULL);
	j = -1;
	i = 0;
	while (++j < counter)
	{
		length = ft_findelem(s, c, &i);
		if (!(array[j] = (char *)malloc(sizeof(char) * length + 1)))
			return (NULL);
		ft_memcopy(array[j], (void *)s, i - length, length);
	}
	array[j] = 0;
	return (array);
}
