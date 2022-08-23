/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:24:52 by tchalifo          #+#    #+#             */
/*   Updated: 2022/08/23 15:38:12 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_WIDTH 1280 //X
# define WIN_HEIGHT 720 //Y
# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <mlx.h>	// Uncomment for Mac
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

typedef struct s_formula_values
{
	int			x_pos;
	int			y_pos;
	int			i;
	long double	n; //size
	long double	cx; //c real
	long double	cy; //c img
	long double	zx;
	long double	zy;
	long double	size;
}t_formula_values;

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
	t_mlx				mlx;
	t_fractal_options	f_opt;
	t_formula_values	mandelbrot;
}	t_fractol;
/*
 * Core functions
 */
void			init_mlx(t_fractol *f_struct);
void			my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void			fractol_exit(t_fractol *f_struct);
void			window_hooks_manager(t_mlx *mlx);
void			keys_hooks_manager(t_mlx *mlx);
void			mouse_hooks_manager(t_mlx *mlx);
int				key_binding_mac(int key, t_mlx *mlx);
// int				key_binding_linux(int key, t_mlx *mlx);
/*
 * Testing functions
 */
int				write_a_square(t_mlx *mlx, int size_x, int size_y, int init_x_pos, int init_y_pos);
void	draw_mandelbrot_cli(t_fractol *f);
/*
 * Fractal functions
 */
void			mandelbrot(t_fractol *f_struct);

#endif