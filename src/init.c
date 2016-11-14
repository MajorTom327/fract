/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:29:09 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/14 13:04:09 by vthomas          ###   ########.fr       */
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

	ft_putendl_fd("init", 2);
	d = (t_data *)ft_memalloc(sizeof(t_data));
	if (d == NULL)
		exit(EXIT_FAILURE);
	if ((d->mlx = mlx_init()) == NULL)
		exit(EXIT_FAILURE);
	if ((d->win = mlx_new_window(d->mlx, W_WID, W_HEI, "Fract'Ol")) == NULL)
		exit(EXIT_FAILURE);
/* ************************************************************************** */
	img = (t_img *)ft_memalloc(sizeof(t_img));
	img->img = mlx_new_image(d->mlx, W_WID, W_HEI);
	img->data = mlx_get_data_addr(img->img, &(img->bpp), &(img->sl),\
	&(img->end));
//	img->data = ft_memset(img->data, 0xAA, W_HEI * W_WID);
	t_v2	tmp;
	tmp.x = 255;
	tmp.y = 255;
	img_put_px(img, 0xFFFFFF, tmp);
	d->img = img;
	mlx_put_image_to_window(d->mlx, d->win, d->img->img, 0, 0);
/* ************************************************************************** */
	mlx_hook(d->win, 17, (1L << 17), &exit_fractol, NULL);
	mlx_key_hook(d->win, &event, NULL);
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
	(void)param;
	if (keycode == 53)
		exit_fractol(NULL);
	ft_putnbr_desc("key pressed:\t", keycode);
}
