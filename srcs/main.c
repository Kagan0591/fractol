/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:24:20 by tchalifo          #+#    #+#             */
/*   Updated: 2022/10/18 11:36:48 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	fractol_exit(t_fractol *f)
{
	mlx_destroy_image(f->mlx.mlx, f->mlx.img_addr);
	mlx_destroy_window(f->mlx.mlx, f->mlx.win);
	free(f);
	exit(0);
}

static void	args_validation(int argc, char **argv, t_fractol *f)
{
	if (argc < 2)
	{
		free(f);
		bad_arguments(22);
	}
	if (ft_strcmp(argv[1], "Mandelbrot") == 0 \
		|| ft_strcmp(argv[1], "mandelbrot") == 0)
		f->f_opt.type = 1;
	else if (ft_strcmp(argv[1], "Julia") == 0 \
		|| ft_strcmp(argv[1], "julia") == 0)
	{
		if ((argc == 3) && (ft_strcmp(argv[2], "auto") || ft_strcmp(argv[2], "Auto")))
			f->f_opt.julia_morph = 1;
		else if (argc == 4 && (ft_strisdecimal(argv[2]) == 0 && ft_strisdecimal(argv[3]) == 0))
			f->f_opt.julia_morph = 2;
		else
			ft_putstr_fd("The additional arguments concerning Julia are not \
			valid. Args are going to be ignore.", 2);
		f->f_opt.type = 2;
	}
	else
	{
		free(f);
		bad_arguments(22);
	}
}

static void	set_initial_vars(t_fractol *f, int argc, char **argv)
{
	if (f->f_opt.type == 1)
		mandelbrot_init(&f->mandelbrot);
	else if (f->f_opt.type == 2)
		julia_init(&f->julia);
	f->f_opt.max_iter = FRACTAL_MAX_ITER;
	f->f_opt.colors = create_color_set(10);
	f->argv_cpy = ft_argvcpy(argc, argv);
	printf ("%s\n", f->argv_cpy[1]);
}

int	main(int argc, char **argv)
{
	t_fractol	*f;

	f = (t_fractol *)malloc(sizeof(t_fractol));
	if (!f)
		return (1);
	args_validation(argc, argv, f);
	set_initial_vars(f, argc, argv);
	// init_mlx(&f->mlx);
	// if (f->f_opt.type == 1)
	// 	mandelbrot(f);
	// else if (f->f_opt.type == 2)
	// 	julia(f);
	// mlx_put_image_to_window(f->mlx.mlx, f->mlx.win, f->mlx.img_addr, 0, 0);
	// hooks_manager(f);
	// mlx_loop(f->mlx.mlx);
	return (0);
}
