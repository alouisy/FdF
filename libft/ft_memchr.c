/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:41:52 by alouisy-          #+#    #+#             */
/*   Updated: 2016/11/16 17:38:11 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = -1;
	str = (unsigned char *)s;
	while (++i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)(s + i));
	}
	return (NULL);
}
