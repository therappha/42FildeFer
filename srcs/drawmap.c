/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:46:27 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/14 20:53:58 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point vec_to_2d(t_vector vector, int focal_length)
{
	t_point isometric;
	isometric.x = vector.x + vector.y;
	isometric.y = vector.y - vector.x - vector.z;
	isometric.color = vector.color;
	return isometric;
}

void	drawmap(t_fdf *fdf)
{
	t_map	*line;
	t_map	*next_line;
	int		i;

	line = ((*fdf).map);
	next_line = line -> next;
	while (next_line)
	{
		i = 0;
		while (i < (*fdf).map_width)
		{
			if (i + 1 < ((*fdf).map_width))
			{
				drawline(fdf, vec_to_2d(line ->line[i], (*fdf).focal_length), vec_to_2d(line ->line[i + 1], (*fdf).focal_length));
			}
			if (next_line)
			{
				drawline(fdf, vec_to_2d(line ->line[i], (*fdf).focal_length), vec_to_2d(next_line ->line[i], (*fdf).focal_length));
			}
			i++;
		}
		line = next_line;
		next_line = next_line -> next;
	}
}
