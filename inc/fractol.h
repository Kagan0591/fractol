#ifndef FRACTOL_H
#define FRACTOL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <mlx.h> // Uncomment for Mac
// #include "mlx.h" // Uncomment for Linux
#include "libft.h"

typedef struct	s_params
{
	char	*uname;
}				t_params;

typedef struct	s_data
{
	int		start_pixel_pos_x;
	int		start_pixel_pos_y;
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

// [ Params function ]
char		*ft_uname(char **envp);

// [ Program function ]
t_data		*init_struct_data(void);
t_mlx_data	*init_struct_mlx_data(void);
void		init_windows(t_mlx_data *mlx_data, int size_x, int size_y, char *window_name);
void		my_mlx_pixel_put(t_mlx_data *mlx_data, int x, int y, int color);
void		window_hooks_manager(t_mlx_data *mlx_data);
int			close_win(t_mlx_data vars);
void		keys_hooks_manager(t_mlx_data *mlx_data, t_data *data, t_params program_params_data);
int			key_binding_mac(t_mlx_data mlx_data, int key, t_data *data);
int			key_binding_linux(t_mlx_data mlx_data, int key, t_data *data);
void		mouse_hooks_manager(t_mlx_data *mlx_data, t_data *data, t_params program_params_data);
int			create_trgb(int t, int r, int g, int b);
// void	square_displacement_left(t_vars data);
// void	displacement_left(t_vars data);

// [ Testhings ]
void		print_a_square(t_mlx_data *mlx_data, t_data *data);
int			write_a_square(t_mlx_data *mlx_data, t_data *data, int x, int y);

#endif
