/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_numlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 11:30:29 by tchalifo          #+#    #+#             */
/*   Updated: 2022/04/18 11:30:31 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexa_numlen(unsigned int n)
{
	int	count;

	count = 0;
	while (n > 15)
	{
		n /= 16;
		count++;
	}
	count++;
	return (count);
}
