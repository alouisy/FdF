/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 04:19:42 by alouisy-          #+#    #+#             */
/*   Updated: 2017/02/21 04:19:44 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		mlx_pixel_image(int x, int y, int color, t_params *prm)
{
	int		pos;

	pos = (x * prm->bbp / 8) + (y * prm->size_line);
	if ((x > 0 && x < WIN_LEHGTH) && (y > 0 && y < WIN_HEIGHT))
	{
		prm->data[pos] = color;
		prm->data[pos + 1] = color >> 8;
		prm->data[pos + 2] = color >> 16;
	}
}

void		ft_trace(t_trace *coor, t_params *prm)
{
	int		tab[4];
	int		err;
	int		e2;

	tab[0] = abs(coor->x2 - coor->x1);
	tab[1] = abs(coor->y2 - coor->y1);
	tab[2] = coor->x1 < coor->x2 ? 1 : -1;
	tab[3] = coor->y1 < coor->y2 ? 1 : -1;
	err = (tab[0] > tab[1] ? tab[0] : -tab[1]) / 2;
	while (1)
	{
		mlx_pixel_image(coor->x1 + prm->decal_x,
			coor->y1 + prm->decal_y, coor->z++ + 0x66FFFF, prm);
		if (coor->x1 == coor->x2 && coor->y1 == coor->y2)
			break ;
		e2 = err;
		if (e2 > -tab[0])
			err -= tab[1];
		if (e2 > -tab[0])
			coor->x1 += tab[2];
		if (e2 < tab[1])
			err += tab[0];
		if (e2 < tab[1])
			coor->y1 += tab[3];
	}
}

void		ft_filltrace3(int i, int j, t_trace *coor, t_params *prm)
{
	coor->x1 = prm->map[j + 1][i].xp;
	coor->y1 = prm->map[j + 1][i].yp;
	coor->x2 = prm->map[j + 1][i + 1].xp;
	coor->y2 = prm->map[j + 1][i + 1].yp;
	coor->z = prm->map[j + 1][i].z0;
	ft_trace(coor, prm);
}

void		ft_filltrace2(int i, int j, t_trace *coor, t_params *prm)
{
	coor->x1 = prm->map[j][i + 1].xp;
	coor->y1 = prm->map[j][i + 1].yp;
	coor->x2 = prm->map[j + 1][i + 1].xp;
	coor->y2 = prm->map[j + 1][i + 1].yp;
	coor->z = prm->map[j][i + 1].z0;
	ft_trace(coor, prm);
}

void		ft_filltrace1(int i, int j, t_trace *coor, t_params *prm)
{
	coor->x1 = prm->map[j][i].xp;
	coor->y1 = prm->map[j][i].yp;
	coor->x2 = prm->map[j][i + 1].xp;
	coor->y2 = prm->map[j][i + 1].yp;
	coor->z = prm->map[j][i].z0;
	ft_trace(coor, prm);
	coor->x1 = prm->map[j + 1][i].xp;
	coor->y1 = prm->map[j + 1][i].yp;
	coor->x2 = prm->map[j][i].xp;
	coor->y2 = prm->map[j][i].yp;
	coor->z = prm->map[j + 1][i].z0;
	ft_trace(coor, prm);
}
