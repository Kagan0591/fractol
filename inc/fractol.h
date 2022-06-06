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
#include "libft.h"

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_vars;

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);

#endif
