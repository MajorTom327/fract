/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:10:51 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/09 15:25:48 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <libft.h>

void	usage(void)
{
	ft_putendl("usage: ./fractol [fractal]");
	ft_putendl("Where fractal is one of this list:\n"\
			"\t- mandelbrot\n"\
			"\t- julia\n"\
			"\t- ship");
}
