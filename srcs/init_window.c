/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:26:08 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/03/08 18:35:26 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_window(t_fdf *fdf)
{
	(*fdf).mlx_ptr = mlx_init();
	(*fdf).win_ptr = mlx_new_window
		((*fdf).mlx_ptr, SCREEN_SIZE_X, SCREEN_SIZE_Y, "FdF");
	(*fdf).image.img = mlx_new_image
		((*fdf).mlx_ptr, SCREEN_SIZE_X, SCREEN_SIZE_Y);
	(*fdf).image.addr = mlx_get_data_addr(
			(*fdf).image.img, &(*fdf).image.bits_per_pixel,
			&(*fdf).image.line_length, &(*fdf).image.endian);
}
