/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:57:49 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/15 21:36:41 by vthomas          ###   ########.fr       */
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
	{
		d->zoom++;
		d->fract->ite += 2;
		d->fract->x1 += 0.05;
		d->fract->x2 -= 0.05;
		d->fract->y1 += 0.05;
		d->fract->y2 -= 0.05;
		d->draw(p);
	}
	else if (btn == 5)
	{
		d->zoom--;
		d->fract->ite -= 2;
		d->fract->x1 -= 0.05;
		d->fract->x2 += 0.05;
		d->fract->y1 -= 0.05;
		d->fract->y2 += 0.05;
		d->draw(p);
	}
	return (0);
}
