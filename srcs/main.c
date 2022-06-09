/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:57:18 by tchalifo          #+#    #+#             */
/*   Updated: 2022/06/08 21:37:22 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


char	*ft_uname(char **envp)
{
	int		pid_t;
	int		pipe_fd[2];
	int		buffer_size;
	char	*buffer;

	buffer_size = 64;
	pipe_fd[0] = 0;
	pipe_fd[1] = 0;
	buffer = ft_calloc(buffer_size + 1, sizeof(char *));
	if (pipe(pipe_fd) == -1)
		perror(NULL);
	pid_t = fork();
	if (pid_t != 0)
	{
		close(pipe_fd[1]);
		if (read(pipe_fd[0], buffer, buffer_size) == -1)
		{
			close(pipe_fd[0]);
			exit(errno);
		}
		close(pipe_fd[0]);
	}
	else if (pid_t == 0) //if is the child process
	{
		close (pipe_fd[0]);
		dup2(pipe_fd[1], 1);
		close(pipe_fd[1]);
		if (execve("/usr/bin/uname", ft_split("uname", ' '), envp) == -1)
		{
			dprintf(2, "EXECVE FAILED\n");
			exit(errno);
		}
	}
	wait(0);
	return (buffer);
}

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
	t_vars		vars;
	t_params	program_data;

	parsing_args(argc, argv);
	program_data.uname = ft_uname(envp);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1280, 720, "Fract-ol");
	write_a_square(vars);
	mlx_hook(vars.win, 17, 0, close_win, &vars);
	if (ft_strcmp(program_data.uname, "Linux\n") == 0)
	{
		mlx_key_hook(vars.win, key_binding_linux, &vars);
	}
	else if (ft_strcmp(program_data.uname, "Darwin") == 0)
	{
		mlx_key_hook(vars.win, key_binding_mac, &vars);
	}
	else
	{
		ft_putstr_fd("OS not supported\n", 2);
		exit(-1);
	}

	mlx_loop(vars.mlx);

	return (0);
}
