/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_gnlvers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:01:30 by tchalifo          #+#    #+#             */
/*   Updated: 2022/04/15 09:02:09 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_gnlvers(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (char )c)
			return ((char *)s + 1);
		s++;
	}
	return (0);
}
