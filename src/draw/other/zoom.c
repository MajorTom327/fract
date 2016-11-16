/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:57:49 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/16 02:45:17 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <libft.h>

int	hook_mouse(int btn, int x, int y, void *p)
{
	t_data	*d;

	(void)x;
	(void)y;
	d = (t_data *)p;
	if (btn == 4)
	{//zoom
		d->zoom /= 1.3;
		d->fract->ite += 5;
	}
	else if (btn == 5)
	{//dezoom
		d->zoom *= 1.3;
		if (d->fract->ite > 10)
			d->fract->ite -= 5;
	}
	if (btn == 4 || btn == 5)
	{
		d->fract->x1 = d->zoom * -1.0;
		d->fract->x2 = d->zoom * 1.0;
		d->fract->y1 = d->zoom * -1.2;
		d->fract->y2 = d->zoom * 1.2;
		d->draw(p);
	}
	return (0);
}
