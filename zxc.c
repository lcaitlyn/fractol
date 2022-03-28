#include "fractol.h"
#include <pthread.h>

t_complex init_complex(double re, double im)
{
    t_complex complex;
    
    complex.re = re;
    complex.im = im;
    return (complex);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, char *color)
{
	int		i;

	i = y * data->line_length + x * (data->bits_per_pixel / 8);
	data->addr[i] = (char)color[2];		// blue
	data->addr[++i] = (char)color[1];		// green
	data->addr[++i] = (char)color[0];		// red
	data->addr[++i] = 0;			// transparency
}


int	win_close(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
	return (0);
}

int move(int x, int y, t_vars *vars)
{
//	if (x > 0 && y > 0)
	//	write (1, "Hello", 5);
	return (0);
}

int	key_contols(int key, t_vars *vars)
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



void	draw_fractal(t_vars *vars)
{
	int			iteration;
	t_complex	factor;
	
	int x = 0;
	int y = 0;
	
	factor.re = (vars->max.re - vars->min.re) / (WIDTH - 1);
	factor.im = (vars->max.im - vars->min.im) / (HEIGHT - 1);
	mlx_destroy_image(vars->mlx, vars->img.img);
	vars->img.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	
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
	mlx_string_put(vars->mlx, vars->win, WIDTH - 100, HEIGHT - 30, 0x00FFFFFF,
	"H - Help");
 
}
	
void	set_default(t_vars *vars)
{
	vars->max_iteration = 50;
	vars->min = init_complex(-2.0, -2.0);
	vars->max.re = 2.0;
	vars->max.im = vars->min.im + (vars->max.re - vars->min.re) * HEIGHT / WIDTH;
	vars->color_shift = 0;
	vars->formula = &mandelbrot;
}


int main()
{
	
	void *mlx;
	void *win;
	t_vars vars;
	t_data img;
	
	pthread_t	thread;
	
	int flag = 0;
	
	
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "zxc");
	img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
		&img.line_length, &img.endian);
	vars.img = img;
//	vars->mlx = mlx;
//	vars->win = win;
	mlx_hook(vars.win, 2, 0, key_contols, &vars);
	mlx_hook(vars.win, 17, 0, win_close, &vars);
	mlx_hook(vars.win, 6, 0, move, &vars);
	mlx_hook(vars.win, 4, 0, mouse_commands, &vars);
	
	set_default(&vars);
//	pthread_create (&thread, NULL, (void *(*)(void *))draw_fractal, (void *)&vars);
//	pthread_join (thread, NULL);
	draw_fractal(&vars);
	
	
	
	

	

	
/*
	x = 300;
	y = 400;
	c.im = max.im - y * factor.im;
	c.re = min.re + x * factor.re;
	z = init_complex(c.re, c.im);
	iteration = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		   && iteration < max_iteration)
	{
		printf ("X= %f Y=%f", pow(z.re, 2.0) - pow(z.im, 2.0) + c.re,
				2.0 * z.re * z.im + c.im);
		z = init_complex(
		pow(z.re, 2.0) - pow(z.im, 2.0) + c.re,
						 2.0 * z.re * z.im + c.im);
		iteration++;
	}
	
	t = (double)iteration / (double)max_iteration;
	printf ("iter = %d t = %f", iteration, t);
	color[0] = (int)(9 * (1 - t) * pow(t, 3) * 255);
	color[1] = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color[2] = (int)(8.5 * pow((1 - t), 3) * t * 255);
				my_mlx_pixel_put(&vars.img, x, y, color);
				printf ("r = %d  g = %d  b =%d\n", color[0], color[1], color[2]);
*/
	
	
	
	mlx_loop(vars.mlx);
	return (0);
}
