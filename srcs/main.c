/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:57:18 by tchalifo          #+#    #+#             */
/*   Updated: 2022/07/15 14:23:53 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	parsing_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd(strerror(22), 2);
		exit(22);
	}
	if (ft_strcmp(argv[1], "Mandelbrot") == 0 \
		|| ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		ft_printf("Mandelbrot have been choosen\n");
	}
	else if (ft_strcmp(argv[1], "Julia") == 0 \
				|| ft_strcmp(argv[1], "julia") == 0)
	{
		ft_printf("Julia have been choosen\n");
	}
	else
	{
		ft_putstr_fd(strerror(22), 2);
		ft_putstr_fd("\n\nTry Mandelbrot or Julia as an argument\n", 2);
		exit(22);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_mlx_data	*mlx_data;
	t_params	program_params_data;
	t_data		*data;

	parsing_args(argc, argv);
	program_params_data.uname = ft_uname(envp);
	data = init_struct_data();
	mlx_data = init_struct_mlx_data();
	mlx_data->mlx = mlx_init();
	init_windows(mlx_data, 1920, 1080, "Fract-ol");
	print_a_square(mlx_data, data);
	window_hooks_manager(mlx_data);
	keys_hooks_manager(mlx_data, data, program_params_data);
	// mlx_hook(mlx_data->win, 17, 0, close_win, &mlx_data);
	// if (ft_strcmp(program_params_data.uname, "Linux\n") == 0)
	// 	mlx_key_hook(mlx_data->win, key_binding_linux, &mlx_data);
	// else if (ft_strcmp(program_params_data.uname, "Darwin\n") == 0)
	// {
	// 	printf("ON MAC !\n");
	// 	printf("MAIN_pixel_pos_x = %d\n", data->start_pixel_pos_x);
	// 	printf("MAIN_pixel_pos_y = %d\n", data->start_pixel_pos_y);
	// 	mlx_hook(mlx_data->win, 2, 3, key_binding_mac, &data);
	// 	// mlx_loop_hook(mlx_data.mlx, key_binding_mac, &data);
	// }
	// else
	// {
	// 	ft_putstr_fd("OS not supported\n", 2);
	// 	exit(-1);
	// }
	mlx_loop(mlx_data->mlx);

	return (0);
}
