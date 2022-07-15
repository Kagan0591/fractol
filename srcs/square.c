/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:36:09 by tchalifo          #+#    #+#             */
/*   Updated: 2022/07/15 11:09:41 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_a_square(t_mlx_data *mlx_data, t_data *data)
{
	mlx_data->img_addr = mlx_new_image(mlx_data->mlx, 1920, 1080);
	write_a_square(mlx_data, data, data->start_pixel_pos_x, data->start_pixel_pos_y);

}

int	write_a_square(t_mlx_data *mlx_data, t_data *data, int x, int y)
{
	int	square_size_width;
	int	square_size_height;
	int	x_cpy;
	int	y_cpy;

	square_size_width = 0;
	square_size_height = 0;
	x_cpy = x;
	y_cpy = y;
	mlx_data->pixel_addr = mlx_get_data_addr(mlx_data->img_addr, &mlx_data->bits_per_pixel, &mlx_data->line_length, &mlx_data->endian);
	while (square_size_width < 100)
	{
		y_cpy = data->start_pixel_pos_y;
		square_size_height = 0;
		while (square_size_height < 100)
		{
			my_mlx_pixel_put(mlx_data, x_cpy, y_cpy, 0x00FAFF0D);
			y_cpy++;
			square_size_height++;
		}
		x_cpy++;
		square_size_width++;
	}
	// mlx_put_image_to_window(mlx_data.mlx, mlx_data.win, mlx_data.img_addr, ((1920/2)-50), ((1080/2)-50));
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->img_addr, 0, 0);
	return (0);
}

// void	square_displacement_left(t_vars data)
// {
// 	// printf("Valeur de data.x = %d", data.x);
// 	// printf("Valeur de data.y = %d", data.y);
// 	data.x++;
// 	mlx_destroy_image(data.mlx, data.img_addr);
// 	data.img_addr = mlx_new_image(data.mlx, 1920, 1080);
// 	data.pixel_addr = mlx_get_data_addr(data.img_addr, &data.bits_per_pixel, &data.line_length, &data.endian);
// 	while (data.x < 100)
// 	{
// 		while (data.y < 100)
// 		{
// 			my_mlx_pixel_put(data, data.x , data.y, 0x00FAFF0D);
// 			data.y++;
// 		}
// 		data.y = 0;
// 		data.x++;
// 	}
// 	mlx_put_image_to_window(data.mlx, data.win, data.img_addr, ((1920/2)-50), ((1080/2)-50));
// }
