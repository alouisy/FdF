/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 19:06:20 by alouisy-          #+#    #+#             */
/*   Updated: 2017/02/25 16:06:13 by alouisy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <math.h>
# include "libft/includes/libft.h"

# define WIN_LEHGTH 1280
# define WIN_HEIGHT 720
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_A 0
# define KEY_D 2
# define KEY_W 13
# define KEY_S 1
# define KEY_PLUS 69
# define KEY_LESS 78
# define KEY_I 34
# define KEY_P 35

typedef struct		s_params
{
	int				decal_x;
	int				decal_y;
	int				scale_xy;
	int				scale_z;
	int				angle;
	int				fx;
	int				length;
	int				height;
	struct s_point	**map;
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bbp;
	int				size_line;
	int				endian;
}					t_params;

typedef struct		s_point
{
	double			x0;
	double			y0;
	double			z0;
	double			xp;
	double			yp;
	double			zp;
}					t_point;

typedef struct		s_trace
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				z;
}					t_trace;

int					safe_open(char *filename);
t_params			*init_prm(void);
int					get_dim(int fd, t_params *parameters);
int					verif_atoi(char *str);
t_point				**make_map(int length, int height);
t_point				**mapyfication(t_point **map, int fd);
void				ft_projection(t_params *parameters);
void				ft_fx(int x, int y, t_params *parameters);
void				ft_trace(t_trace *coor, t_params *parameters);
void				ft_filltrace1(int i, int j,
	t_trace *coor, t_params *parameters);
void				ft_filltrace2(int i, int j,
	t_trace *coor, t_params *parameters);
void				ft_filltrace3(int i, int j,
	t_trace *coor, t_params *parameters);
double				good_arrondi(double nb);
int					key_style(int keycode, t_params *parameters);
void				fdf_graphic(int length, int height, t_params *parameters);
void				fdf(t_params *parameters);
void				mlx_pixel_image(int x, int y, int color, t_params *prm);

#endif
