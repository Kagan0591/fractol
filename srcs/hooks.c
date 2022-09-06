/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:04:05 by tchalifo          #+#    #+#             */
/*   Updated: 2022/09/05 16:02:59 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static int	close_win(t_fractol *f)
{
	fractol_exit(f);
	return (0);
}

void	hooks_manager(t_fractol *f)
{
	mlx_hook(f->mlx.win, 17, 0, close_win, &f->mlx);
	mlx_hook(f->mlx.win, 2, 0, key_binding_mac, &f->mlx);
	mlx_mouse_hook(f->mlx.win, mouse_binding_mac, &f->mlx);
	mlx_hook(f->mlx.win, 6, 0, mouse_get_pos_mac, f->mlx.mlx);
}

// void	keys_hooks_manager(t_mlx *mlx, t_data *data, t_params program_params_data)
// {
// 	(void) data;
// 	if (ft_strcmp(program_params_data.uname, "Linux\n") == 0)
// 	{
// 		mlx_key_hook(mlx->win, key_binding_linux, &mlx);
// 	}
// 	else if (ft_strcmp(program_params_data.uname, "Darwin\n") == 0)
// 	{
// 		// printf("MAIN_pixel_pos_x = %d\n", data->start_pixel_pos_x);
// 		// printf("MAIN_pixel_pos_y = %d\n", data->start_pixel_pos_y);
// 		mlx_key_hook(mlx->win, key_binding_mac, &mlx);
// 	}
// 	else
// 	{
// 		ft_putstr_fd("Keys binding not supported on this system\n", 2);
// 		exit(-1);
// 	}
// }
