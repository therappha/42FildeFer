/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_displays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:41:42 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/14 15:08:30 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	free_displays(t_fdf *fdf)
{
	mlx_destroy_window((fdf) -> mlx_ptr, (fdf) -> win_ptr );
	mlx_destroy_display((fdf) -> mlx_ptr);
	free((fdf) -> mlx_ptr);
	ft_freemap((fdf->map));
	ft_printf("Closing Application!");
	exit(1);
	return (0);
}

