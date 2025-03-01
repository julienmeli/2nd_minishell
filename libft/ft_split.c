/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:02:50 by jmeli             #+#    #+#             */
/*   Updated: 2024/10/25 14:14:37 by jmeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	trigger;
	int	count;

	trigger = 0;
	count = 0;
	while (*s)
	{
		if ((*s != c) && trigger == 0)
		{
			trigger = 1;
			count++;
		}
		if (*s == c)
			trigger = 0;
		s++;
	}
	return (count);
}

static int	ft_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && (s[len] != c))
		len++;
	return (len);
}

static char	*ft_strdup_len(char const *s, int len)
{
	char	*string;
	int		j;

	string = (char *)malloc((len + 1) * sizeof(char const));
	if (string == 0)
		return (NULL);
	j = 0;
	while (j < len)
	{
		string[j] = s[j];
		j++;
	}
	string[j] = '\0';
	return (string);
}

static char	**ft_free(char **array, int i)
{
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		len;

	array = (char **)malloc((ft_count(s, c) + 1) * sizeof(*array));
	if (array == 0)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = ft_len(s, c);
			array[i] = ft_strdup_len(s, len);
			if (array[i] == NULL)
				return (ft_free(array, i));
			i++;
			s = s + len;
		}
		else
			s++;
	}
	array[i] = NULL;
	return (array);
}
