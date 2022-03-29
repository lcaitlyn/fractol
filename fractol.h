/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:26:11 by lcaitlyn          #+#    #+#             */
/*   Updated: 2022/03/11 17:26:12 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "keys.h"

# define WIDTH 600
# define HEIGHT 600

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_data		img;
	int			max_iteration;
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	t_complex	c;
	t_complex	k;
	int			mouse;
	int			color_shift;
	char		color[3];
	int			(*formula)(struct s_vars *vars);
}	t_vars;

char		*ft_strnstr(const char *s1, const char *s2, int n);

void		ft_help(void);
int			win_close(t_vars *vars);

int			key_commands(int key, t_vars *vars);
int			mouse_commands(int button, int x, int y, t_vars *vars);
int			julia_motion(int x, int y, t_vars *vars);

void		draw_fractal(t_vars *vars);

void		get_color(int iteration, t_vars *vars);

void		ft_init(t_vars *vars);
void		set_default(t_vars *vars);
t_complex	init_complex(double re, double im);

int			mandelbrot(t_vars *vars);
int			julia(t_vars *vars);
int			burning_ship(t_vars *vars);

#endif
