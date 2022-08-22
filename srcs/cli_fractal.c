/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_fractal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:24:44 by tchalifo          #+#    #+#             */
/*   Updated: 2022/08/22 16:35:10 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal_cli(void)
{
	int pos_x;
	int pos_y;
	int i;
	long double n;
	long double x;
	long double y;
	long double xx;
	long double yy;
	long double tmp;

	pos_y = 0;
	n = 15;
	while (pos_y <= (4 * n))
	{
		y = 2 - (pos_y / n);
		pos_x = 0;

		while (pos_x <= (4 * n))
		{
			x = -2 + (pos_x / n);
			pos_x++;
			i = 1;
			xx = 0;
			yy = 0;
			while (i<=1000)
			{
				tmp = xx;
				xx = (xx * xx) - (yy * yy) + x;
				yy = (2 * tmp * yy) + y;
				if ((xx * xx) + (yy * yy) > 4)
					break;
				i++;
			}
			if (i == 1001)
				printf(".");
			else
				printf(" ");
			// printf("iter test %d", i);
		}
		pos_y++;
		printf("\n");
	}
}