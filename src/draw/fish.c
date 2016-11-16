/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fish.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:35:27 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/16 02:50:58 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <libft.h>
#include <mlx.h>

int	fish(void)
{
	t_data	*d;

	d = init();
	d->fract = (t_fract *)ft_memalloc(sizeof(t_fract));
	d->fract->x1 = d->zoom * -1.0;
	d->fract->x2 = d->zoom * 1.0;
	d->fract->y1 = d->zoom * -1.2;
	d->fract->y2 = d->zoom * 1.2;
	d->fract->ite = 50;
	d->fract->motion = 0;
	mlx_expose_hook(d->win, &exp_fish, (void *)d);
	d->draw = &exp_fish;
	mlx_mouse_hook(d->win, &hook_mouse, (void *)d);
	mlx_loop(d->mlx);
	return (0);
}
