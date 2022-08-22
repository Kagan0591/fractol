/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:24:20 by tchalifo          #+#    #+#             */
/*   Updated: 2022/08/22 16:22:44 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_exit(t_fractol *f_struct) //Function for suitable exit.
{
	mlx_destroy_image(f_struct->mlx.mlx, f_struct->mlx.img_addr);
	mlx_destroy_window(f_struct->mlx.mlx, f_struct->mlx.win);
	free(f_struct);
	exit(0);
}

// static void	agruments_validation(int argc, char **argv, t_fractol *f_struct) //Function that check the arguments and validate it.
// {
// 	if (argc != 2)
// 	{
// 		ft_putstr_fd(strerror(22), 2);
// 		exit(22);
// 	}
// 	if (ft_strcmp(argv[1], "Mandelbrot") == 0 \
// 		|| ft_strcmp(argv[1], "mandelbrot") == 0)
// 	{
// 		ft_printf("Mandelbrot set have been choosen\n");
// 		f_struct->f_opt.type = 1;
// 	}
// 	else if (ft_strcmp(argv[1], "Julia") == 0 \
// 				|| ft_strcmp(argv[1], "julia") == 0)
// 	{
// 		ft_printf("Julia set have been choosen\n");
// 		f_struct->f_opt.type = 2;
// 	}
// 	else
// 	{
// 		ft_putstr_fd(strerror(22), 2);
// 		ft_putstr_fd(" --> Try Mandelbrot or Julia as an argument\n", 2);
// 		free(f_struct);
// 		exit(22);
// 	}
// }

int	main(int argc, char **argv, char **envp)
{
	(void) envp;
	(void) argc;
	(void) argv;
	// t_fractol	*f_struct;

	// f_struct = (t_fractol *)malloc(sizeof(t_fractol));
	// agruments_validation(argc, argv, f_struct);
	// // printf("The set-type number is : %d\n", f_struct->f_opt.type);
	// init_mlx(f_struct);
	/* TESTING FUNCTION HERE */
	// write_a_square(&f_struct->mlx, 100, 100, 50, 50);
	// write_a_square(&f_struct->mlx, 100, 100, 200, 200);
	// keys_hooks_manager(&f_struct->mlx);
	// mlx_string_put(f_struct->mlx.mlx, f_struct->mlx.win, 50, 650, 0xFFFFFF, "My Test");
	draw_fractal_cli();
	/* END OF TEST */
	// mlx_loop(f_struct->mlx.mlx);
	return (0);
}