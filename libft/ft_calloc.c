/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:25:48 by jmeli             #+#    #+#             */
/*   Updated: 2024/10/25 14:20:02 by jmeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (!size || !nmemb)
		return (malloc(0));
	if (nmemb > ((size_t)(-1)) / size)
		return (0);
	ptr = malloc(nmemb * size);
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
