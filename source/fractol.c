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

#include "../fractol.h"

int	ft_check(t_vars *vars, const char *str)
{
	if (ft_strnstr(str, "Mandelbrot", 10) != 0
		|| (str[0] == '1' && !str[1]))
		vars->formula = &mandelbrot;
	else if (ft_strnstr(str, "Julia", 5) != 0
		|| (str[0] == '2' && !str[1]))
	{
		vars->formula = &julia;
		vars->mouse = 2;
	}
	else if (ft_strnstr(str, "Burning Ship", 12) != 0
		|| (str[0] == '3' && !str[1]))
		vars->formula = &burning_ship;
	else
		ft_help();
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
