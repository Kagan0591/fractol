/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strofstrlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:57:10 by tchalifo          #+#    #+#             */
/*   Updated: 2022/04/15 15:58:12 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strofstrlen(char **strofstr)
{
	int	count;

	count = 0;
	while (strofstr[count] != NULL)
		count++;
	return (count);
}
