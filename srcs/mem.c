/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:45:28 by tchalifo          #+#    #+#             */
/*   Updated: 2022/07/15 10:07:11 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data	*init_struct_data(void)
{
	t_data	*data;
	data = malloc(sizeof(t_data));
	data->start_pixel_pos_x = 0;
	data->start_pixel_pos_y = 0;
	return (data);
}

t_mlx_data *init_struct_mlx_data(void)
{
	t_mlx_data	*mlx_data;
	mlx_data = malloc(sizeof(t_mlx_data));
	mlx_data->mlx = NULL;
	mlx_data->win = NULL;
	mlx_data->img_addr = NULL;
	mlx_data->pixel_addr = NULL;
	mlx_data->bits_per_pixel = 0;
	mlx_data->line_length = 0;
	mlx_data->endian = 0;
	return (mlx_data);
}
