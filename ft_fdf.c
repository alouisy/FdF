/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 04:19:34 by alouisy-          #+#    #+#             */
/*   Updated: 2017/02/21 04:19:38 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fdf_graphic(int length, int height, t_params *prm)
{
	int			i;
	int			j;
	t_trace		*coor;

	i = -1;
	j = 0;
	coor = (t_trace *)malloc(sizeof(t_trace));
	prm->img = mlx_new_image(prm->mlx, WIN_LEHGTH, WIN_HEIGHT);
	prm->data = mlx_get_data_addr(prm->img, &prm->bbp,
		&prm->size_line, &prm->endian);
	while (j < height - 1)
	{
		while (++i < length - 1)
		{
			ft_filltrace1(i, j, coor, prm);
			if (i + 2 == length)
				ft_filltrace2(i, j, coor, prm);
			if (j + 2 == height)
				ft_filltrace3(i, j, coor, prm);
		}
		j++;
		i = -1;
	}
	mlx_put_image_to_window(prm->mlx, prm->win, prm->img, 0, 0);
}

void		fdf(t_params *prm)
{
	prm->mlx = mlx_init();
	prm->win = mlx_new_window(prm->mlx, WIN_LEHGTH, WIN_HEIGHT, "FdF");
	fdf_graphic(prm->length, prm->height, prm);
	mlx_key_hook(prm->win, key_style, prm);
	mlx_loop(prm->mlx);
}

double		good_arrondi(double nb)
{
	int		cp_i;
	double	cp_d;

	cp_i = (int)nb;
	cp_d = (double)cp_i + 0.5;
	if (nb >= cp_d)
		return (cp_d + 0.5);
	return (cp_d - 0.5);
}

void		ft_fx(int x, int y, t_params *prm)
{
	if (prm->fx == 1)
	{
		prm->map[y][x].zp = prm->map[y][x].z0 * prm->scale_z;
		
		prm->map[y][x].xp = (prm->map[y][x].x0 * prm->scale_xy * cos(prm->angle * M_PI / 180.0)) - (prm->map[y][x].y0 * prm->scale_xy * sin(prm->angle * M_PI / 180.0));
		prm->map[y][x].yp = -prm->map[y][x].zp + ((prm->map[y][x].x0 * prm->scale_xy * sin(prm->angle * M_PI / 180.0)) + (prm->map[y][x].y0 * prm->scale_xy * cos(prm->angle * M_PI / 180.0))) / 2;
	}
	else
	{
		prm->map[y][x].zp = prm->map[y][x].z0 * prm->scale_z;
		prm->map[y][x].xp = prm->map[y][x].x0 * prm->scale_xy
		+ prm->map[y][x].zp * sin(prm->angle * M_PI / 180.0);
		prm->map[y][x].yp = prm->map[y][x].y0 * prm->scale_xy
		+ (sin(prm->angle * M_PI / 180.0)) / 2 * prm->map[y][x].zp;
	}
	prm->map[y][x].xp = good_arrondi(prm->map[y][x].xp);
	prm->map[y][x].yp = good_arrondi(prm->map[y][x].yp);
}

void		ft_projection(t_params *prm)
{
	int		x;
	int		y;

	x = -1;
	y = 0;
	while (y < prm->height)
	{
		while (++x < prm->length)
			ft_fx(x, y, prm);
		x = -1;
		y++;
	}
}
