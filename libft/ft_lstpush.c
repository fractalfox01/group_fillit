/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhukova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:32:58 by ezhukova          #+#    #+#             */
/*   Updated: 2019/03/06 14:33:27 by ezhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list *head, t_list *new)
{
	if (head)
	{
		while (head->next)
			head = head->next;
		head->next = new;
	}
	else
		head = new;
}
