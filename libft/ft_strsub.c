/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 22:41:10 by alouisy-          #+#    #+#             */
/*   Updated: 2016/11/18 22:41:13 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	str = NULL;
	if (s)
	{
		str = ft_strnew(len);
		if (str)
		{
			while (s[start] && i < len)
			{
				str[i] = s[start];
				i++;
				start++;
			}
		}
	}
	return (str);
}
