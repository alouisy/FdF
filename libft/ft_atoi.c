/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:24:29 by alouisy-          #+#    #+#             */
/*   Updated: 2016/11/07 16:57:12 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_atoi(const char *str)
{
	int		neg;
	int		i;
	int		nb;

	i = 0;
	neg = 1;
	nb = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		i++;
		neg = -1;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		nb = 10 * nb + ((int)str[i] - '0');
		i++;
	}
	return (nb * neg);
}
