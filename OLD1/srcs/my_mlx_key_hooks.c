/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_key_hooks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:07:39 by tchalifo          #+#    #+#             */
/*   Updated: 2022/08/13 14:34:19 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_binding_mac(int key, t_mlx_data *mlx_data, t_data *data)
{
	// printf("TEST\n");
	// key  = 0;
	(void) mlx_data;
	if (key == 53)
		exit(1);
	else if (key == 123) // LEFT
	{
		printf("Valeur de data->x = %d\n", data->start_pixel_pos_x);
		// data->start_pixel_pos_x--;
		printf("Key pressed --> %d\n", key);
		// printf("Valeur de data->x = %d\n", data->pixel_pos_x);
		// printf("Valeur de data->y = %d\n", data->pixel_pos_y);
	}
	else if (key == 124) // RIGHT
	{
		printf("Valeur de data->x = %d\n", data->start_pixel_pos_x);
		// data->start_pixel_pos_x++;
		printf("Key pressed --> %d\n", key);
		// printf("Valeur de data->x = %d\n", data->pixel_pos_x);
		// printf("Valeur de data->y = %d\n", data->pixel_pos_y);
	}
	else if (key == 125) // DOWN
	{
		printf("Valeur de data->x = %d\n", data->start_pixel_pos_x);
		// data->start_pixel_pos_y++;
		printf("Key pressed --> %d\n", key);
		// printf("Valeur de data->x = %d\n", data->pixel_pos_x);
		// printf("Valeur de data->y = %d\n", data->pixel_pos_y);
	}
	else if (key == 126) // UP
	{
		// printf("Valeur de data->x = %d\n", data->pixel_pos_x);
		printf ("%d\n", data->start_pixel_pos_y);
		// data->start_pixel_pos_y--;
		printf("Key pressed --> %d\n", key);
		// printf("Valeur de data->x = %d\n", data->pixel_pos_x);
		// printf("Valeur de data->y = %d\n", data->pixel_pos_y);
	}
	else
		printf("Others Key pressed --> %d\n", key);
	// mlx_destroy_image(mlx_data->mlx, mlx_data->img_addr);
	return (0);
}

int	key_binding_linux(int key, t_mlx_data mlx_data, t_data *data)
{
	(void) data;
	(void) mlx_data;
	if (key == 65307)
		exit(1);
	// if (key == 65361) // left
	// 	displacement_left(data);
	// if (key == 65362) // top
	// if (key == 65363) // right
	// if (key == 65364) // down
	printf("%d\n", key);
	return (0);
}
