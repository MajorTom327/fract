/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:27:25 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/14 15:17:03 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <mlx.h>
#include <stdlib.h>

int	exp_julia(void *param)
{
	t_data	*d;

	d = (t_data *)param;
	ft_putendl("Calculate started...");
	ft_putnbr_desc("WIDTH:\t", W_WID);
	ft_putnbr_desc("HEIGHT:\t", W_HEI);
	juliacalculate(d);
	ft_putendl("Calculate finished !");
	mlx_put_image_to_window(d->mlx, d->win, d->img->img, 0, 0);
	return (0);
}
