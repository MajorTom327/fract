/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:43:50 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/16 04:40:17 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <libft.h>
#include <mlx.h>
#include <math.h>

static int		sf_shippart(t_fract *f, t_v2 pos)
{
	t_cmplx	cmplx;
	float	tmp;
	int		i;

	i = 0;
	cmplx.c_r = pos.x / f->zoom.x + f->x1;
	cmplx.c_i = pos.y / f->zoom.y + f->y1;
	cmplx.z_r = 0;
	cmplx.z_i = 0;
	while (((cmplx.z_r * cmplx.z_r) + (cmplx.z_i * cmplx.z_i)) < 4 &&
	i < f->ite)
	{
		tmp = cmplx.z_r;
		cmplx.z_r = cmplx.z_r * cmplx.z_r - cmplx.z_i * cmplx.z_i + cmplx.c_r;
		cmplx.z_i = 2 * fabs(cmplx.z_i * tmp) + cmplx.c_i;
		i++;
	}
	return (i);
}

void			shipcalculate(t_data *d, int bg, int xmin, int xmax)
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
			ret = sf_shippart(d->fract, pos);
			if (ret != d->fract->ite)
				img_put_px(d->img, rainbow(ret, d->fract->ite * d->zoom), pos);
			else
				img_put_px(d->img, bg, pos);
			pos.x++;
		}
		pos.y++;
	}
}

void			*shipth(void *p)
{
	t_thread	*t;
	int			xmin;
	int			xmax;

	t = (t_thread *)p;
	xmin = W_WID / NBTH * t->id;
	xmax = W_WID / NBTH * (t->id + 1);
	shipcalculate(t->d, t->c, xmin, xmax);
	pthread_exit(NULL);
}
