/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:47:20 by lcaitlyn          #+#    #+#             */
/*   Updated: 2022/03/25 17:47:34 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	win_close(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
	return (0);
}

void	ft_help(void)
{
	write (1, "\nPlease choose set:\n", 20);
	write (1, "\tâ Mandelbrot[1] ğ\n", 25);
	write (1, "\tâ Julia[2] ğ\n", 20);
	write (1, "\tâ Burning Ship[3] ğ\n", 26);
	write (1, "./fractol [<id> or <name>]\n\n", 29);
	exit (0);
}
