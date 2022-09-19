/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:08:59 by tchalifo          #+#    #+#             */
/*   Updated: 2022/09/19 14:59:10 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* key value details
 * 123 = LEFT, 124 = Right, 125 = Down, 126 = Up, 49 = reCenter,
 * 69 = +(numpad), 78 = -(numpad)
 */

#include "../inc/fractol.h"

int	key_binding_mac(int key, t_fractol *f)
{
	if (key == 53)
		fractol_exit(f);
	else if (key == 123)
		f->mandelbrot.x_axis_offset += 0.2;
	else if (key == 124)
		f->mandelbrot.x_axis_offset -= 0.2;
	else if (key == 125)
		f->mandelbrot.y_axis_offset += 0.2;
	else if (key == 126)
		f->mandelbrot.y_axis_offset -= 0.2;
	else if (key == 49)
	{
		f->mandelbrot.x_axis_offset = -2.8;
		f->mandelbrot.y_axis_offset = 1.2;
	}
	else if (key == 69)
		f->mandelbrot.size += 50;
	else if (key == 78)
		f->mandelbrot.size -= 50;
	else
		printf("Others Key pressed --> %d\n", key);
	fractal_updater(f);
	return (0);
}

int	mouse_binding_mac(int key, int x, int y, t_fractol *f)
{
	(void) x;
	(void) y;
	if (key == 4)
		f->mandelbrot.size += 50;
	else if (key == 5)
		f->mandelbrot.size -= 50;
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
