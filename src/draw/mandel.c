/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:27:13 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/16 04:33:24 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <libft.h>
#include <mlx.h>

int	mandel(void)
{
	t_data	*d;

	d = init();
	d->fract = (t_fract *)ft_memalloc(sizeof(t_fract));
	d->fract->x1 = d->zoom * -1.0 + ((float)d->pos.x / 100);
	d->fract->x2 = d->zoom * 1.0 + ((float)d->pos.x / 100);
	d->fract->y1 = d->zoom * -1.2 + ((float)d->pos.y / 100);
	d->fract->y2 = d->zoom * 1.2 + ((float)d->pos.y / 100);
	d->fract->ite = 50;
	d->fract->motion = 0;
	mlx_expose_hook(d->win, &exp_mandel, (void *)d);
	d->draw = &exp_mandel;
	mlx_mouse_hook(d->win, &hook_mouse, (void *)d);
	mlx_loop(d->mlx);
	return (0);
}
