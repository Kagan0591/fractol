/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:57:18 by tchalifo          #+#    #+#             */
/*   Updated: 2022/06/07 17:59:32 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


// char	*ft_uname(void)
// {
// 	int		pid_t;
// 	int		pipe_fd[2];
// 	int		buffer_size;
// 	char	*buffer;

// 	buffer_size = 64;
// 	pipe_fd[0] = 0;
// 	pipe_fd[1] = 0;
// 	buffer = ft_calloc(buffer_size + 1, sizeof(char *));
// 	pid_t = fork();
// 	if (pid_t == 0)
// 	{
// 		close (pipe_fd[0]);
// 		dup2(pipe_fd[1], 0);
// 		close(0);
// 		if (execve("/usr/bin/uname", (char * const*)"uname", 0) == -1)
// 			exit(errno);

// 	}
// 	else
// 	{
// 		wait(0);
// 		if (read(pipe_fd[0], buffer, buffer_size) == -1)
// 			exit(errno);
// 		dprintf(2, "Result = %s\n", buffer);
// 	}
// 	return (buffer);
// }

void	parsing_args(int argc, char **argv)
{
	(void) argv;
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

int	close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	key_hook(int key)
{
	if (key == 53)
		exit(1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		x_pos = 0;
	int		y_pos = 0;
	int		x_pos_keeped = 1;
	int		y_pos_keeped = 1;

	parsing_args(argc, argv);
	// ft_uname();
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Fract-ol");
	write_a_square(vars);
	mlx_mouse_hook(void *win_ptr, int (*f)(), void *param)
	mlx_mouse_get_pos(vars.win, &x_pos, &y_pos);
	x_pos_keeped = x_pos;
	y_pos_keeped = y_pos;
	if (x_pos != x_pos_keeped || y_pos != y_pos_keeped)
	{
		printf("x = %d, y = %d", x_pos, y_pos);
	}
	mlx_hook(vars.win, 17, 0, close_win, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);

	return (0);
}
