/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:07:58 by alouisy-          #+#    #+#             */
/*   Updated: 2016/11/22 15:08:00 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t	ft_nbrtab(char const *s, char c)
{
	size_t	nb;
	size_t	i;

	nb = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			nb++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (nb);
}

static char		**ft_filltab(char **tab, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	stop;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			if (ft_strchr(s + i, (int)c))
				stop = (size_t)(ft_strchr(s + i, (int)c) - (s + i));
			else
				stop = ft_strlen(s) - i;
			tab[j] = ft_strsub(s, i, stop);
			j++;
			i += stop;
		}
	}
	tab[j] = NULL;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;

	tab = NULL;
	if (s)
	{
		tab = (char **)malloc(sizeof(char*) * (ft_nbrtab(s, c) + 1));
		if (tab)
			tab = ft_filltab(tab, s, c);
	}
	return (tab);
}
