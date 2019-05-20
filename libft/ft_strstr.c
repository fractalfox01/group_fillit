/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhukova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:26:04 by ezhukova          #+#    #+#             */
/*   Updated: 2018/10/30 16:05:38 by ezhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	int s;
	int f;
	int remember;

	s = -1;
	f = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[++s] != '\0')
	{
		if (str[s] == to_find[f])
		{
			remember = s;
			while (str[s] == to_find[f])
			{
				if (to_find[f + 1] == '\0')
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
