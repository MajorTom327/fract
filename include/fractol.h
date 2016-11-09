/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:13:49 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/09 16:40:24 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define W_WID 512
# define W_HEI 512

typedef struct	img
{
	void	*img;
	char	*data;
	int		bpp;
	int		sl;
	int		end;
	int		x;
	int		y;
}

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	void	*img;
}				t_data;

void	usage(void);
t_data	*init(void);
int		exit_fractol(void *param);
int		event(int keycode, void *param);

int		mandel(void);
#endif
