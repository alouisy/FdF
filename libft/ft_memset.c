/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:08:10 by alouisy-          #+#    #+#             */
/*   Updated: 2016/11/04 16:08:13 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = (char*)b;
	while (i < len)
	{
		tmp[i] = (unsigned char)c;
		i++;
	}
	b = (void*)tmp;
	return (b);
}
