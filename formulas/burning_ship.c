/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:56:18 by lcaitlyn          #+#    #+#             */
/*   Updated: 2022/03/28 15:56:31 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		burning_ship(t_vars *vars)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = init_complex(vars->c.re, vars->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iteration < vars->max_iteration)
	{
		z = init_complex(
			pow(z.re, 2.0) - pow(z.im, 2.0) + vars->c.re,
			-2.0 * fabs(z.re * z.im) + vars->c.im);
		iteration++;
	}
	return (iteration);
}
