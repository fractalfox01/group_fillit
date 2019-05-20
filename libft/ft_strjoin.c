/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhukova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:56:47 by ezhukova          #+#    #+#             */
/*   Updated: 2019/03/08 17:38:00 by ezhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char				*str;
	unsigned int		i;
	unsigned int		j;
	size_t				len1;
	size_t				len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = -1;
	j = len1;
	if (!(str = (char *)malloc(sizeof(char) * (len1 + len2) + 1)))
		return (NULL);
	while (s1[++i])
	{
		str[i] = s1[i];
	}
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i++];
	}
	str[len1 + len2] = '\0';
	return (str);
}
