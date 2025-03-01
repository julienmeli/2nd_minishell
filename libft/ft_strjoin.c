/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 10:07:03 by jmeli             #+#    #+#             */
/*   Updated: 2025/02/25 13:03:52 by jmeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	dest = (char *)malloc(len * sizeof(char));
	if (dest == 0)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
