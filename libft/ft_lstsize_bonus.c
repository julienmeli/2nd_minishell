/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 08:05:10 by jmeli             #+#    #+#             */
/*   Updated: 2024/10/25 14:01:10 by jmeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*ptr;
	int		count;

	ptr = lst;
	count = 0;
	while (ptr)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}
