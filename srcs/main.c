/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:42:20 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/14 19:59:46 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


int	main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac != 2)
		return (0);
	fdf.scale = 16;
	fdf.map = read_map(av[1], &fdf);
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr= mlx_new_window(fdf.mlx_ptr, SCREEN_SIZE_X, SCREEN_SIZE_Y, "FdF");
	fdf.image.img = mlx_new_image(fdf.mlx_ptr, SCREEN_SIZE_X, SCREEN_SIZE_Y);
	fdf.image.addr = mlx_get_data_addr(fdf.image.img, &fdf.image.bits_per_pixel,
		&fdf.image.line_length, &fdf.image.endian);
	fdf.focal_length = FOCAL_LENGTH;
	drawmap(&fdf);
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, fdf.image.img, 0, 0);
	mlx_hook(fdf.win_ptr, DestroyNotify, 0L, free_displays, &fdf);
	mlx_loop(fdf.mlx_ptr);
}
