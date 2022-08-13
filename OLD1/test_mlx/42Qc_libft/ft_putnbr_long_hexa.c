/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_long_hexa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 11:32:18 by tchalifo          #+#    #+#             */
/*   Updated: 2022/04/18 11:32:20 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_putnbr_long_hexa(unsigned long n)
{
	unsigned int	count;

	count = ft_hexa_long_numlen(n);
	if ((n / 16) != 0)
		ft_putnbr_long_hexa(n / 16);
	if ((n % 16) > 9)
		ft_putchar((n % 16) + 87);
	else
		ft_putchar((n % 16) + 48);
	return (count);
}
