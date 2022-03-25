/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:50:37 by lcaitlyn          #+#    #+#             */
/*   Updated: 2022/03/23 15:50:59 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mandelbrot(t_vars *vars)
{
	int iteration;
	t_complex	z;
	
	z = init_complex(vars->c.re, vars->c.im);
	iteration = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iteration < vars->max_iteration)
	{
		z = init_complex(
			pow(z.re, 2.0) - pow(z.im, 2.0) + vars->c.re,
			2.0 * z.re * z.im + vars->c.im);
		iteration++;
	}
	return (iteration);
}
