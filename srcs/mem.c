/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:45:28 by tchalifo          #+#    #+#             */
/*   Updated: 2022/07/14 16:50:34 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data	init_struct_data(void)
{
	t_data	data;

	data.start_pixel_pos_x = 1;
	data.start_pixel_pos_y = 0;
	return (data);
}