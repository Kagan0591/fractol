/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:04:39 by tchalifo          #+#    #+#             */
/*   Updated: 2022/10/18 11:29:33 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	bad_arguments(int error_code)
{
	ft_putstr_fd(strerror(error_code), 2);
	ft_putstr(", You can choose between two different fractals : \
		\n- Mandelbrot set\n- Julia set\n\nAlso, the Julia set can take a \
decimal number from -2 to 2 to create a different set or use the word auto \
for mouse tracking modifier.");
	exit(error_code);
}
