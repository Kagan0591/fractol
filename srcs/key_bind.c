/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:08:59 by tchalifo          #+#    #+#             */
/*   Updated: 2022/08/30 16:21:57 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	key_binding_mac(int key, t_fractol *f)
{
	if (key == 53)
		fractol_exit(f);
	else if (key == 123) // LEFT
	{
		f->mandelbrot.x_axis_offset += 0.2;
		printf("Key pressed --> %d\n", key);
		printf("Valeur de data->x = %Lf\n", f->mandelbrot.x_axis_offset);
	}
	else if (key == 124) // RIGHT
	{
		f->mandelbrot.x_axis_offset -= 0.2;
		printf("Key pressed --> %d\n", key);
		printf("Valeur de data->x = %Lf\n", f->mandelbrot.x_axis_offset);
	}
	else if (key == 125) // DOWN
	{
		f->mandelbrot.y_axis_offset += 0.2;
		printf("Key pressed --> %d\n", key);
		printf("Valeur de data->y = %Lf\n", f->mandelbrot.y_axis_offset);
	}
	else if (key == 126) // UP
	{
		f->mandelbrot.y_axis_offset -= 0.2;
		printf("Key pressed --> %d\n", key);
		printf("Valeur de data->y = %Lf\n", f->mandelbrot.y_axis_offset);
	}
	else if (key == 49) //RE CENTER
	{
		f->mandelbrot.x_axis_offset = -2.8;
		f->mandelbrot.y_axis_offset = 1.2;
		printf("Key pressed --> %d\n", key);
	}
	else
		printf("Others Key pressed --> %d\n", key);
	fractal_updater(f);
	return (0);
}

int	mouse_event_mac(int key, int x, int y, t_fractol *f)
{
	(void) x;
	(void) y;
	(void) f;
	if (key == 4)
		f->mandelbrot.size += 20;
	if (key == 5)
		f->mandelbrot.size -= 20;

	// Ici sa seg fault si je decommente Je suis rendu la !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// fractal_updater(f);
	// printf("%Lf\n", f->mandelbrot.size);
	printf("mouse key --> %d\n", key);
	return (0);
}
int	key_binding_linux(int key, t_mlx *mlx)
{
	(void) mlx;
	if (key == 65307)
		exit(1);
	if (key == 65361) // left
	if (key == 65362) // top
	if (key == 65363) // right
	if (key == 65364) // down
	printf("%d\n", key);
	return (0);
}
