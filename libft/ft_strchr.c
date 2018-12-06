/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:24:13 by alouisy-          #+#    #+#             */
/*   Updated: 2016/11/18 15:24:14 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char *)s;
	while (tmp[i])
	{
		if (tmp[i] == (char)c)
			return (tmp + i);
		if (tmp[i + 1] == (char)c)
			return (tmp + i + 1);
		i++;
	}
	return (NULL);
}
