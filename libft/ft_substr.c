/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 09:31:52 by jmeli             #+#    #+#             */
/*   Updated: 2024/10/24 15:02:49 by jmeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_big_start(void)
{
	char	*dest;

	dest = malloc(1);
	if (dest == NULL)
		return (NULL);
	dest[0] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*dest;

	if (!s)
		return (NULL);
	if (len >= (unsigned int)ft_strlen(s))
		len = (unsigned int)ft_strlen(s) - start;
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_big_start());
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = ((char *)s)[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
