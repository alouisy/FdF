/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 14:53:56 by alouisy-          #+#    #+#             */
/*   Updated: 2016/12/20 14:54:08 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int argc, char **argv)
{
	int			fd;
	t_params	*prm;

	if (argc == 2)
	{
		prm = init_prm();
		fd = safe_open(argv[1]);
		if (get_dim(fd, prm) == 1)
		{
			close(fd);
			prm->map = make_map(prm->length, prm->height);
			prm->decal_x = WIN_LEHGTH / 2 - (prm->length * prm->scale_xy) / 4;
			prm->decal_y = WIN_HEIGHT / 2 - (prm->height * prm->scale_xy) / 4;
			fd = safe_open(argv[1]);
			prm->map = mapyfication(prm->map, fd);
			close(fd);
			ft_projection(prm);
			fdf(prm);
		}
		ft_putendl("error");
	}
	return (0);
}
