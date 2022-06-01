/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:57:18 by tchalifo          #+#    #+#             */
/*   Updated: 2022/05/31 22:33:32 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


char	*ft_uname(void)
{
	int		pid_t;
	int		pipe_fd[2];
	int		buffer_size;
	char	*buffer;

	buffer_size = 64;
	pipe_fd[0] = 0;
	pipe_fd[1] = 0;
	buffer = ft_calloc(buffer_size + 1, sizeof(char *));
	pid_t = fork();
	if (pid_t == 0)
	{
		close (pipe_fd[0]);
		dup2(pipe_fd[1], 0);
		close(0);
		if (execve("/usr/bin/uname", (char * const*)"uname", 0) == -1)
			exit(errno);

	}
	else
	{
		wait(0);
		if (read(pipe_fd[0], buffer, buffer_size) == -1)
			exit(errno);
		dprintf(2, "Result = %s\n", buffer);
	}
	return (buffer);
}

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	ft_uname();
	return (0);
}


