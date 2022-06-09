#ifndef FRACTOL_H
#define FRACTOL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <mlx.h>
// #include "mlx.h"
#include "libft.h"

typedef struct	s_params
{
	char	*uname;
}				t_params;

typedef struct	s_data
{
	int		pixel_pos_x;
	int		pixel_pos_y;
}				t_data;

typedef struct	s_mlx_data
{
	void	*mlx;
	void	*win;
	void	*img_addr;
	char	*pixel_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mlx_data;

t_data	init_struct_data(void);
void	my_mlx_pixel_put(t_mlx_data data, int x, int y, int color);
int		close_win(t_mlx_data vars);
int		key_binding_mac(t_mlx_data mlx_data, t_data *data, int key);
int		key_binding_linux(t_mlx_data mlx_data, t_data *data, int key);
int		create_trgb(int t, int r, int g, int b);
// void	square_displacement_left(t_vars data);
// void	displacement_left(t_vars data);


//Test-things
int	write_a_square(t_mlx_data mlx_data, t_data *data);

#endif
