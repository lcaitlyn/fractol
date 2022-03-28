/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:49:25 by lcaitlyn          #+#    #+#             */
/*   Updated: 2022/03/25 18:49:34 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, char *color)
{
	int		i;

	i = y * data->line_length + x * (data->bits_per_pixel / 8);
	data->addr[i] = (char)color[2];			// blue
	data->addr[++i] = (char)color[1];		// green
	data->addr[++i] = (char)color[0];		// red
	data->addr[++i] = 0;					// transparency
}

void	draw_fractal(t_vars *vars)
{
	int			iteration;
	t_complex	factor;
	int x;
	int y;
	
	
	factor.re = (vars->max.re - vars->min.re) / (WIDTH - 1);
	factor.im = (vars->max.im - vars->min.im) / (HEIGHT - 1);
	y = 0;
		while (y < HEIGHT)
		{
			vars->c.im = vars->max.im - y * factor.im;
			x = 0;
			while (x < WIDTH)
			{
				vars->c.re = vars->min.re + x * factor.re;
				get_color(vars->formula(vars), vars);
				my_mlx_pixel_put(&vars->img, x, y, vars->color);
				x++;
			}
			y++;
		}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	mlx_string_put(vars->mlx, vars->win, WIDTH - 100, HEIGHT - 30, 0x00FFFFFF, "H - Help");
}
