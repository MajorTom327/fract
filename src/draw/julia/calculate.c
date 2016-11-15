/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:43:50 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/15 20:35:12 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <libft.h>
#include <mlx.h>

static int		sf_juliapart(t_fract *f, t_v2 pos)
{
	float	z_r;
	float	z_i;
	float	tmp;
	int		i;

	i = 0;
	z_r = (float)pos.x / f->zoom.x + f->x1;
	z_i = (float)pos.y / f->zoom.y + f->y1;
	while (((z_r * z_r) + (z_i * z_i)) < 4 && i < f->ite)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + f->c_r;
		z_i = 2.0 * z_i * tmp + f->c_i;
		i++;
	}
	return (i);
}

void			juliacalculate(t_data *d, int bg, int xmin, int xmax)
{
	t_v2	pos;
	int		ret;

	d->fract->zoom.x = W_WID / (d->fract->x2 - d->fract->x1);
	d->fract->zoom.y = W_HEI / (d->fract->y2 - d->fract->y1);
	pos.y = 0;
	while (pos.y < W_HEI)
	{
		pos.x = xmin;
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
	juliacalculate(t->d, t->c, xmin, xmax);
	pthread_exit(NULL);
}
