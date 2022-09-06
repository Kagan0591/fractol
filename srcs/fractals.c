/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 08:15:40 by tchalifo          #+#    #+#             */
/*   Updated: 2022/09/06 16:43:59 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	mandelbrot_init(t_formula_values *data)
{
// 	data->x_pos = 0;
// 	data->y_pos = 0;
// 	data->i = 1;
	data->size = 200;
	data->x_axis_offset = -2.8;
	data->y_axis_offset = 1.2;
}

void	julia_init(t_formula_values *data)
{
// 	data->x_pos = 0;
// 	data->y_pos = 0;
// 	data->i = 1;
	data->size = 100;
	data->x_axis_offset = -2.8;
	data->y_axis_offset = 1.2;
}

void	fractal_updater(t_fractol *f)
{
	// image_refresh(&f->mlx);
	if (f->f_opt.type == 1)
		mandelbrot(&f->mandelbrot, &f->mlx);
	else if (f->f_opt.type == 2)
		julia(&f->mandelbrot, &f->mlx);
	mlx_put_image_to_window(f->mlx.mlx, f->mlx.win, f->mlx.img_addr, 0, 0);
}

void	mandelbrot(t_formula_values *data, t_mlx *mlx_data)
{
	long double x_tmp;

	data->y_pos = 0;
	// printf("%Lf | %Lf\n",data->y_axis_offset, data->x_axis_offset);
	while (data->y_pos <= (WIN_HEIGHT))
	{
		data->cy = data->y_axis_offset - (data->y_pos / data->size);
		data->x_pos = 0;
		while (data->x_pos <=(WIN_WIDTH))
		{
			data->cx = data->x_axis_offset + (data->x_pos / data->size);
			data->x_pos++;
			data->i = 1;
			data->zx = 0;
			data->zy = 0;
			/*
			 * Calculus
			 */
			while (data->i <= FRACTAL_MAX_ITER)
			{
				x_tmp = data->zx;
				data->zx = (data->zx * data->zx) - (data->zy * data->zy) + data->cx;
				data->zy = (2 * x_tmp *data->zy) + data->cy;
				if ((data->zx * data->zx) + (data->zy * data->zy) > 4)
					break;
				data->i++;
			}
			/*
			 * End of calculus
			 */
			if (data->i == (FRACTAL_MAX_ITER + 1))
			{
				my_mlx_pixel_put(mlx_data, data->x_pos, data->y_pos, 0x00440000); //Dark RED
				// printf("."); // black pixel here !
			}
			else
			{
				// printf(" "); // Edge, so some colors here !
				my_mlx_pixel_put(mlx_data, data->x_pos, data->y_pos, 0x00FFF000); //Yellow
			}
		}
		data->y_pos++;
	}
}

void	julia(t_formula_values *data, t_mlx *mlx_data)
{
	long double x_tmp;

	data->y_pos = 0;
	// printf("%Lf | %Lf\n",data->y_axis_offset, data->x_axis_offset);
	while (data->y_pos <= (WIN_HEIGHT))
	{
		data->cy = 0.156;
		data->x_pos = 0;
		while (data->x_pos <=(WIN_WIDTH))
		{
			data->cx = -0.8;
			data->x_pos++;
			data->i = 1;
			data->zx = data->x_axis_offset + (data->x_pos / data->size);
			data->zy = data->y_axis_offset - (data->y_pos / data->size);
			/*
			 * Calculus
			 */
			while (data->i <= FRACTAL_MAX_ITER)
			{
				x_tmp = data->zx;
				data->zx = (data->zx * data->zx) - (data->zy * data->zy) + data->cx;
				data->zy = (2 * x_tmp *data->zy) + data->cy;
				if ((data->zx * data->zx) + (data->zy * data->zy) > 4)
					break;
				data->i++;
			}
			/*
			 * End of calculus
			 */
			if (data->i == (FRACTAL_MAX_ITER + 1))
			{
				my_mlx_pixel_put(mlx_data, data->x_pos, data->y_pos, 0x00440000); //Dark RED
				// printf("."); // black pixel here !
			}
			else
			{
				// printf(" "); // Edge, so some colors here !
				my_mlx_pixel_put(mlx_data, data->x_pos, data->y_pos, 0x00FFF000); //Yellow
			}
		}
		data->y_pos++;
	}
}
