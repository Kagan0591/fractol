/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:45:28 by tchalifo          #+#    #+#             */
/*   Updated: 2022/06/09 14:49:29 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data	init_struct_data(void)
{
	t_data	data;

	data.pixel_pos_x = 0;
	data.pixel_pos_y = 0;
	return (data);
}