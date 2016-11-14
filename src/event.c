/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:09:42 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/14 23:06:06 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <libft.h>

int		mouse_motion(int x, int y, void *p)
{
	t_data	*d;
	t_fract	*f;

	d = (t_data *)p;
	f = d->fract;
	if (!d->fract->motion)
		return (0);
	if (x < 0 || x > W_WID || y < 0 || y > W_HEI)
		return (0);
	f->c_r = (float)x * 2.0 / (float)W_WID - 1.0;
	f->c_i = (float)y * 2.0 / (float)W_HEI - 1.0;
	exp_julia(p);
	return (0);
}
