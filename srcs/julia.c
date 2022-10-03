/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:16:53 by tchalifo          #+#    #+#             */
/*   Updated: 2022/10/03 15:52:30 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* cx and cy are static values for the Julia set
 * zx and zy are dynamic values for the Julia set
 * Where x is reel num and y is imaginary num.
 */

#include "../inc/fractol.h"

void	julia(t_fractol *f)
{
	f->julia.y_pos = 0;
	while (f->julia.y_pos <= (WIN_HEIGHT))
	{
		f->julia.cy = 0.3842;
		f->julia.x_pos = 0;
		while (f->julia.x_pos <= (WIN_WIDTH))
		{
			f->julia.cx = -0.70176;
			f->julia.x_pos++;
			julia_calculus(&f->julia);
			julia_colorisation(f);
		}
		f->julia.y_pos++;
	}
}

void	julia_colorisation(t_fractol *f)
{
	if (f->julia.i == (FRACTAL_MAX_ITER + 1))
		my_mlx_pixel_put(&f->mlx, f->julia.x_pos, f->julia.y_pos, \
			create_trgb(0, 151, 117, 170));
	else if (f->julia.i == (FRACTAL_MAX_ITER))
		my_mlx_pixel_put(&f->mlx, f->julia.x_pos, f->julia.y_pos, \
			f->f_opt.colors[1]);
	else if (f->julia.i == (FRACTAL_MAX_ITER - 1))
		my_mlx_pixel_put(&f->mlx, f->julia.x_pos, f->julia.y_pos, \
			f->f_opt.colors[2]);
	else if (f->julia.i == (FRACTAL_MAX_ITER - 2))
		my_mlx_pixel_put(&f->mlx, f->julia.x_pos, f->julia.y_pos, \
			f->f_opt.colors[3]);
	else if (f->julia.i == (FRACTAL_MAX_ITER - 3))
		my_mlx_pixel_put(&f->mlx, f->julia.x_pos, f->julia.y_pos, \
			f->f_opt.colors[4]);
	else if (f->julia.i == (FRACTAL_MAX_ITER - 4))
		my_mlx_pixel_put(&f->mlx, f->julia.x_pos, f->julia.y_pos, \
			f->f_opt.colors[5]);
	else
		my_mlx_pixel_put(&f->mlx, f->julia.x_pos, f->julia.y_pos, \
			create_trgb(0, 35, 35, 35));
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
