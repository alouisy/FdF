/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 04:45:45 by alouisy-          #+#    #+#             */
/*   Updated: 2017/02/21 04:45:48 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			key_style(int keycode, t_params *prm)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == KEY_P || keycode == KEY_I)
		prm->fx = (keycode == KEY_I) ? 1 : 0;
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		prm->decal_x += (keycode == KEY_LEFT) ? -30 : 30;
	else if (keycode == KEY_UP || keycode == KEY_DOWN)
		prm->decal_y += (keycode == KEY_UP) ? -30 : 30;
	else if (keycode == KEY_PLUS || keycode == KEY_LESS)
		prm->angle += (keycode == KEY_PLUS) ? -5 : 5;
	else if (keycode == KEY_A && prm->scale_xy >= 3)
		prm->scale_xy -= 1;
	else if (keycode == KEY_D && prm->scale_xy <= 49)
		prm->scale_xy += 1;
	else if (keycode == KEY_S && prm->scale_z >= 3)
		prm->scale_z -= 1;
	else if (keycode == KEY_W && prm->scale_z <= 49)
		prm->scale_z += 1;
	else
		return (0);
	ft_projection(prm);
	mlx_destroy_image(prm->mlx, prm->img);
	fdf_graphic(prm->length, prm->height, prm);
	return (0);
}

t_params	*init_prm(void)
{
	t_params	*prm;

	prm = (t_params*)malloc(sizeof(t_params));
	prm->scale_xy = 20;
	prm->scale_z = 20;
	prm->angle = 45;
	prm->fx = 1;
	return (prm);
}
