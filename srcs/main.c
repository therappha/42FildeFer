/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:42:20 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/10 20:03:50 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


int	main(int ac, char **av)
{
	t_fdf	*fdf;
	t_line *lines;

	if (ac != 3)
		return (0);
	fdf = malloc(sizeof(fdf));
	lines = NULL;
	read_map(&fdf, &lines, av[1]);
	int screen_x;
	int screen_y;

	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1900, 1000, "FdF");
	mlx_get_screen_size(fdf ->mlx_ptr, (&fdf ->screen_x), (&fdf-> screen_y));
	drawmap(&fdf, &lines, atoi(av[2]));
	mlx_hook((fdf) -> win_ptr, DestroyNotify, 0L, free_displays, &fdf);
	mlx_loop(fdf->mlx_ptr);
}
