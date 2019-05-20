/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhukova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:10:39 by ezhukova          #+#    #+#             */
/*   Updated: 2019/03/08 16:57:02 by ezhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *ptr;

	ptr = NULL;
	while (*str)
	{
		if (*str == c)
			ptr = ((char *)str);
		str++;
	}
	if (c == 0)
		return ((char *)str);
	return (ptr);
}
