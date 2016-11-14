/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:13:49 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/14 15:07:44 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define W_WID 1024
# define W_HEI 1024

typedef struct	s_v2
{
	int			x;
	int			y;
}				t_v2;

typedef struct	s_v2f
{
	float			x;
	float			y;
}				t_v2f;

typedef struct	s_img
{
	void		*img;
	char		*data;
	int			bpp;
	int			sl;
	int			end;
	t_v2		size;
}				t_img;

typedef struct	s_fract
{
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	t_v2f	zoom;
	int		ite;
}				t_fract;

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_fract		*fract;
}				t_data;

void			img_put_px(t_img *img, unsigned long c, t_v2 p);
int				rainbow(int i, int it);

void			usage(void);
t_data			*init(void);
int				exit_fractol(void *param);
int				event(int keycode, void *param);

int				mandel(void);
int				exp_mandel(void *param);
void			mandelcalculate(t_data *d);

int				fish(void);
int				exp_fish(void *param);
void			fishcalculate(t_data *d);

int				ship();
int				exp_ship(void *param);
void			shipcalculate(t_data *d);
#endif
