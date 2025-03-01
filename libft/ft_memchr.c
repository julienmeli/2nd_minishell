/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:33:33 by jmeli             #+#    #+#             */
/*   Updated: 2024/10/28 10:33:37 by jmeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	a;
	size_t			i;

	ptr = (unsigned char *)s;
	a = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*(ptr + i) == a)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
