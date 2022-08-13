/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_s1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:05:41 by tchalifo          #+#    #+#             */
/*   Updated: 2022/05/17 17:18:36 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	the_free(char *str_ptr1)
{
	free(str_ptr1);
}

char	*ft_strjoin_free_s1(char const *s1, char const *s2)
{
	char	*s3;
	size_t	s1_lenght;
	size_t	s2_lenght;

	if (!s1)
		return ((char *) s2);
	if (!s2)
		return ((char *) s1);
	if (s1 || s2)
	{
		s1_lenght = ft_strlen(s1);
		s2_lenght = ft_strlen(s2);
		s3 = malloc((s1_lenght + s2_lenght) + 1);
		if (!s3)
			return (NULL);
		ft_strlcpy(s3, s1, (s1_lenght + 1));
		ft_strlcat(s3, s2, ((s1_lenght + s2_lenght) + 1));
		the_free((char *)s1);
		return (s3);
	}
	return (NULL);
}
