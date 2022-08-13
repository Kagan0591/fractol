/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:24:20 by tchalifo          #+#    #+#             */
/*   Updated: 2022/08/13 19:29:24 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_exit(t_fractol *f_struct) //Function for suitable exit.
{
	free(f_struct);
	exit(0);
}

void	agruments_validation(int argc, char **argv, t_fractol *f_struct) //Function that check the arguments and validate it.
{
	if (argc != 2)
	{
		ft_putstr_fd(strerror(22), 2);
		exit(22);
	}
	if (ft_strcmp(argv[1], "Mandelbrot") == 0 \
		|| ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		ft_printf("Mandelbrot set have been choosen\n");
		f_struct->f_opt.type = 1;
	}
	else if (ft_strcmp(argv[1], "Julia") == 0 \
				|| ft_strcmp(argv[1], "julia") == 0)
	{
		ft_printf("Julia set have been choosen\n");
		f_struct->f_opt.type = 2;
	}
	else
	{
		ft_putstr_fd(strerror(22), 2);
		ft_putstr_fd(" --> Try Mandelbrot or Julia as an argument\n", 2);
		free(f_struct);
		exit(22);
	}
}

void	init_mlx(t_fractol *f_struct)
{
	f_struct->mlx.mlx = mlx_init();
	f_struct->mlx.win = mlx_new_window(f_struct->mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "Thomas Fractol");
	f_struct->mlx.img_addr = mlx_new_image(f_struct->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	f_struct->mlx.pixel_addr = mlx_get_data_addr(f_struct->mlx.img_addr, &f_struct->mlx.bits_per_pixel, &f_struct->mlx.line_length, &f_struct->mlx.endian);
	printf("TEST\n");
}

void	my_mlx_pixel_put(t_mlx *mlx_data, int x, int y, int color)
{
	char	*dst;

	dst = mlx_data->pixel_addr + (y * mlx_data->line_length) + (x * (mlx_data->bits_per_pixel / 8));
//	printf("%s:%d\n", __FUNCTION__, __LINE__);
	*(unsigned int*)dst = color;
//	printf("%s:%d\n", __FUNCTION__, __LINE__);
}

int	write_a_square(t_mlx *mlx, int size_x, int size_y, int init_x_pos, int init_y_pos)
{
	int	x_pos;
	int	y_pos;

	x_pos = init_x_pos;
	y_pos = init_y_pos;
	while (y_pos < (size_y + init_y_pos))
	{
		x_pos = init_x_pos;
		while (x_pos < (size_x + init_x_pos))
		{
			my_mlx_pixel_put(mlx, x_pos, y_pos, 0x00FAFF0D);
			x_pos++;
		}
		y_pos++;
	}
	// mlx_put_image_to_window(mlx_data.mlx, mlx_data.win, mlx_data.img_addr, ((1920/2)-50), ((1080/2)-50));
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_addr, 0, 0);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	(void) envp;
	t_fractol	*f_struct;

	f_struct = (t_fractol *)malloc(sizeof(t_fractol));
	agruments_validation(argc, argv, f_struct);
	// printf("The set-type number is : %d\n", f_struct->f_opt.type);
	init_mlx(f_struct);
	/* TESTING FUNCTION HERE */
	write_a_square(&f_struct->mlx, 100, 100, 50, 50);
	write_a_square(&f_struct->mlx, 100, 100, 200, 200);
	/* END OF TEST */
	mlx_string_put(f_struct->mlx.mlx, f_struct->mlx.win, 50, 650, 0xFFFFFF, "My frac");
	mlx_loop(f_struct->mlx.mlx);
	return (0);
}