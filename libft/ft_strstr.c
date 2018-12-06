/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 16:00:47 by alouisy-          #+#    #+#             */
/*   Updated: 2016/11/18 16:00:51 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_strcheck(int start, char *big, char *little)
{
	int		i;

	i = 0;
	while (little[i])
	{
		if (little[i] != big[start])
			return (0);
		start++;
		i++;
	}
	return (1);
}

char		*ft_strstr(const char *big, const char *little)
{
	char	*xl;
	char	*xs;
	int		i;

	xl = (char *)big;
	xs = (char *)little;
	i = 0;
	if (!*xs)
		return (xl);
	while (xl[i])
	{
		if (xs[0] == xl[i] && ft_strcheck(i, xl, xs))
			return (xl + i);
		i++;
	}
	return (NULL);
}
