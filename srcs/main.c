/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:42:20 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/16 00:42:09 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


int	main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac != 2)
		return (0);
	fdf.scale = 10;
	fdf.map = read_map(av[1], &fdf);
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr= mlx_new_window(fdf.mlx_ptr, SCREEN_SIZE_X, SCREEN_SIZE_Y, "FdF");
	fdf.x_angle = 0;
	fdf.y_angle = 0;
	fdf.z_angle = 0;
	fdf.x_move = 0;
	fdf.y_angle = 0;
	fdf.z_move = 0;
	drawmap(&fdf);
	ft_printf("finished drawing map!\n");
	mlx_hook(fdf.win_ptr, DestroyNotify, 0L, free_displays, &fdf);
	mlx_key_hook(fdf.win_ptr, input_handler, &fdf);
	mlx_loop(fdf.mlx_ptr);
}
