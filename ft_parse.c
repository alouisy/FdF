/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 04:19:51 by alouisy-          #+#    #+#             */
/*   Updated: 2017/02/21 04:19:53 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		**mapyfication(t_point **map, int fd)
{
	char	**tab;
	char	*line;
	int		x;
	int		y;

	x = -1;
	y = 0;
	while (get_next_line(fd, &line) == 1)
	{
		tab = ft_strsplit(line, ' ');
		while (tab[++x] != NULL)
		{
			map[y][x].x0 = (double)x;
			map[y][x].y0 = (double)y;
			map[y][x].z0 = (double)ft_atoi(tab[x]);
		}
		x = -1;
		y++;
	}
	return (map);
}

t_point		**make_map(int length, int height)
{
	t_point	**map;
	int		y;

	y = -1;
	map = (t_point **)malloc(sizeof(t_point *) * height);
	while (++y < height)
		map[y] = (t_point *)malloc(sizeof(t_point) * length);
	return (map);
}

int			safe_open(char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("Error While Trying To Open The File !");
		exit(0);
	}
	return (fd);
}

int			verif_atoi(char *str)
{
	if (ft_atoi(str) == 0)
	{
		if (ft_strcmp(str, "+0") != 0 &&
			ft_strcmp(str, "-0") != 0 && str[0] != '0')
			return (0);
	}
	return (1);
}

int			get_dim(int fd, t_params *prm)
{
	char	**tab;
	char	*line;
	int		i;

	i = -1;
	prm->length = 0;
	prm->height = 0;
	while (get_next_line(fd, &line) == 1)
	{
		(prm->height)++;
		tab = ft_strsplit(line, ' ');
		while (tab && tab[++i] != NULL)
			if (!verif_atoi(tab[i]))
				return (0);
		if (i != prm->length && prm->length != 0)
			return (0);
		prm->length = i;
		i = -1;
	}
	if (prm->height == 0 || prm->length == 0)
		return (0);
	return (1);
}
