/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhukova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:53:24 by ezhukova          #+#    #+#             */
/*   Updated: 2019/03/08 16:05:23 by ezhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int num;

	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
		return ;
	}
	num = n;
	if (num < 0)
	{
		ft_putchar('-');
		num = num * (-1);
	}
	if (num < 10)
	{
		ft_putchar('0' + num);
	}
	else
	{
		ft_putnbr(num / 10);
		ft_putchar('0' + (num % 10));
	}
}
