/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:24:16 by tchalifo          #+#    #+#             */
/*   Updated: 2022/09/27 11:48:07 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	char_randomizer(void)
{
	int fd;
	char	*buffer;
	int		buffer_int = -1;

	buffer = malloc(sizeof(char *));
	fd = open ("/dev/urandom", O_RDONLY);
	while (buffer_int < 0)
	{
		read (fd, buffer, 1);
		buffer_int = buffer[0];
	}
	close (fd);
	return (buffer[0]);
}