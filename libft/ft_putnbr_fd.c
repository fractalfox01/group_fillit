/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhukova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:53:26 by ezhukova          #+#    #+#             */
/*   Updated: 2019/03/08 16:04:54 by ezhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int num;

	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
		return ;
	}
	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = num * (-1);
	}
	if (num < 10)
	{
		ft_putchar_fd('0' + num, fd);
	}
	else
	{
		ft_putnbr_fd((num / 10), fd);
		ft_putchar_fd(('0' + (num % 10)), fd);
	}
}
