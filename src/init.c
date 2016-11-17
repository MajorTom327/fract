/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:29:09 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/17 04:10:57 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <libft.h>
#include <mlx.h>
#include <stdlib.h>

t_data	*init(void)
{
	t_data	*d;
	t_img	*img;

	d = (t_data *)ft_memalloc(sizeof(t_data));
	if (d == NULL)
		exit(EXIT_FAILURE);
	if ((d->mlx = mlx_init()) == NULL)
		exit(EXIT_FAILURE);
	if ((d->win = mlx_new_window(d->mlx, W_WID, W_HEI, "Fract'Ol")) == NULL)
		exit(EXIT_FAILURE);
	img = (t_img *)ft_memalloc(sizeof(t_img));
	img->img = mlx_new_image(d->mlx, W_WID, W_HEI);
	img->data = mlx_get_data_addr(img->img, &(img->bpp), &(img->sl),\
	&(img->end));
	d->img = img;
	mlx_hook(d->win, 17, (1L << 17), &exit_fractol, NULL);
	mlx_key_hook(d->win, &event, (void *)d);
	d->pos.x = 0;
	d->zoom = 2.0;
	return (d);
}

int		exit_fractol(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
	return (0);
}

int		event(int keycode, void *param)
{
	t_data	*d;

	d = (t_data *)param;
	if (keycode == 53)
		exit_fractol(NULL);
	else if (keycode == 49)
		d->fract->motion = !d->fract->motion;
	else if (keycode == 123)
		d->pos.x--;
	else if (keycode == 124)
		d->pos.x++;
	else if (keycode == 125)
		d->pos.y++;
	else if (keycode == 126)
		d->pos.y--;
	if (keycode >= 123 && keycode <= 126)
	{
		d->fract->x1 = d->zoom * -1.0 + ((float)d->pos.x / 100);
		d->fract->x2 = d->zoom * 1.0 + ((float)d->pos.x / 100);
		d->fract->y1 = d->zoom * -1.2 + ((float)d->pos.y / 100);
		d->fract->y2 = d->zoom * 1.2 + ((float)d->pos.y / 100);
		d->draw(param);
	}
	return (0);
}
