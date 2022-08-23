/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:17:40 by tchalifo          #+#    #+#             */
/*   Updated: 2022/08/23 15:41:45 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_fractol *f)
{
	f->mlx.mlx = mlx_init();
	f->mlx.win = mlx_new_window(f->mlx.mlx, 1920, 1080, "Thomas Fractol");
	f->mlx.img_addr = mlx_new_image(f->mlx.mlx, (WIN_WIDTH + 1), (WIN_HEIGHT + 1));
	f->mlx.pixel_addr = mlx_get_data_addr(f->mlx.img_addr, &f->mlx.bits_per_pixel, &f->mlx.line_length, &f->mlx.endian);
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->pixel_addr + (y * mlx->line_length) + (x * (mlx->bits_per_pixel / 8));
//	printf("%s:%d\n", __FUNCTION__, __LINE__);
	*(unsigned int*)dst = color;
//	printf("%s:%d\n", __FUNCTION__, __LINE__);
}