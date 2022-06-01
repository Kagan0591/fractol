/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:57:18 by tchalifo          #+#    #+#             */
/*   Updated: 2022/06/01 14:37:47 by tchalifo         ###   ########.fr       */
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

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	void	*ptr;
	// ft_uname();
	ptr = mlx_init();
	mlx_new_window(ptr, 1080, 720, "Bob");
	mlx_loop(ptr);
	return (0);
}


