/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:27:22 by lcaitlyn          #+#    #+#             */
/*   Updated: 2022/03/11 16:27:23 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_check(t_vars *vars, const char *str)
{
	if (ft_strnstr(str, "Mandelbrot", 10) != 0)
		vars->formula = &mandelbrot;
	else
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	
	if (argc != 2)
		ft_help();
	else if (ft_check(&vars, argv[1]))
	{
		ft_init (&vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}
