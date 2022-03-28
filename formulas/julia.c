/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:16:22 by lcaitlyn          #+#    #+#             */
/*   Updated: 2022/03/28 13:16:37 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int julia_motion(int x, int y, t_vars *vars)
{
	if (vars->mouse % 2 == 1)
	{
		vars->k = init_complex(
			4 * ((double)x / WIDTH - 0.5),
			4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
		draw_fractal(vars);
	}
    return (0);
}

int julia_move(int x, int y, t_vars *vars)
{
	if (vars->mouse % 2 == 1)
	{
		vars->k = init_complex(
			4 * ((double)x / WIDTH - 0.5),
			4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
		draw_fractal(vars);
	}
    return (0);
}

int	julia(t_vars *vars)
{
	int			iteration;
	t_complex	z;
	
	z = init_complex(vars->c.re, vars->c.im);
	iteration = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iteration < vars->max_iteration)
	{
		z = init_complex(
			pow(z.re, 2.0) - pow(z.im, 2.0) + vars->k.re,
			2.0 * z.re * z.im + vars->k.im);
		iteration++;
	}
	return (iteration);
}
