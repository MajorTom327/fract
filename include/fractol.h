/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:13:49 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/10 17:26:35 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define W_WID 767
# define W_HEI 767

typedef struct	s_v2
{
	int			x;
	int			y;
}				t_v2;

typedef struct	s_img
{
	void		*img;
	char		*data;
	int			bpp;
	int			sl;
	int			end;
	t_v2		size;
}				t_img;

typedef struct	s_fract
{
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	t_v2	zoom;
	int		ite;
}				t_fract;

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_fract		*fract;
}				t_data;

void	img_put_px(t_img *img, unsigned long c, t_v2 p);

void	usage(void);
t_data	*init(void);
int		exit_fractol(void *param);
int		event(int keycode, void *param);

int		mandel(void);

int	exp_mandel(void *param);
#endif
