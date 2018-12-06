/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:08:48 by alouisy-          #+#    #+#             */
/*   Updated: 2016/11/22 15:08:50 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char	*ft_putnbrstr(int n, int len, char *str)
{
	int		i;

	i = 0;
	if (n < 0)
		str[i++] = '-';
	n = (n < 0) ? (n * -1) : n;
	while (len - 1 >= i)
	{
		if (n > 9)
		{
			str[len - 1] = (n % 10) + '0';
			n /= 10;
		}
		else
			str[len - 1] = n + '0';
		len--;
	}
	return (str);
}

static int	ft_howlong(int n)
{
	int		neg;
	int		i;

	i = 1;
	if (n == -2147483648)
		n++;
	neg = (n < 0) ? 1 : 0;
	n = (n < 0) ? (n * -1) : n;
	while ((size_t)n >= ft_power(10, (size_t)i))
		i++;
	return (i + neg);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_howlong(n);
	str = ft_strnew(len);
	if (str)
	{
		if (n == -2147483648)
			str = ft_strcpy(str, "-2147483648");
		else
			str = ft_putnbrstr(n, len, str);
	}
	return (str);
}
