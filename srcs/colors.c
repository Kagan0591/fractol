/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:38:21 by tchalifo          #+#    #+#             */
/*   Updated: 2022/09/26 16:42:01 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	create_rand_rgb(void)
{
	char	red;
	char	green;
	char	blue;
	char	transparency;

	transparency = 0;
	red = char_randomizer();
	green = char_randomizer();
	blue = char_randomizer();
	// int[i] = *(int *)(unsigned char [4]){transparency, blue, green, red};
	return (*(int *)(unsigned char [4]){transparency, blue, green, red});
}

int	*create_color_set(int gen_amount)
{
	int	*colors;
	int	i;

	i = 0;
	colors = malloc(sizeof(int) * gen_amount);
	while (i < gen_amount)
	{
		colors[i] = create_rand_rgb();
		i++;
	}
	return (colors);
}
