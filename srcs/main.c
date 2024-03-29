/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:24:20 by tchalifo          #+#    #+#             */
/*   Updated: 2022/09/06 16:28:31 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	fractol_exit(t_fractol *f) //Function for suitable exit.
{
	mlx_destroy_image(f->mlx.mlx, f->mlx.img_addr);
	mlx_destroy_window(f->mlx.mlx, f->mlx.win);
	free(f);
	exit(0);
}

static void	agruments_validation(int argc, char **argv, t_fractol *f) //Function that check the arguments and validate it.
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
		f->f_opt.type = 1;
	}
	else if (ft_strcmp(argv[1], "Julia") == 0 \
				|| ft_strcmp(argv[1], "julia") == 0)
	{
		ft_printf("Julia set have been choosen\n");
		f->f_opt.type = 2;
	}
	else
	{
		ft_putstr_fd(strerror(22), 2);
		ft_putstr_fd(" --> Try Mandelbrot or Julia as an argument\n", 2);
		free(f);
		exit(22);
	}
}

int	main(int argc, char **argv, char **envp)
{
	(void) envp;
	(void) argc;
	(void) argv;
	t_fractol	*f;

	f = (t_fractol *)malloc(sizeof(t_fractol));
	agruments_validation(argc, argv, f);
	mandelbrot_init(&f->mandelbrot);
	julia_init(&f->julia);
	// // printf("The set-type number is : %d\n", f->f_opt.type);
	init_mlx(&f->mlx);
	if (f->f_opt.type == 1)
		mandelbrot(&f->mandelbrot, &f->mlx);
	else if (f->f_opt.type == 2)
		julia(&f->mandelbrot, &f->mlx);
	mlx_put_image_to_window(f->mlx.mlx, f->mlx.win, f->mlx.img_addr, 0, 0);
	/* TESTING FUNCTION HERE */
	// write_a_square(&f->mlx, 100, 100, 50, 50);
	// write_a_square(&f->mlx, 100, 100, 200, 200);
	// mlx_string_put(f->mlx.mlx, f->mlx.win, 50, 650, 0xFFFFFF, "My Test");
	// draw_fractal_cli();
	/* END OF TEST */
	hooks_manager(f);
	mlx_loop(f->mlx.mlx);
	return (0);
}