/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhukova <ezhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 13:02:00 by ezhukova          #+#    #+#             */
/*   Updated: 2019/03/08 17:00:46 by ezhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*str;
	int			i;
	int			j;
	int			end;

	i = 0;
	if (!s)
		return (NULL);
	end = (int)ft_strlen(s) - 1;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while (end >= 0 && (s[end] == ' ' || s[end] == '\n' || s[end] == '\t'))
		end--;
	str = (char *)malloc(sizeof(char) * (end < i ? 1 : (end - i + 2)));
	if (!str)
		return (NULL);
	j = 0;
	while (i + j <= end)
	{
		str[j] = s[i + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
