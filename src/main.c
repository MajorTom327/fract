/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:43:26 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/14 15:18:48 by vthomas          ###   ########.fr       */
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
		julia();
	else if (ft_strcmp(av[1], "ship") == 0)
		ship();
	else if (ft_strcmp(av[1], "fish") == 0)
		fish();
	else
		usage();
	return (0);
}
