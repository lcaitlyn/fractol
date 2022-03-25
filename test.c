#include <stdio.h>
#include <math.h>

int main()
{
/*
 int x = 0;
	int flag = 0;
	int y = 0;
	while (x < 1536)
	{
		if ((x / 256) == flag + 1 && ((x % 256) == 0))
			printf ("%d\n", ++flag);
		x++;
	}
 */
	
	
/*	while (x < 1536)
	{
		y = 0;
		if ((x / 256) == 1)
		{
			flag++;
		}
			
		while (y < 256)
		{
			printf ("%d\n", (flag + 2) % 3 );
			printf ("%d\n", (flag + 1) % 3);
			printf ("%d\n\n", flag % 3);
			y++;
		}
		x++;
	}
	flag = 0;
	while (flag < 6)
	{
		printf ("%d\n", (flag + 2) % 3 );
		printf ("%d\n", (flag + 1) % 3);
		printf ("%d\n\n", flag % 3);
		flag++;
	}*/
	int x = 0;
	int y = 0;
	int max_iteration = 50;
	
	int width = 1000;
	int height = 1000;
	double min_re = -2.0;
	double max_re = 2.0;
	double min_im = -2.0;
	double max_im;
	max_im = min_im + (max_re - min_re) * height / width;
	
	double factor_re = (max_re - min_re) / (width - 1);
	double factor_im = (max_im - min_im) / (height - 1);
	
	double c_re = min_re + x * factor_re;
	double c_im = max_im - y * factor_im;
	
	y = 0;
	while (y < height)
	{
		c.im = max.im - y * factor.im;
		x = 0;
		while (x < width)
		{
			c.re = min.re + x * factor.re;
			// Формула множества Мандельброта
			// Установка цвета точки
			x++;
		}
		y++;
	}
	
	return 0;
}
