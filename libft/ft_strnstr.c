/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhukova <ezhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:26:04 by ezhukova          #+#    #+#             */
/*   Updated: 2019/03/08 16:55:23 by ezhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, size_t len)
{
	size_t	s;
	int		f;
	int		remember;

	s = -1;
	f = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[++s] != '\0' && s < len)
	{
		if (str[s] == to_find[f])
		{
			remember = s;
			while (str[s] == to_find[f])
			{
				if (to_find[f + 1] == '\0' && s < len)
					return (&str[remember]);
				s++;
				f++;
			}
			s = remember;
			f = 0;
		}
	}
	return (0);
}
