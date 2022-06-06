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
}				t_vars;

int	create_trgb(int t, int r, int g, int b);

#endif
