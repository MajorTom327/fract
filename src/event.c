/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:09:42 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/14 16:18:15 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <libft.h>

int		mouse_motion(int x, int y, void *p)
{
	t_data	*d;
	t_fract	*f;

	d = (t_data *)p;
	if (!d->fract->motion)
		return (0);
	ft_putendl("MOTION EVENT !!");
	return (0);
}
