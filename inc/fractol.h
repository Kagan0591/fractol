/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:24:52 by tchalifo          #+#    #+#             */
/*   Updated: 2022/08/30 15:01:18 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_WIDTH 1280 //X
# define WIN_HEIGHT 720 //Y
# define FRACTAL_MAX_ITER 50
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
	long double	cx; //c real
	long double	cy; //c img
	long double	zx; //z real
	long double	zy; //z img
	long double	size;
	long double	x_axis_offset;
	long double	y_axis_offset;
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
void			init_mlx(t_mlx *mlx_data);
void			my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void			image_refresh(t_mlx *mlx_data);
void			fractol_exit(t_fractol *f_struct);
void			window_hooks_manager(t_fractol *f);
void			keys_hooks_manager(t_fractol *f);
void			mouse_hooks_manager(t_fractol *f);
int				key_binding_mac(int key, t_fractol *f);
int				mouse_event_mac(int key, int x, int y, t_fractol *f);
// int				key_binding_linux(int key, t_mlx *mlx);
/*
 * Testing functions
 */
int				write_a_square(t_mlx *mlx, int size_x, int size_y, int init_x_pos, int init_y_pos);
void			draw_mandelbrot_cli(t_fractol *f);
/*
 * Fractal functions
 */
void			mandelbrot_init(t_formula_values *data);
void			mandelbrot(t_formula_values *data, t_mlx *mlx_data);
void			fractal_updater(t_fractol *f);

#endif