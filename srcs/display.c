/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:18:32 by tchalifo          #+#    #+#             */
/*   Updated: 2022/06/07 17:47:03 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_vars data, int x, int y, int color)
{
	char	*dst;

	dst = data.img_addr + (y * data.line_length + x * (data.bits_per_pixel / 8));
//	printf("%s:%d\n", __FUNCTION__, __LINE__);
	*(unsigned int*)dst = color;
//	printf("%s:%d\n", __FUNCTION__, __LINE__);
}

int	write_a_square(t_vars vars)
{
	int		i;
	int		j;
	int		x = 1920/2 - 50;
	int		y = 1080/2 - 50;
	i = 0;
	j = 0;

	vars.img = mlx_new_image(vars.mlx, 1920, 1080);
	vars.img_addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length, &vars.endian);
	while (i < 100)
	{
		while (j < 100)
		{
			my_mlx_pixel_put(vars, i, j, 0x00FFFFFF);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, x, y);
	return (0);
}