/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhukova <ezhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 12:08:19 by ezhukova          #+#    #+#             */
/*   Updated: 2019/03/08 11:10:09 by ezhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!(s1 && s2))
		return (0);
	while (*s1 == *s2 && i < n && *s1)
	{
		i++;
		s1++;
		s2++;
	}
	if ((*s1 == '\0' && *s2 == '\0') || i == n)
		return (1);
	else
		return (0);
}
