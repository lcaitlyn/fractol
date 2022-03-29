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

#include "../fractol.h"

void	help(t_vars *vars)
{
	vars->mouse = 2;
	mlx_clear_window(vars->mlx, vars->win);
	mlx_string_put(vars->mlx, vars->win,
		WIDTH / 4, HEIGHT / 4, 0x00FFFFFF, "H - Help");
	mlx_string_put(vars->mlx, vars->win,
		(WIDTH / 4), (HEIGHT / 4) + 30, 0x00FFFFFF, "R - Reset");
	mlx_string_put(vars->mlx, vars->win,
		(WIDTH / 4), (HEIGHT / 4) + 60,
		0x00FFFFFF, "+/- Add/Remove max iterations");
	mlx_string_put(vars->mlx, vars->win,
		(WIDTH / 4), (HEIGHT / 4) + 90, 0x00FFFFFF,
		"Arrows UP/DOWN/LEFT/RIGHT - Move");
	mlx_string_put(vars->mlx, vars->win,
		(WIDTH / 4), (HEIGHT / 4) + 120, 0x00FFFFFF,
		"Scroll UP/DOWN - Zoom");
	mlx_string_put(vars->mlx, vars->win,
		(WIDTH / 4), (HEIGHT / 4) + 150, 0x00FFFFFF,
		"Space - Unlock mousemove (Only in Julia!)");
	mlx_string_put(vars->mlx, vars->win,
		(WIDTH / 4), (HEIGHT / 4) + 180, 0x00FFFFFF, "Esc - Quit");
}

void	key_move(int key, t_vars *vars)
{
	t_complex	delta;

	delta = init_complex(fabs(vars->max.re - vars->min.re),
			fabs(vars->max.im - vars->min.im));
	if (key == ARROW_LEFT)
	{
		vars->min.re -= delta.re * 0.05;
		vars->max.re -= delta.re * 0.05;
	}
	else if (key == ARROW_RIGHT)
	{
		vars->min.re += delta.re * 0.05;
		vars->max.re += delta.re * 0.05;
	}
	else if (key == ARROW_UP)
	{
		vars->min.im += delta.re * 0.05;
		vars->max.im += delta.re * 0.05;
	}
	else if (key == ARROW_DOWN)
	{
		vars->min.im -= delta.re * 0.05;
		vars->max.im -= delta.re * 0.05;
	}
}

int	key_commands(int key, t_vars *vars)
{
	if (key == KEY_ESC)
		win_close(vars);
	if (key == KEY_C)
		vars->color_shift++;
	if (key == KEY_PLUS || key == NUM_PAD_PLUS)
		vars->max_iteration++;
	if ((key == KEY_MINUS || key == NUM_PAD_MINUS) && vars->max_iteration > 2)
		vars->max_iteration--;
	if (key == KEY_SPACE)
		vars->mouse++;
	if (key == KEY_R)
		set_default(vars);
	if (key == ARROW_UP || key == ARROW_DOWN
		|| key == ARROW_LEFT || key == ARROW_RIGHT)
		key_move(key, vars);
	if (key == KEY_H)
		help(vars);
	else
		draw_fractal(vars);
	return (0);
}
