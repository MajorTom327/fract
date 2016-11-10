/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:29:09 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/10 18:03:34 by vthomas          ###   ########.fr       */
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
	ft_putendl("allocate img...");
	img = (t_img *)ft_memalloc(sizeof(t_img));
	if (img == NULL)
		ft_putendl("\033[31mimg malloc error\033[0m");
	else
		ft_putendl("img successfully allocated !");
//		img->size.x = W_WID;
//		img->size.y = W_HEI;
	ft_putendl("img size set");
	if (d->mlx == NULL)
		ft_putendl("\033[31mmlx is not set !\033[0m");
	else
		ft_putendl("\033[32mmlx is set !\033[0m");
	img->img = mlx_new_image(d->mlx, W_WID, W_HEI);
	if (img->img == NULL)
		ft_putendl("\033[31mimg-img not allocated !\033[0m");
	else
		ft_putendl("img->img successfully allocated !");
	img->data = mlx_get_data_addr(img->img, &(img->bpp), &(img->sl),\
	&(img->end));
	img->data = ft_memset(img->data, 0xAA, W_HEI * W_WID);
//	t_v2	tmp;
//	tmp.x = W_WID / 2;
//	tmp.y = W_HEI / 2;
//	img_put_px(img, 0xFFFFFF, tmp);
	d->img = img;
	mlx_put_image_to_window(d->mlx, d->win, img->img, 0, 0);
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
