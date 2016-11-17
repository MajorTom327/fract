/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:57:49 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/17 04:10:27 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <libft.h>

static void	recalculate_pos(t_data *d, int x, int y, int btn)
{
	t_v2	pos;

	pos.x = ((x - (W_WID / 2)) / 100);
	pos.y = ((y - (W_HEI / 2)) / 100);
	d->pos.x += (btn == 4) ? pos.x : -pos.x;
	d->pos.y += (btn == 4) ? pos.y : -pos.y;
}

int	hook_mouse(int btn, int x, int y, void *p)
{
	t_data	*d;

	(void)x;
	(void)y;
	d = (t_data *)p;
	if (btn == 4)
	{
		d->zoom /= 1.3;
		if (d->fract->ite * 1.3 < 2147483647)
			d->fract->ite *= 1.3;
	}
	else if (btn == 5)
	{
		d->zoom *= 1.3;
		if (d->fract->ite >= 10)
			d->fract->ite /= 1.3;
	}
	if (btn == 4 || btn == 5)
	{
		if (d->zoom > 1.0)
			d->fract->ite = 50;
		recalculate_pos(d, x, y, btn);
		d->fract->x1 = d->zoom * -1.0 + ((float)d->pos.x / 100.0);
		d->fract->x2 = d->zoom * 1.0 + ((float)d->pos.x / 100.0);
		d->fract->y1 = d->zoom * -1.2 + ((float)d->pos.y / 100.0);
		d->fract->y2 = d->zoom * 1.2 + ((float)d->pos.y / 100.0);
		d->draw(p);
	}
	return (0);
}
