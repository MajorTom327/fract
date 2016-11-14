/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:27:13 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/14 13:07:05 by vthomas          ###   ########.fr       */
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
	d->fract->x1 = -2.1;
	d->fract->x2 = 0.6;
	d->fract->y1 = -1.2;
	d->fract->y2 = 1.2;
	d->fract->ite = 50;
	mlx_expose_hook(d->win, &exp_mandel, (void *)d);
	mlx_loop(d->mlx);
	return (0);
}
