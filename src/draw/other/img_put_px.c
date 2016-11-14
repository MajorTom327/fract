/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_put_px.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:51:55 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/10 17:32:07 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	img_put_px(t_img *img, unsigned long c, t_v2 p)
{
	int pos;

	if (p.x < 0 || p.x > W_WID || p.y > W_HEI || p.y < 0)
		return ;
	pos = p.y * img->sl + p.x * img->bpp / 8;
	img->data[pos] = (c & 0x0000FF);
	img->data[pos + 1] = (c & 0x00FF00) >> 8;
	img->data[pos + 2] = (c & 0xFF0000) >> 16;
}
