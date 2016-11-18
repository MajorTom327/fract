/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:09:42 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/18 03:19:15 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <libft.h>

int		mouse_motion(int x, int y, void *p)
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

int		zoom(t_data *d, int st, int t)
{
	float	factor;
	float	ite;

	factor = (t) ? 1.3 : 1.03;
	ite = (t) ? 1.01 : 1.005;
	if (st)
	{
		d->zoom /= factor;
		if (d->fract->ite * ite < 2147483647)
			d->fract->ite *= ite;
	}
	else
	{
		d->zoom *= factor;
		d->fract->ite /= ite;
		if (d->fract->ite < 10)
			d->fract->ite = 11;
	}
	d->fract->x1 = d->zoom * -1.0 + ((float)(d->pos.x / d->zoom) * (d->zoom / 10.0));
	d->fract->x2 = d->zoom * 1.0 + ((float)(d->pos.x / d->zoom) * (d->zoom / 10.0));
	d->fract->y1 = d->zoom * -1.2 + ((float)d->pos.y * (d->zoom / 10.0));
	d->fract->y2 = d->zoom * 1.2 + ((float)d->pos.y * (d->zoom / 10.0));
	d->draw((void *)d);
	return (0);
}
