/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:57:18 by tchalifo          #+#    #+#             */
/*   Updated: 2022/07/15 16:27:36 by tchalifo         ###   ########.fr       */
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
	mouse_hooks_manager(mlx_data, data, program_params_data);
	mlx_loop(mlx_data->mlx);
	return (0);
}
