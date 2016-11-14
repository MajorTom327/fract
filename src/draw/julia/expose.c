/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:27:25 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/14 23:35:30 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <mlx.h>
#include <stdlib.h>
#include <pthread.h>

int	exp_julia(void *param)
{
	t_data		*d;
	t_thread	t[NBTH];//Look this
	int i;

	d = (t_data *)param;
	i = 0;
	while (i < NBTH)
	{
		t[i].id = i;
		t[i].d = d;
		t[i].c = 0x222222 * i;
		pthread_create(&(t[i].thd), NULL, &juliath, (void *)&t[i]);
		//juliacalculate(d);
		i++;
	}
	while (i <= 0)
	{
		pthread_join(t[i].thd, NULL);
		i--;
	}
	//full sans thread:
	// decommente en dessous et commente les 2 while precedent
//	juliacalculate(d, 0, W_WID);
	mlx_put_image_to_window(d->mlx, d->win, d->img->img, 0, 0);
	return (0);
}
