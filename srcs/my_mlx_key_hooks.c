/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_key_hooks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:07:39 by tchalifo          #+#    #+#             */
/*   Updated: 2022/06/08 16:38:47 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_binding_mac(int key)
{
	if (key == 53)
		exit(1);
	printf("%d\n", key);
	return (0);
}

int	key_binding_linux(int key)
{
	if (key == 53)
		exit(1);
	printf("%d\n", key);
	return (0);
}

// linux code

// 65362 fleche haut
// 65363 fleche droite
// 65364 fleche bas
// 65361 fleche gauche
// 65307 ESC
