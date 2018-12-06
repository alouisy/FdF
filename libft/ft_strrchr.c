/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:24:18 by alouisy-          #+#    #+#             */
/*   Updated: 2016/11/18 15:24:19 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	int		i;

	i = ft_strlen(s);
	tmp = (char *)s;
	while (i >= 0)
	{
		if (tmp[i] == (char)c)
			return (tmp + i);
		i--;
	}
	return (NULL);
}
