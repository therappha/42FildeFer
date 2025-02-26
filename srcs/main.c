/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:42:20 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/26 19:34:02 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int ac, char **av)
{
	t_fdf	fdf;
	t_line	*lines;

	if (ac != 3)
		return (0);
	lines = NULL;
	if (read_map(&lines, av[1]) == -1)
	{
		ft_printf("Error, Could not read file!\n");
		return (0);
	}
	fdf.scale = atoi(av[2]);
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window
		(fdf.mlx_ptr, SCREEN_SIZE_X, SCREEN_SIZE_Y, "FdF");
	fdf.image.img = mlx_new_image(fdf.mlx_ptr, SCREEN_SIZE_X, SCREEN_SIZE_Y);
	fdf.image.addr = mlx_get_data_addr(fdf.image.img, &fdf.image.bits_per_pixel,
			&fdf.image.line_length, &fdf.image.endian);
	drawmap(&fdf, &lines, atoi(av[2]));
	ft_linefree(&lines);
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, fdf.image.img, 0, 0);
	mlx_destroy_image(fdf.mlx_ptr, fdf.image.img);
	mlx_hook(fdf.win_ptr, DestroyNotify, 0L, free_displays, &fdf);
	mlx_key_hook(fdf.win_ptr, input_handler, &fdf);
	mlx_loop(fdf.mlx_ptr);
}
