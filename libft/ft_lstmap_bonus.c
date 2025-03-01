/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:54:36 by jmeli             #+#    #+#             */
/*   Updated: 2024/10/25 12:56:18 by jmeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*save;

	if (!lst || !f || !del)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
	save = new;
	while (lst->next)
	{
		new->next = ft_lstnew(f(lst->next->content));
		if (!new->next)
		{
			ft_lstclear(&save, del);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (save);
}
