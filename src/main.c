/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:43:26 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/09 15:39:09 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fractol.h>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		usage();
		return (0);
	}
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		mandel();
	else if (ft_strcmp(av[1], "julia") == 0)
		ft_putendl("let's work on julia !");
	else if (ft_strcmp(av[1], "ship") == 0)
		ft_putendl("let's work on ship !");
	else
		usage();
	return (0);
}
