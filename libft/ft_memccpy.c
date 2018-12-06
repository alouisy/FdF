/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 13:52:56 by alouisy-          #+#    #+#             */
/*   Updated: 2016/11/16 13:55:49 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,
		int c, size_t n)
{
	size_t			i;
	unsigned char	*d2;
	unsigned char	*s2;

	i = 0;
	d2 = dst;
	s2 = (unsigned char *)src;
	while (i < n)
	{
		d2[i] = s2[i];
		i++;
		if (s2[i - 1] == (unsigned char)c)
			return ((void *)(d2 + i));
	}
	return (NULL);
}
