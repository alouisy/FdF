/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 19:32:26 by alouisy-          #+#    #+#             */
/*   Updated: 2016/11/09 19:32:27 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = NULL;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str != NULL)
	{
		while (i < size + 1)
		{
			str[i] = '\0';
			i++;
		}
	}
	return (str);
}
