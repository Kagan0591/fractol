/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_fractals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:24:44 by tchalifo          #+#    #+#             */
/*   Updated: 2022/09/19 10:26:09 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

/*
 * A simple draw of a mandelbrot in terminal to visualize the result in one function.
 * Based on the formula : f{z} = (z * z) + c
 */
// void	draw_mandelbrot_cli(void)
// {
// 	int pos_x;
// 	int pos_y;
// 	int i;
// 	long double n; //size
// 	long double cx;
// 	long double cy;
// 	long double zx;
// 	long double zy;
// 	long double tmp_x;

// 	pos_y = 0;
// 	n = 15;
// 	while (pos_y <= (4 * n))
// 	{
// 		cy = 2 - (pos_y / n);
// 		pos_x = 0;

// 		while (pos_x <= (4 * n))
// 		{
// 			cx = -2 + (pos_x / n);
// 			pos_x++;
// 			i = 1;
// 			zx = 0;
// 			zy = 0;
// 			while (i<=1000)
// 			{
// 				tmp_x = zx;
// 				zx = (zx * zx) - (zy * zy) + cx;
// 				zy = (2 * tmp_x * zy) + cy;
// 				if ((zx * zx) + (zy * zy) > 4)
// 					break;
// 				i++;
// 			}
// 			if (i == 1001)
// 				printf(".");
// 			else
// 				printf(" ");
// 		}
// 		pos_y++;
// 		printf("\n");
// 	}
// }

/*
 * A simple draw of a mandelbrot in terminal to visualize the result using data struct.
 * Based on the formula : f{z} = (z * z) + c
 */
void	draw_mandelbrot_cli(t_fractol *f)
{
	long double x_tmp;

	f->mandelbrot.y_pos = 0;
	f->mandelbrot.size = 15;
	while (f->mandelbrot.y_pos <= 4 * f->mandelbrot.size)// WIN_HEIGHT)
	{
		f->mandelbrot.cy = 2 - (f->mandelbrot.y_pos / f->mandelbrot.size);
		f->mandelbrot.x_pos = 0;
		while (f->mandelbrot.x_pos <= 4 * f->mandelbrot.size)// WIN_WIDTH)
		{
			f->mandelbrot.cx = -2 + (f->mandelbrot.x_pos / f->mandelbrot.size);
			f->mandelbrot.x_pos++;
			f->mandelbrot.i = 1;
			f->mandelbrot.zx = 0;
			f->mandelbrot.zy = 0;
			while (f->mandelbrot.i <= 1000)
			{
				x_tmp = f->mandelbrot.zx;
				f->mandelbrot.zx = (f->mandelbrot.zx * f->mandelbrot.zx) - (f->mandelbrot.zy * f->mandelbrot.zy) + f->mandelbrot.cx;
				f->mandelbrot.zy = (2 * x_tmp *f->mandelbrot.zy) + f->mandelbrot.cy;
				if ((f->mandelbrot.zx * f->mandelbrot.zx) + (f->mandelbrot.zy * f->mandelbrot.zy) > 4)
				{
					break;
				}
				f->mandelbrot.i++;
			}
			if (f->mandelbrot.i == 1001)
				printf(".");
			else
				printf(" ");
		}
		f->mandelbrot.y_pos++;
		printf("\n");
	}
}