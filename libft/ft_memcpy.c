/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 13:12:50 by alouisy-          #+#    #+#             */
/*   Updated: 2016/11/16 13:55:39 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t	i;
	char	*d2;
	char	*s2;

	i = -1;
	d2 = dst;
	s2 = (char *)src;
	while (++i < n)
		d2[i] = s2[i];
	return ((void *)d2);
}
