/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:18:32 by tchalifo          #+#    #+#             */
/*   Updated: 2022/06/08 13:39:01 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_vars data, int x, int y, int color)
{
	char	*dst;

	dst = data.pixel_addr + (y * data.line_length + x * (data.bits_per_pixel / 8));
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

	vars.img_addr = mlx_new_image(vars.mlx, 1920, 1080);
	vars.pixel_addr = mlx_get_data_addr(vars.img_addr, &vars.bits_per_pixel, &vars.line_length, &vars.endian);
	while (i < 100)
	{
		while (j < 100)
		{
			my_mlx_pixel_put(vars, i, j, 0x00FAFF0D);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img_addr, x, y);
	return (0);
}
