/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 22:15:07 by alouisy-          #+#    #+#             */
/*   Updated: 2016/11/18 22:15:08 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*str;

	i = -1;
	str = NULL;
	if (s && f)
	{
		str = ft_strnew(ft_strlen(s));
		if (str)
		{
			while (s[++i])
				str[i] = f(s[i]);
		}
	}
	return (str);
}
