/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_rainbow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 04:19:59 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/17 06:09:49 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static int	get_red(int i)
{
	if (i < 255)
		return (255);
	if (255 <= i && i < 510)
		return (510 - i);
	if (510 <= i && i < 1020)
		return (0);
	if (1020 <= i && i < 1275)
		return (i - 1020);
	return (255);
}

static int	get_green(int i)
{
	if (i < 255)
		return (i);
	if (255 <= i && i < 765)
		return (255);
	if (765 <= i && i < 1020)
		return (1020 - i);
	return (0);
}

static int	get_blue(int i)
{
	if (i < 510)
		return (0);
	if (510 <= i && i < 765)
		return (i - 510);
	if (765 <= i && i < 1275)
		return (255);
	return (1530 - i);
}

int			rainbow(int i, int it)
{
	double t;

	t = (double)i / (double)(it % 1530);
	i = (int)(t * 1530.0);
	//i = i % 1530;
	return ((get_red(i) << 16) + (get_green(i) << 8) + (get_blue(i)));
}
