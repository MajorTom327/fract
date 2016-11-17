/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 00:04:11 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/17 03:15:06 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <mlx.h>

static void	info_square(t_v2 start, t_v2 end, t_data *d)
{
	int x;
	int y;

	y = start.y;
	while (y <= end.y)
	{
		x = start.x;
		while (x <= end.x)
		{
			mlx_pixel_put(d->mlx, d->win, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
}

static void	draw_sable(t_data *d, t_v2 pos)
{
	t_v2	src;
	t_v2	dst;

	src = pos;
	dst = pos;
	dst.x += 7;
	line(src, dst, d, 0x000000);
	src.y++;
	dst.y += 9;
	line(src, dst, d, 0x000000);
	src.y += 8;
	line(src, dst, d, 0x000000);
	src.y--;
	dst.y -= 9;
	line(src, dst, d, 0x000000);
}

void		info_calculate(t_data *d)
{
	t_v2	start;
	t_v2	end;

	start.x = 0;
	start.y = W_HEI - 16;
	end.x = start.x + 16;
	end.y = start.y + 16;
	info_square(start, end, d);
	start.x += 4;
	start.y += 4;
	draw_sable(d, start);
	mlx_string_put(d->mlx, d->win, start.x + 16, start.y - 8, 0x000000,
		"Calculating...");
}
