/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 19:15:40 by alouisy-          #+#    #+#             */
/*   Updated: 2016/11/18 19:15:42 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_strcheck(size_t start, size_t len, char *big, char *little)
{
	size_t	i;

	i = 0;
	while (little[i] && i < len)
	{
		if (little[i] != big[start])
			return (0);
		start++;
		i++;
	}
	if (little[i] != '\0')
		return (0);
	return (1);
}

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*xl;
	char	*xs;
	size_t	i;

	xl = (char *)big;
	xs = (char *)little;
	i = 0;
	if (!*xs)
		return (xl);
	while (xl[i] && i < len)
	{
		if (xs[0] == xl[i] && ft_strcheck(i, len - i, xl, xs))
			return (xl + i);
		i++;
	}
	return (NULL);
}
