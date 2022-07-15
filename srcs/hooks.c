/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:06:54 by tchalifo          #+#    #+#             */
/*   Updated: 2022/07/15 14:28:24 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	window_hooks_manager(t_mlx_data *mlx_data)
{
	mlx_hook(mlx_data->win, 17, 0, close_win, &mlx_data);
}

void	keys_hooks_manager(t_mlx_data *mlx_data, t_data *data, t_params program_params_data)
{
	if (ft_strcmp(program_params_data.uname, "Linux\n") == 0)
	{
		mlx_key_hook(mlx_data->win, key_binding_linux, &mlx_data);
	}
	else if (ft_strcmp(program_params_data.uname, "Darwin\n") == 0)
	{
		printf("ON MAC !\n");
		printf("MAIN_pixel_pos_x = %d\n", data->start_pixel_pos_x);
		printf("MAIN_pixel_pos_y = %d\n", data->start_pixel_pos_y);
		mlx_hook(mlx_data->win, 2, 3, key_binding_mac, &data);
		// mlx_loop_hook(mlx_data.mlx, key_binding_mac, &data);
	}
	else
	{
		ft_putstr_fd("Keys binding not supported on this system\n", 2);
		exit(-1);
	}
}

void	mouse_hooks_manager(t_mlx_data *mlx_data, t_data *data, t_params program_params_data)
{
	return (0);

}