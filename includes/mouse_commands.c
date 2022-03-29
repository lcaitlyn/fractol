/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:11:20 by lcaitlyn          #+#    #+#             */
/*   Updated: 2022/03/25 19:11:30 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

int	mouse_commands(int button, int x, int y, t_vars *vars)
{
	t_complex	mouse;
	double		interpolation;
	double		zoom;

	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
	{
		mouse = init_complex(
			(double)x / (WIDTH / (vars->max.re - vars->min.re))
				+ vars->min.re,
			(double)y / (HEIGHT / (vars->max.im - vars->min.im))
				* -1 + vars->max.im);
		if (button == MOUSE_SCROLL_DOWN)
			zoom = 0.80;
		else
			zoom = 1.20;
		interpolation = 1.0 / zoom;
		vars->min.re = interpolate(mouse.re, vars->min.re, interpolation);
		vars->min.im = interpolate(mouse.im, vars->min.im, interpolation);
		vars->max.re = interpolate(mouse.re, vars->max.re, interpolation);
		vars->max.im = interpolate(mouse.im, vars->max.im, interpolation);
		draw_fractal(vars);
	}
//	if ()
	return (0);
}
