/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_numlen.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 11:24:37 by tchalifo          #+#    #+#             */
/*   Updated: 2022/04/18 11:24:54 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unsigned_numlen(unsigned int n)
{
	int	count;

	count = 0;
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	count++;
	return (count);
}
