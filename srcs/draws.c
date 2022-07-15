/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:18:32 by tchalifo          #+#    #+#             */
/*   Updated: 2022/07/15 10:00:15 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_mlx_data *mlx_data, int x, int y, int color)
{
	char	*dst;

	dst = mlx_data->pixel_addr + (y * mlx_data->line_length + x * (mlx_data->bits_per_pixel / 8));
//	printf("%s:%d\n", __FUNCTION__, __LINE__);
	*(unsigned int*)dst = color;
//	printf("%s:%d\n", __FUNCTION__, __LINE__);
}
