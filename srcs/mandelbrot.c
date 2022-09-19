/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:56:37 by tchalifo          #+#    #+#             */
/*   Updated: 2022/09/19 11:22:30 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	mandelbrot(t_formula_values *data, t_mlx *mlx_data)
{
	data->y_pos = 0;
	while (data->y_pos <= (WIN_HEIGHT))
	{
		data->cy = data->y_axis_offset - (data->y_pos / data->size); //Dynamic value for Mandel set
		data->x_pos = 0;
		while (data->x_pos <=(WIN_WIDTH))
		{
			data->cx = data->x_axis_offset + (data->x_pos / data->size); //Dynamic value for Mandel set
			data->x_pos++;
			mandel_calculus(data);
			if (data->i == (FRACTAL_MAX_ITER + 1))
				my_mlx_pixel_put(mlx_data, data->x_pos, data->y_pos, 0x00440000);
			else
				my_mlx_pixel_put(mlx_data, data->x_pos, data->y_pos, 0x00FFF000);
		}
		data->y_pos++;
	}
}

void	mandel_calculus(t_formula_values *data)
{
	long double x_tmp;

	data->i = 1;
	data->zx = 0; //Static value for mandel
	data->zy = 0; //Static value for mandel
	while (data->i <= FRACTAL_MAX_ITER)
	{
		x_tmp = data->zx;
		data->zx = (data->zx * data->zx) - (data->zy * data->zy) + data->cx;
		data->zy = (2 * x_tmp *data->zy) + data->cy;
		if ((data->zx * data->zx) + (data->zy * data->zy) > 4)
			break;
		data->i++;
	}
}