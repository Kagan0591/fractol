/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   os.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 08:29:29 by tchalifo          #+#    #+#             */
/*   Updated: 2022/07/15 09:10:11 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void ft_exec(char *file, char **args, char **envp)
{
	if (execve(file, args, envp) == -1)
	{
		dprintf(2, "EXECVE FAILED\n");
		exit(errno);
	}
}

static void ft_read_to_pipe(int pipe_in_0, char *buffer, int buffer_size)
{
	if (read(pipe_in_0, buffer, buffer_size) == -1)
	{
		close(pipe_in_0);
		exit(errno);
	}
	close(pipe_in_0);
}

char	*ft_uname(char **envp)
{
	int		pid_t;
	int		pipe_fd[2];
	char	*buffer;

	pipe_fd[0] = 0;
	pipe_fd[1] = 0;
	buffer = ft_calloc(7, sizeof(char *));
	if (pipe(pipe_fd) == -1)
		perror(NULL);
	pid_t = fork();
	if (pid_t != 0)
	{
		close(pipe_fd[1]);
		ft_read_to_pipe(pipe_fd[0], buffer, 7);
	}
	else if (pid_t == 0) //if is the child process
	{
		close (pipe_fd[0]);
		dup2(pipe_fd[1], 1);
		close(pipe_fd[1]);
		ft_exec("/usr/bin/uname", ft_split("uname", ' '), envp);
	}
	printf("UNAME VALUE = %s", buffer);
	waitpid(pid_t, NULL, 0);
	return (buffer);
}
