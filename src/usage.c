/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:10:51 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/17 03:02:27 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <libft.h>

void	usage(void)
{
	ft_putendl("usage: ./fractol [fractal]");
	ft_putendl("Where fractal is one of this list:\n"\
			"\t- \033[4mm\033[0mandelbrot\n"\
			"\t- \033[4mj\033[0mulia\n"\
			"\t- \033[4ms\033[0mhip\n"\
			"\t- \033[4mf\033[0mish");
}
