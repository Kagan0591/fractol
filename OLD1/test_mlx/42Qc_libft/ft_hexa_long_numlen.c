/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_long_numlen.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 11:30:08 by tchalifo          #+#    #+#             */
/*   Updated: 2022/04/18 11:30:11 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexa_long_numlen(unsigned long n)
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
