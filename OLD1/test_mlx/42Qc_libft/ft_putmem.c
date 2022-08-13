/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 11:31:05 by tchalifo          #+#    #+#             */
/*   Updated: 2022/04/18 11:31:07 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_putmem(void *mem)
{
	unsigned int	count;

	if (!mem || mem == 0)
		return (write(1, "0x0", 3));
	ft_putstr("0x");
	count = 2;
	count = count + ft_putnbr_long_hexa((unsigned long) mem);
	return (count);
}
