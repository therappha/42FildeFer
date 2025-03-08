/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:42:20 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/03/08 19:33:55 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int ac, char **av)
{
	t_fdf	fdf;
	t_line	*lines;

	if (ac != 2)
		return (0);
	lines = NULL;
	fdf.map_x = -1;
	fdf.map_y = 0;
	if (!check_args(av[1]) || read_map(&lines, &fdf, av[1]) == -1)
	{
		ft_printf("Error, Could not read file!\n");
		return (0);
	}
	init_window(&fdf);
	fdf.scale = get_scale(&fdf);
	drawmap(&fdf, &lines);
	ft_linefree(&lines);
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, fdf.image.img, 0, 0);
	mlx_destroy_image(fdf.mlx_ptr, fdf.image.img);
	mlx_hook(fdf.win_ptr, DestroyNotify, 0L, free_displays, &fdf);
	mlx_key_hook(fdf.win_ptr, input_handler, &fdf);
	mlx_loop(fdf.mlx_ptr);
}
