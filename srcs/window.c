/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 10:08:48 by tchalifo          #+#    #+#             */
/*   Updated: 2022/07/15 10:41:16 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_windows(t_mlx_data *mlx_data, int size_x, int size_y, char *window_name)
{
	mlx_data->win = mlx_new_window(mlx_data->mlx, size_x, size_y, window_name);
}