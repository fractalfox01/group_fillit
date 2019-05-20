/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhukova <ezhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:39:45 by ezhukova          #+#    #+#             */
/*   Updated: 2019/04/11 14:34:28 by ezhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

char		*ft_get_line(char **store, char **line, int fd);
char		*clean_strjoin(char **store, int fd, char *buff);
int			check_result(int num, char **store, int fd, char **line);
int			get_next_line(const int fd, char **line);

#endif
