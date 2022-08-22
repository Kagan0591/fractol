/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_testing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 09:54:56 by tchalifo          #+#    #+#             */
/*   Updated: 2022/08/22 11:06:20 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	write_a_square(t_mlx *mlx, int size_x, int size_y, int init_x_pos, int init_y_pos)
{
	int	x_pos;
	int	y_pos;

	x_pos = init_x_pos;
	y_pos = init_y_pos;
	while (y_pos < (size_y + init_y_pos))
	{
		x_pos = init_x_pos;
		while (x_pos < (size_x + init_x_pos))
		{
			my_mlx_pixel_put(mlx, x_pos, y_pos, 0x00FAFF0D);
			x_pos++;
		}
		y_pos++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_addr, 0, 0);
	return (0);
}