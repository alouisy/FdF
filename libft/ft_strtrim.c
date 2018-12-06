/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 23:18:47 by alouisy-          #+#    #+#             */
/*   Updated: 2016/11/18 23:18:49 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	start;
	size_t	stop;

	str = NULL;
	start = 0;
	if (s)
	{
		stop = ft_strlen(s) - 1;
		while (start < stop && ft_isspace(s[start]))
			start++;
		if (start < stop)
		{
			while (stop > 0 && ft_isspace(s[stop]))
				stop--;
			str = ft_strsub(s, start, stop - start + 1);
		}
		else
			str = ft_strnew(0);
	}
	return (str);
}
