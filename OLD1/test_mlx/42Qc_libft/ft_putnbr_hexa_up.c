/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa_up.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 11:32:07 by tchalifo          #+#    #+#             */
/*   Updated: 2022/04/18 11:32:08 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_putnbr_hexa_up(unsigned int n)
{
	unsigned int	count;

	count = ft_hexa_numlen(n);
	if ((n / 16) != 0)
		ft_putnbr_hexa_up(n / 16);
	if ((n % 16) > 9)
		ft_putchar((n % 16) + 55);
	else
		ft_putchar((n % 16) + 48);
	return (count);
}
