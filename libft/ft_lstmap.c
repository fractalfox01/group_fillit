/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhukova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 11:25:56 by ezhukova          #+#    #+#             */
/*   Updated: 2019/03/11 15:12:32 by ezhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newheader;
	t_list	*newelem;

	if (!lst || !f)
		return (NULL);
	newheader = (*f)(lst);
	newelem = newheader;
	while (lst->next)
	{
		lst = lst->next;
		newelem->next = (*f)(lst);
		newelem = newelem->next;
	}
	newelem->next = NULL;
	return (newheader);
}
