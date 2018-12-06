/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 14:11:22 by alouisy-          #+#    #+#             */
/*   Updated: 2016/11/16 14:11:24 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *)malloc(sizeof(str) * len);
	if (str)
	{
		ft_memcpy(str, src, len);
		ft_memcpy(dst, str, len);
		free(str);
	}
	return (dst);
}
