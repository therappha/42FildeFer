/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:42:20 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/12 21:06:14 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


int	main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac != 2)
		return (0);
	fdf.scale = 1;
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr= mlx_new_window(fdf.mlx_ptr, SCREEN_SIZE_X, SCREEN_SIZE_Y, "FdF");
	fdf.map_image.img = mlx_new_image(fdf.mlx_ptr, SCREEN_SIZE_X, SCREEN_SIZE_Y);
	mlx_hook(fdf.win_ptr, DestroyNotify, 0L, free_displays, &fdf);
	mlx_loop(fdf.mlx_ptr);
}
