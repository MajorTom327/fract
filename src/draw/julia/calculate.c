/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:43:50 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/14 23:24:57 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <libft.h>
#include <mlx.h>

static float	sf_locksave(float v, int st)
{
	static float	value = 0.0;

	if (st)
		value = v;
	return (value);
}

static int		sf_juliapart(t_fract *f, t_v2 pos)
{
	float	z_r;
	float	z_i;
	int		i;

	i = 0;
	z_r = (float)pos.x / f->zoom.x + f->x1;
	z_i = (float)pos.y / f->zoom.y + f->y1;
	while (((z_r * z_r) + (z_i * z_i)) < 4 && i < f->ite)
	{
		sf_locksave(z_r, 1);
		z_r = z_r * z_r - z_i * z_i + f->c_r;
		z_i = 2.0 * z_i * sf_locksave(0.0, 0) + f->c_i;
		i++;
	}
	return (i);
}

void			juliacalculate(t_data *d, int bg, const int xmin, const int xmax)
{
	t_v2	pos;
	int		ret;

	d->fract->zoom.x = W_WID / (d->fract->x2 - d->fract->x1);
	d->fract->zoom.y = W_HEI / (d->fract->y2 - d->fract->y1);
	pos.y = 0;
	while (pos.y < W_HEI)
	{
		pos.x = (int)xmin;
		while (pos.x < xmax)
		{
			ret = sf_juliapart(d->fract, pos);//Partie calcule
			if (ret != d->fract->ite)
				img_put_px(d->img, rainbow(ret, d->fract->ite), pos);
			else
				img_put_px(d->img, bg, pos);
			pos.x++;
		}
		pos.y++;
	}
}

void			*juliath(void *p)
{
	t_thread	*t;
	int			xmin;
	int			xmax;

	t = (t_thread *)p;
	xmin = W_WID / NBTH * t->id;//ID EST APPARAMENT INVALIDE DES FOIS
	xmax = W_WID / NBTH * (t->id + 1);
	ft_putstr_fd("id:\t", 2);
	ft_putnbr_fd(t->id, 2);
	ft_putchar_fd('\n', 2);
	if (t->id < 0 || t->id > NBTH)
	{
		ft_putendl("ERROR THREAD");
		exit(EXIT_FAILURE);
		pthread_exit(NULL);
	}
	//xmin: limite gauche du thread
	//xmax: limite droite du thread
	juliacalculate(t->d, t->c, xmin, xmax);
	pthread_exit(NULL);
}
