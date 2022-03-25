/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:28:37 by lcaitlyn          #+#    #+#             */
/*   Updated: 2022/03/22 16:28:38 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_commands(int key, t_vars *vars)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_image(vars->mlx, vars->img.img);
		mlx_destroy_window(vars->mlx, vars->win);
		exit (0);
	}
	if (key == KEY_C)
	{
		vars->color_shift++;
	}
	if (key == KEY_PLUS || key == NUM_PAD_PLUS)
	{
		if (vars->max_iteration < 50)
			vars->max_iteration += 1;
		else if (vars->max_iteration < 1000000000)
			vars->max_iteration = (int)(vars->max_iteration * 1.05);
	}
	draw_fractal(vars);
	return (0);
}
