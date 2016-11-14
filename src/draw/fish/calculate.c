/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:43:50 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/14 14:50:19 by vthomas          ###   ########.fr       */
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

static int		sf_fishpart(t_fract *f, t_v2 pos)
{
	float	c_r;
	float	c_i;
	float	z_r;
	float	z_i;
	int		i;

	i = 0;
	c_r = pos.x / f->zoom.x + f->x1;
	c_i = pos.y / f->zoom.y + f->y1;
	z_r = 0;
	z_i = 0;
	while (((z_r * z_r) + (z_i * z_i)) < 4 && i < f->ite)
	{
		sf_locksave(z_r, 1);
		tmp = z_r;
		z_r = fabs(z_r * z_r - z_i * z_i) + c_r;
		z_i = 2 * z_i * sf_locksave(0.0, 0) + c_i;
		i++;
	}
	return (i);
}

void			fishcalculate(t_data *d)
{
	t_v2	pos;
	int		ret;

	d->fract->zoom.x = W_WID / (d->fract->x2 - d->fract->x1);
	d->fract->zoom.y = W_HEI / (d->fract->y2 - d->fract->y1);
	pos.y = 0;
	while (pos.y < W_HEI)
	{
		pos.x = 0;
		while (pos.x < W_WID)
		{
			ret = sf_fishpart(d->fract, pos);
			if (ret != d->fract->ite)
				img_put_px(d->img, rainbow(ret, d->fract->ite), pos);
			pos.x++;
		}
		pos.y++;
	}
}
