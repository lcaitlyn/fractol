/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:36:23 by lcaitlyn          #+#    #+#             */
/*   Updated: 2022/03/25 18:36:32 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

void	set_default(t_vars *vars)
{
	vars->max_iteration = 30;
	vars->min = init_complex(-2.0, -2.0);
	vars->max.re = 2.0;
	vars->max.im = vars->min.im
		+ (vars->max.re - vars->min.re) * HEIGHT / WIDTH;
	vars->color_shift = 0;
	vars->k = init_complex(-0.4, -0.6);
	vars->mouse = 2;
}

void	ft_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "lcaitlyn's fractol");
	vars->img.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
	mlx_hook(vars->win, 2, 0, key_commands, vars);
	mlx_hook(vars->win, 17, 0, win_close, vars);
	mlx_hook(vars->win, 4, 0, mouse_commands, vars);
	if (vars->mouse == 2)
		mlx_hook(vars->win, 6, 0, julia_motion, vars);
	set_default(vars);
	draw_fractal(vars);
}
