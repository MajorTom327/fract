/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:57:49 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/18 03:16:55 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <libft.h>

static void	recalculate_pos(t_data *d, int x, int y, int btn)
{
	t_v2	pos;

	pos.x = ((x - (W_WID / 2)) / 100);
	pos.y = ((y - (W_HEI / 2)) / 100);
	if (pos.x <= 1 && pos.x >= -1)
		pos.x = 0;
	if (pos.y <= 1 && pos.y >= -1)
		pos.y = 0;
	d->pos.x += (btn == 4) ? pos.x : -pos.x;
	d->pos.y += pos.y;
	ft_putnbr_desc("pos.x:\t", d->pos.x);
	ft_putnbr_desc("pos.y:\t", d->pos.y);
}

int			hook_mouse(int btn, int x, int y, void *p)
{
	t_data	*d;

	d = (t_data *)p;
	if (btn == 4 || btn == 5)
	{
		recalculate_pos(d, x, y, btn);
		zoom(d, (btn == 4), 1);
	}
	return (0);
}
