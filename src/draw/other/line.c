/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gft_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 01:08:06 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/17 01:08:16 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <fractol.h>

void	line(t_v2 src, t_v2 dst, t_data *data, int c)
{
	t_v2	d;
	t_v2	s;
	t_v2	e;

	d.x = abs(dst.x - src.x);
	s.x = src.x < dst.x ? 1 : -1;
	d.y = abs(dst.y - src.y);
	s.y = src.y < dst.y ? 1 : -1;
	e.x = (d.x > d.y ? d.x : -d.y) / 2;
	while (src.x != dst.x || src.y != dst.y)
	{
		mlx_pixel_put(data->mlx, data->win, src.x, src.y,\
			mlx_get_color_value(data->mlx, c));
		e.y = e.x;
		if (e.y > -d.x)
		{
			e.x -= d.y;
			src.x += s.x;
		}
		if (e.y < d.y)
		{
			e.x += d.x;
			src.y += s.y;
		}
	}
}
