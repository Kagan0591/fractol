/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:17:40 by tchalifo          #+#    #+#             */
/*   Updated: 2022/09/06 09:56:02 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	init_mlx(t_mlx *mlx_data)
{
	mlx_data->mlx = mlx_init();
	mlx_data->win = mlx_new_window(mlx_data->mlx, WIN_WIDTH, WIN_HEIGHT, "Thomas Fractol");
	mlx_data->img_addr = mlx_new_image(mlx_data->mlx, (WIN_WIDTH + 1), (WIN_HEIGHT + 1));
	mlx_data->pixel_addr = mlx_get_data_addr(mlx_data->img_addr, &mlx_data->bits_per_pixel, &mlx_data->line_length, &mlx_data->endian);
	mlx_data->mouse_pos_x = 0;
	mlx_data->mouse_pos_y = 0;
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->pixel_addr + (y * mlx->line_length) + (x * (mlx->bits_per_pixel / 8));
//	printf("%s:%d\n", __FUNCTION__, __LINE__);
	*(unsigned int*)dst = color;
//	printf("%s:%d\n", __FUNCTION__, __LINE__);
}

void	image_refresh(t_mlx *mlx_data)
{
	mlx_destroy_image(mlx_data->mlx, mlx_data->img_addr);
	mlx_data->img_addr = mlx_new_image(mlx_data->mlx, (WIN_WIDTH + 1), (WIN_HEIGHT + 1));
	mlx_data->pixel_addr = mlx_get_data_addr(mlx_data->img_addr, &mlx_data->bits_per_pixel, &mlx_data->line_length, &mlx_data->endian);
}

// void	mouse_pos_update(t_mlx *mlx_data)
// {
// 	mlx_mouse_get_pos(mlx_data->win, mlx_data->mouse_pos_x, mlx_data->mouse_pos_y);
// }