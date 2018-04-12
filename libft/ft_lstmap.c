/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:43:35 by ireva             #+#    #+#             */
/*   Updated: 2016/12/07 17:36:21 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	freedom(t_list **alst)
{
	if (!(*alst))
		return ;
	if ((*alst)->next)
	{
		freedom(&(*alst)->next);
		free(*alst);
		*alst = NULL;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;

	new = NULL;
	if (lst && f)
	{
		if (lst->next)
			new = ft_lstmap(lst->next, f);
		tmp = (f)(lst);
		if (!tmp)
			freedom(&new);
		tmp->next = new;
		return (tmp);
	}
	return (NULL);
}
