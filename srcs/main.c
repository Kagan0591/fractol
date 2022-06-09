/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:57:18 by tchalifo          #+#    #+#             */
/*   Updated: 2022/06/09 15:06:36 by tchalifo         ###   ########.fr       */
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
	waitpid(pid_t, NULL, 0);
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
	t_mlx_data	mlx_data;
	t_params	program_params_data;
	t_data		data;

	parsing_args(argc, argv);
	program_params_data.uname = ft_uname(envp);
	data = init_struct_data();
	mlx_data.mlx = mlx_init();
	mlx_data.win = mlx_new_window(mlx_data.mlx, 1280, 720, "Fract-ol");
	write_a_square(mlx_data, &data);
	mlx_hook(mlx_data.win, 17, 0, close_win, &mlx_data);
	if (ft_strcmp(program_params_data.uname, "Linux\n") == 0)
		mlx_key_hook(mlx_data.win, key_binding_linux, &mlx_data);
	else if (ft_strcmp(program_params_data.uname, "Darwin\n") == 0)
	{
		printf("ON MAC !\n");
		mlx_key_hook(mlx_data.win, key_binding_mac, &mlx_data);
	}
	else
	{
		ft_putstr_fd("OS not supported\n", 2);
		exit(-1);
	}
	mlx_loop(mlx_data.mlx);

	return (0);
}
