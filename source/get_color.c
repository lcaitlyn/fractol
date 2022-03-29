/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:02:04 by lcaitlyn          #+#    #+#             */
/*   Updated: 2022/03/25 17:02:16 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	get_color(int iteration, t_vars *vars)
{
	double	t;

	t = (double)iteration / (double)vars->max_iteration;
	vars->color[(0 + vars->color_shift) % 3]
		= (int)(9 * (1 - t) * pow(t, 3) * 255);
	vars->color[(1 + vars->color_shift) % 3]
		= (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	vars->color[(2 + vars->color_shift) % 3]
		= (int)(8.5 * pow((1 - t), 3) * t * 255);
}
