/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:09:42 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/14 17:31:06 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <libft.h>

int		mouse_motion(int x, int y, void *p)
{
	t_data	*d;
	t_fract	*f;
	float	px;
	float	py;

	d = (t_data *)p;
	f = d->fract;
	if (!d->fract->motion)
		return (0);
	if (x < 0 || x > W_WID || y < 0 || y > W_HEI)
		return (0);
	ft_putendl("MOTION EVENT !!");
	f->c_r = x * 2 / W_WID - 1;
	f->c_i = y * 2 / W_HEI - 1;
	exp_julia(p);
	return (0);
}
