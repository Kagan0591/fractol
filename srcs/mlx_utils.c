/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:17:40 by tchalifo          #+#    #+#             */
/*   Updated: 2022/08/15 10:18:09 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_fractol *f_struct)
{
	f_struct->mlx.mlx = mlx_init();
	f_struct->mlx.win = mlx_new_window(f_struct->mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "Thomas Fractol");
	f_struct->mlx.img_addr = mlx_new_image(f_struct->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	f_struct->mlx.pixel_addr = mlx_get_data_addr(f_struct->mlx.img_addr, &f_struct->mlx.bits_per_pixel, &f_struct->mlx.line_length, &f_struct->mlx.endian);
}

void	my_mlx_pixel_put(t_mlx *mlx_data, int x, int y, int color)
{
	char	*dst;

	dst = mlx_data->pixel_addr + (y * mlx_data->line_length) + (x * (mlx_data->bits_per_pixel / 8));
//	printf("%s:%d\n", __FUNCTION__, __LINE__);
	*(unsigned int*)dst = color;
//	printf("%s:%d\n", __FUNCTION__, __LINE__);
}