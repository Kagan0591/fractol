/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:08:59 by tchalifo          #+#    #+#             */
/*   Updated: 2022/09/27 15:32:46 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* key value details
 * 123 = LEFT, 124 = Right, 125 = Down, 126 = Up, 49 = reCenter,
 * 69 = +(numpad), 78 = -(numpad)
 */

#include "../inc/fractol.h"


// AJUSTER POUR JULIA METTRE CONDITION TYPE 1 ou 2
int	key_binding_mac(int key, t_fractol *f)
{
	if (key == 53)
		fractol_exit(f);
	else if (f->f_opt.type == 1 && key == 123)
		f->mandelbrot.x_axis_offset += 0.2;
	else if (f->f_opt.type == 2 && key == 123)
		f->julia.x_axis_offset += 0.2;
	else if (f->f_opt.type == 1 && key == 124)
		f->mandelbrot.x_axis_offset -= 0.2;
	else if (f->f_opt.type == 2 && key == 124)
		f->julia.x_axis_offset -= 0.2;
	else if (f->f_opt.type == 1 && key == 125)
		f->mandelbrot.y_axis_offset += 0.2;
	else if (f->f_opt.type == 2 && key == 125)
		f->julia.y_axis_offset += 0.2;
	else if (f->f_opt.type == 1 && key == 126)
		f->mandelbrot.y_axis_offset += 0.2;
	else if (f->f_opt.type == 2 && key == 126)
		f->julia.y_axis_offset -= 0.2;
	else
		printf("Others Key pressed --> %d\n", key);
	fractal_updater(f);
	return (0);
}

int	mouse_binding_mac(int key, int x, int y, t_fractol *f)
{
	(void) x;
	(void) y;
	if (f->f_opt.type == 1 && key == 4)
		f->mandelbrot.size += 100;
	if (f->f_opt.type == 2 && key == 4)
		f->julia.size += 100;
	else if (f->f_opt.type == 1 && key == 5)
		f->mandelbrot.size -= 75;
	else if (f->f_opt.type == 2 && key == 5)
		f->julia.size -= 75;
	fractal_updater(f);
	return (0);
}

int	mouse_get_pos_mac(int x, int y, t_fractol *f)
{
	if ((x >= 0 && x <= 1280) && (y >= 0 && y <= 720))
	{
		f->mlx.mouse_pos_x = x;
		f->mlx.mouse_pos_y = y;
		printf("%d, %d\n", f->mlx.mouse_pos_x, f->mlx.mouse_pos_y);
	}
	return (0);
}
