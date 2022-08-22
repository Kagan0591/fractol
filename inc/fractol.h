/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:24:52 by tchalifo          #+#    #+#             */
/*   Updated: 2022/08/22 16:22:23 by tchalifo         ###   ########.fr       */
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

// typedef struct s_formula_values
// {
// 	/* data */
// };


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
	t_fractal_options	f_opt;
	t_mlx				mlx;
}	t_fractol;

void			init_mlx(t_fractol *f_struct);
void			my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void			fractol_exit(t_fractol *f_struct);
void			window_hooks_manager(t_mlx *mlx);
void			keys_hooks_manager(t_mlx *mlx);
void			mouse_hooks_manager(t_mlx *mlx);
int				key_binding_mac(int key, t_mlx *mlx);
// int				key_binding_linux(int key, t_mlx *mlx);
int				write_a_square(t_mlx *mlx, int size_x, int size_y, int init_x_pos, int init_y_pos);
void			draw_fractal_cli(void);
#endif