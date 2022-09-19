/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:16:53 by tchalifo          #+#    #+#             */
/*   Updated: 2022/09/19 14:53:08 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* cx and cy are static values for the Julia set
 * zx and zy are dynamic values for the Julia set
 */

#include "../inc/fractol.h"

void	julia(t_formula_values *data, t_mlx *mlx_data)
{
	data->y_pos = 0;
	while (data->y_pos <= (WIN_HEIGHT))
	{
		data->cy = 0.156;
		data->x_pos = 0;
		while (data->x_pos <= (WIN_WIDTH))
		{
			data->cx = -0.8;
			data->x_pos++;
			julia_calculus(data);
			if (data->i == (FRACTAL_MAX_ITER + 1))
				my_mlx_pixel_put(mlx_data, data->x_pos, data->y_pos, 0x440000);
			else
				my_mlx_pixel_put(mlx_data, data->x_pos, data->y_pos, 0xFFF000);
		}
		data->y_pos++;
	}
}

void	julia_calculus(t_formula_values *data)
{
	long double	x_tmp;

	data->i = 1;
	data->zx = data->x_axis_offset + (data->x_pos / data->size);
	data->zy = data->y_axis_offset - (data->y_pos / data->size);
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
