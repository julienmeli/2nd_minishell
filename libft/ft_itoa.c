/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:46:19 by jmeli             #+#    #+#             */
/*   Updated: 2024/10/24 15:06:31 by jmeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_len(int n)
{
	int	len;

	if (n == -2147483648)
		return (10);
	if (n == 0)
		return (1);
	len = 0;
	n = (n > 0) * n + (n < 0) * -n;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static int	ft_power(int n, int power)
{
	int	i;
	int	result;

	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	i = 0;
	result = 1;
	while (i < power)
	{
		result = result * n;
		i++;
	}
	return (result);
}

static char	*ft_exceptions(char *num, int n)
{
	if (n == -2147483648)
	{
		num[0] = '-';
		num[1] = '2';
		num[2] = '1';
		num[3] = '4';
		num[4] = '7';
		num[5] = '4';
		num[6] = '8';
		num[7] = '3';
		num[8] = '6';
		num[9] = '4';
		num[10] = '8';
		num[11] = '\0';
	}
	if (n == 0)
	{
		num[0] = '0';
		num[1] = '\0';
	}
	return (num);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		len;
	int		i;

	len = ft_len(n) + (n < 0) * 1;
	num = (char *)malloc((len + 1) * sizeof(char));
	if (num == 0)
		return (NULL);
	if (n == 0 || n == -2147483648)
		return (ft_exceptions(num, n));
	i = 0;
	if (-2147483648 < n && n < 0)
	{
		n = -n;
		num[0] = '-';
		i++;
	}
	while (i < len)
	{
		num[i] = (n / (ft_power(10, len - 1 - i)) + '0');
		n = n % (ft_power(10, len - 1 - i));
		i++;
	}
	num[i] = '\0';
	return (num);
}
