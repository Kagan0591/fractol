/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 08:15:40 by tchalifo          #+#    #+#             */
/*   Updated: 2022/08/29 16:03:59 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	mandelbrot(t_fractol *f)
{
	long double x_tmp;

	f->mandelbrot.y_pos = 0;
	f->mandelbrot.size = 300;
	while (f->mandelbrot.y_pos <= (WIN_HEIGHT))
	{
		f->mandelbrot.cy =  1.2- (f->mandelbrot.y_pos / f->mandelbrot.size); // 1.2 = la position du plan cartesien dans l image
		f->mandelbrot.x_pos = 0;
		while (f->mandelbrot.x_pos <=(WIN_WIDTH))
		{
			f->mandelbrot.cx = -2.8 + (f->mandelbrot.x_pos / f->mandelbrot.size); // 2.8 = la position du plan cartesien dans l image
			f->mandelbrot.x_pos++;
			f->mandelbrot.i = 1;
			f->mandelbrot.zx = 0;
			f->mandelbrot.zy = 0;
			/*
			 * Calculus
			 */
			while (f->mandelbrot.i <= FRACTAL_ITER)
			{
				x_tmp = f->mandelbrot.zx;
				f->mandelbrot.zx = (f->mandelbrot.zx * f->mandelbrot.zx) - (f->mandelbrot.zy * f->mandelbrot.zy) + f->mandelbrot.cx;
				f->mandelbrot.zy = (2 * x_tmp *f->mandelbrot.zy) + f->mandelbrot.cy;
				if ((f->mandelbrot.zx * f->mandelbrot.zx) + (f->mandelbrot.zy * f->mandelbrot.zy) > 4)
					break;
				f->mandelbrot.i++;
			}
			/*
			 * End of calculus
			 */
			if (f->mandelbrot.i == (FRACTAL_ITER + 1))
			{
				my_mlx_pixel_put(&f->mlx, f->mandelbrot.x_pos, f->mandelbrot.y_pos, 0x00550000); //RED
				// printf("."); // black pixel here !
			}
			else
			{
				// printf(" "); // Edge, so some colors here !
				my_mlx_pixel_put(&f->mlx, f->mandelbrot.x_pos, f->mandelbrot.y_pos, 0x00FF0000); //Yellow
			}
		}
		f->mandelbrot.y_pos++;
	}
}
