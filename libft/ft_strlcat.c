/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhukova <ezhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:42:02 by ezhukova          #+#    #+#             */
/*   Updated: 2019/03/08 16:42:13 by ezhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	int		s;
	size_t	d;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	s = 0;
	d = i;
	if (i > dstsize)
		return (j + dstsize);
	while ((src[s] != '\0') && (d < (dstsize - 1)))
	{
		dst[d] = src[s];
		d++;
		s++;
	}
	dst[d] = '\0';
	return (i + j);
}
