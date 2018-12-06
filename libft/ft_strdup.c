/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:21:24 by alouisy-          #+#    #+#             */
/*   Updated: 2016/11/16 19:21:26 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = -1;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (str)
	{
		while (s1[++i])
			str[i] = s1[i];
		str[i] = '\0';
	}
	return (str);
}
