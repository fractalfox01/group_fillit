/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhukova <ezhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:39:28 by ezhukova          #+#    #+#             */
/*   Updated: 2019/04/11 14:27:57 by ezhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char	*ft_get_line(char **st, char **line, int fd)
{
	char			*tail;
	int				i;

	i = (ft_strchr(st[fd], '\n')) - st[fd];
	line[0] = ft_strsub(st[fd], 0, (size_t)i);
	if (line[0] == NULL)
		return (NULL);
	tail = ft_strsub(st[fd], i + 1, ft_strlen(st[fd]) - (i + 1));
	if (tail == NULL)
		return (NULL);
	free(st[fd]);
	st[fd] = tail;
	return (st[fd]);
}

char	*clean_strjoin(char **st, int fd, char *buff)
{
	char			*tmp;

	tmp = st[fd];
	st[fd] = ft_strjoin(st[fd], buff);
	ft_strdel(&tmp);
	return (st[fd]);
}

int		check_result(int num, char **st, int fd, char **line)
{
	if (num < 0)
		return (-1);
	else if (num == 0 && (st[fd] == NULL || *st[fd] == '\0'))
		return (0);
	else
	{
		line[0] = ft_strdup(st[fd]);
		free(st[fd]);
		st[fd] = NULL;
		return (1);
	}
}

int		get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static char		*st[4068];
	int				num;

	if (fd > 4068 || fd < 0 || !line || (!st[fd] && !(st[fd] = ft_strnew(1))))
		return (-1);
	if (ft_strchr(st[fd], '\n') != NULL)
	{
		st[fd] = ft_get_line(st, line, fd);
		return (1);
	}
	while ((num = read(fd, (void *)buff, BUFF_SIZE)) > 0)
	{
		buff[num] = '\0';
		st[fd] = clean_strjoin(st, fd, buff);
		if (ft_strchr(st[fd], '\n') != NULL)
		{
			st[fd] = ft_get_line(st, line, fd);
			return (1);
		}
	}
	return (check_result(num, st, fd, line));
}
