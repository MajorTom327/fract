/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:27:25 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/15 20:15:36 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <mlx.h>
#include <stdlib.h>
#include <pthread.h>

int	exp_julia(void *param)
{
	t_data		*d;
	t_thread	t[NBTH];
	int i;

	d = (t_data *)param;
	i = 0;
	while (i < NBTH)
	{
		t[i].id = i;
		t[i].d = d;
		t[i].c = 0x222222 * i;
		pthread_create(&(t[i].thd), NULL, &juliath, (void *)&t[i]);
		i++;
	}
	while (i >= 0)
	{
		pthread_join(t[i].thd, NULL);
		i--;
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img->img, 0, 0);
	return (0);
}
