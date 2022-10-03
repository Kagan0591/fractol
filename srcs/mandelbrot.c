/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:56:37 by tchalifo          #+#    #+#             */
/*   Updated: 2022/10/03 15:41:28 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* cx and cy are dynamic values for the Mandelbrot set
 * zx and zy are static values for the Mandelbrot set
 * Where x is reel num and y is imaginary num.
 */

#include "../inc/fractol.h"

// void	mandelbrot(t_formula_values *data, t_mlx *mlx_data)
void	mandelbrot(t_fractol *f)
{
	f->mandelbrot.y_pos = 0;
	while (f->mandelbrot.y_pos <= (WIN_HEIGHT))
	{
		f->mandelbrot.cy = f->mandelbrot.y_axis_offset \
			- (f->mandelbrot.y_pos / f->mandelbrot.size);
		f->mandelbrot.x_pos = 0;
		while (f->mandelbrot.x_pos <= (WIN_WIDTH))
		{
			f->mandelbrot.cx = f->mandelbrot.x_axis_offset \
				+ (f->mandelbrot.x_pos / f->mandelbrot.size);
			f->mandelbrot.x_pos++;
			mandel_calculus(&f->mandelbrot);
			mandel_colorisation(f);
		}
		f->mandelbrot.y_pos++;
	}
}

void	mandel_colorisation(t_fractol *f)
{
	if (f->mandelbrot.i == (FRACTAL_MAX_ITER + 1))
		my_mlx_pixel_put(&f->mlx, f->mandelbrot.x_pos, f->mandelbrot.y_pos, \
			create_trgb(0, 118, 137, 169));
	else if (f->mandelbrot.i == (FRACTAL_MAX_ITER - 1))
		my_mlx_pixel_put(&f->mlx, f->mandelbrot.x_pos, f->mandelbrot.y_pos, \
			f->f_opt.colors[1]);
	else if (f->mandelbrot.i == (FRACTAL_MAX_ITER - 3))
		my_mlx_pixel_put(&f->mlx, f->mandelbrot.x_pos, f->mandelbrot.y_pos, \
			f->f_opt.colors[2]);
	else if (f->mandelbrot.i == (FRACTAL_MAX_ITER - 5))
		my_mlx_pixel_put(&f->mlx, f->mandelbrot.x_pos, f->mandelbrot.y_pos, \
			f->f_opt.colors[3]);
	else if (f->mandelbrot.i == (FRACTAL_MAX_ITER - 7))
		my_mlx_pixel_put(&f->mlx, f->mandelbrot.x_pos, f->mandelbrot.y_pos, \
			f->f_opt.colors[4]);
	else if (f->mandelbrot.i == (FRACTAL_MAX_ITER - 9))
		my_mlx_pixel_put(&f->mlx, f->mandelbrot.x_pos, f->mandelbrot.y_pos, \
			f->f_opt.colors[5]);
	else
		my_mlx_pixel_put(&f->mlx, f->mandelbrot.x_pos, f->mandelbrot.y_pos, \
			create_trgb(0, 35, 35, 35));
}

void	mandel_calculus(t_formula_values *data)
{
	long double	x_tmp;

	data->i = 1;
	data->zx = 0;
	data->zy = 0;
	while (data->i <= FRACTAL_MAX_ITER)
	{
		x_tmp = data->zx;
		data->zx = (data->zx * data->zx) - (data->zy * data->zy) + data->cx;
		data->zy = (2 * x_tmp * data->zy) + data->cy;
		if ((data->zx * data->zx) + (data->zy * data->zy) > 4)
			break ;
		data->i++;
	}
}
