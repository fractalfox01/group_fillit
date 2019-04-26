/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcopy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhukova <ezhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:20:00 by ezhukova          #+#    #+#             */
/*   Updated: 2019/03/11 15:12:07 by ezhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcopy(void *dst, void *src, int start, int len)
{
	int				i;
	unsigned char	*dest;
	unsigned char	*source;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = 0;
	while (i < len)
	{
		dest[i] = source[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dst);
}
