/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:46:27 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/16 00:42:55 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point vec_to_2d(t_vector v, t_fdf *fdf) {
    t_point p;
	float x;
	float y;
	t_vector middle;
	middle.x = (*fdf).map_width / 2 * (*fdf).scale;
	middle.y = 0;
	middle.z = (*fdf).map_height / 2 * (*fdf).scale;
	v = rotate_around_point(v, middle, (*fdf).x_angle, (*fdf).y_angle, (*fdf).z_angle);
	v.z += 200;
	v.z += (*fdf).z_move * (*fdf).scale;
	v.y += (*fdf).y_move *  (*fdf).scale;
	v.x += (*fdf).x_move * (*fdf).scale;
    float fovRad = (FOCAL_LENGTH * M_PI) / 180.0;  // Convert FOV to radians
    float scale = tan(fovRad / 2);
    if (v.z <= 0) v.z = 0.01;  // Prevent division by zero
    // Perspective projection formula
    x = ((-v.x / (v.z * scale)) * SCREEN_SIZE_X / 2 + SCREEN_SIZE_X / 2);
    y = ((-v.y / (v.z * scale)) * SCREEN_SIZE_Y / 2 + SCREEN_SIZE_Y / 2);
	p.x = x;
	p.y = y;
	p.color = v.color;  // Preserve color
    return p;
}

void	drawmap(t_fdf *fdf)
{
	t_map	*line;
	t_map	*next_line;
	int		i;

	reset_image(fdf);
	line = ((*fdf).map);
	next_line = line -> next;
	while (next_line)
	{
		i = 0;
		while (i < (*fdf).map_width)
		{
			if (i + 1 < ((*fdf).map_width))
			{
				drawline(fdf, vec_to_2d(line ->line[i], fdf), vec_to_2d(line ->line[i + 1], fdf));
			}
			if (next_line)
			{
				drawline(fdf, vec_to_2d(line ->line[i],fdf ), vec_to_2d(next_line ->line[i], fdf));
			}
			i++;
		}
		line = next_line;
		next_line = next_line -> next;
	}
	mlx_put_image_to_window((*fdf).mlx_ptr, (*fdf).win_ptr, (*fdf).image.img, 0, 0);
}
