/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:09:42 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/18 05:07:24 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <libft.h>

int			mouse_motion(int x, int y, void *p)
{
	t_data	*d;
	t_fract	*f;

	d = (t_data *)p;
	f = d->fract;
	if (!d->fract->motion)
		return (0);
	if (x < 0 || x > W_WID || y < 0 || y > W_HEI)
		return (0);
	f->c_r = (float)x * 2.0 / (float)W_WID - 1.0;
	f->c_i = (float)y * 2.0 / (float)W_HEI - 1.0;
	exp_julia(p);
	return (0);
}

static void	sf_unzoommax(t_data *d)
{
	if (d->fract->ite > 10000 || d->zoom <= 0.0000001)
	{
		ft_putendl("Zoom too deeper: nothing to see so reseted !");
		d->fract->ite = 50;
		d->zoom = 2.0;
		d->pos.x = 0;
		d->pos.y = 0;
	}
}

int			zoom(t_data *d, int st, int t)
{
	if (st)
	{
		d->zoom /= ((t) ? 1.03 : 1.03);
		if (d->fract->ite * ((t) ? 1.005 : 1.005) < 2147483647)
			d->fract->ite *= ((t) ? 1.005 : 1.005);
	}
	else
	{
		d->zoom *= ((t) ? 1.03 : 1.03);
		d->fract->ite /= ((t) ? 1.005 : 1.005);
		if (d->fract->ite < 10)
			d->fract->ite = 11;
	}
	sf_unzoommax(d);
	d->fract->x1 = d->zoom * -1.0 + ((float)(d->pos.x / d->zoom) *\
	(d->zoom / 10.0));
	d->fract->x2 = d->zoom * 1.0 + ((float)(d->pos.x / d->zoom) *\
	(d->zoom / 10.0));
	d->fract->y1 = d->zoom * -1.2 + ((float)(d->pos.y / d->zoom) *\
	(d->zoom / 10.0));
	d->fract->y2 = d->zoom * 1.2 + ((float)(d->pos.y / d->zoom) *\
	(d->zoom / 10.0));
	return (0);
}
