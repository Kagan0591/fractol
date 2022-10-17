/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 08:15:40 by tchalifo          #+#    #+#             */
/*   Updated: 2022/10/17 17:09:00 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	mandelbrot_init(t_formula_values *data)
{
	data->size = 200;
	data->x_axis_offset = -2.8;
	data->y_axis_offset = 1.2;
}

void	julia_init(t_formula_values *data)
{
	data->size = 200;
	data->x_axis_offset = -2.8;
	data->y_axis_offset = 1.2;
	// data->cy = 0.3842;
	// data->cx = -0.7017;
	// data->cy = 0.1889;
	// data->cx = -0.7269;
	// data->cy = 0.2000;
	// data->cx = -0.8500;
	data->cy = 0;
	data->cx = -1;
}

void	fractal_updater(t_fractol *f)
{
	if (f->f_opt.type == 1)
		mandelbrot(f);
	else if (f->f_opt.type == 2)
		julia(f);
	mlx_put_image_to_window(f->mlx.mlx, f->mlx.win, f->mlx.img_addr, 0, 0);
}
