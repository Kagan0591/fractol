/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_key_hooks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:07:39 by tchalifo          #+#    #+#             */
/*   Updated: 2022/06/09 15:05:17 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_binding_mac(t_mlx_data mlx_data, t_data *data, int key)
{
	// printf("TEST\n");
	if (key == 53)
		exit(1);
	if (key == 123) // left
	{
		data->pixel_pos_x++;
		printf("Valeur de data->x = %d\n", data->pixel_pos_x);
		printf("Valeur de data->y = %d\n", data->pixel_pos_y);
		//mlx_destroy_image(data.mlx, data.img_addr);
		write_a_square(mlx_data, data);
	}
	// if (key == 65362) // top
	// if (key == 65363) // right
	// if (key == 65364) // down
	printf("%d\n", key);
	return (0);
}

int	key_binding_linux(t_mlx_data mlx_data, t_data *data, int key)
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

// void	displacement_left(t_vars data)
// {
// 	square_displacement_left(data);
// }

// void	displacement_top(void)
// {

// }

// void	displacement_right(void)
// {

// }

// void	displacement_down(void)
// {

// }


// linux code

// 65362 fleche haut
// 65363 fleche droite
// 65364 fleche bas
// 65361 fleche gauche
// 65307 ESC
