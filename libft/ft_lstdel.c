/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:09:11 by alouisy-          #+#    #+#             */
/*   Updated: 2016/11/22 15:09:13 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*list;
	t_list	*next;

	if (del && alst)
	{
		list = *alst;
		while (list)
		{
			next = list->next;
			del(list->content, list->content_size);
			free(list);
			list = next;
		}
		*alst = NULL;
	}
}
