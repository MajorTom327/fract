/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:35:27 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/16 02:25:58 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <libft.h>
#include <mlx.h>

int	julia(void)
{
	t_data	*d;

	d = init();
	d->fract = (t_fract *)ft_memalloc(sizeof(t_fract));
	d->fract->x1 = -1.0;
	d->fract->x2 = 1.0;
	d->fract->y1 = -1.2;
	d->fract->y2 = 1.2;
	d->fract->ite = 50;
	d->fract->motion = 1;
	d->fract->c_r = 0.285;
	d->fract->c_i = 0.01;
	mlx_hook(d->win, 6, (1L << 6), &mouse_motion, (void *)d);
	d->draw = &exp_julia;
	mlx_expose_hook(d->win, &exp_julia, (void *)d);
	mlx_mouse_hook(d->win, &hook_mouse, (void *)d);
	mlx_loop(d->mlx);
	return (0);
}
