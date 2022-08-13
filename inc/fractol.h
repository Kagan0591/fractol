/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:24:52 by tchalifo          #+#    #+#             */
/*   Updated: 2022/08/13 18:01:39 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H
#define WIN_WIDTH 1280 //X
#define WIN_HEIGHT 720 //Y
#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <mlx.h>	// Uncomment for Mac
// #include "mlx.h"	// Uncomment for Linux

/*
 * Struct containing all mlx related vars
 */
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img_addr;
	char	*pixel_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx;

/*
 * Struct for fractal options
 */
typedef struct	s_fractal_options
{
	int	type;
}	t_fractal_options;

/*
 * Main struct containing others struct
 */
typedef struct s_fractol
{
	t_fractal_options f_opt;
	t_mlx mlx;
}	t_fractol;


#endif