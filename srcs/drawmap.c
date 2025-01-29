/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:04:57 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/28 23:24:06 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	get_color(char *str);

void drawmap(t_fdf **fdf, t_line **line, int distance)
{
	t_line *current_line;
	t_point start;
	t_point dest;
	char **current_array;
	char **next_array;
	int	line_count;
	int	i;
	int	j;
	i = 0;
	j = 0;
	line_count = 0;
	start.color = 0;
	dest.color = 0;
	current_line = (*line);
	while (current_line)
	{
		i = 0;
		next_array = NULL;
		current_array = current_line -> line;
		if (current_line -> next)
			next_array = current_line -> next -> line;
		while (current_array[i])
		{
				start.x = i;
				start.y = line_count;
				start.color = get_color(current_array[i]);
				if (current_array[i + 1])
				{
					dest.x = (i + 1);
					dest.y = line_count;
					dest.color = get_color(current_array[i + 1]);
					drawline(fdf, cartesian_to_iso(start, current_array[i], distance, start.color), cartesian_to_iso(dest, current_array[i + 1], distance, dest.color));
				}
				if (next_array && next_array[i])
				{
					dest.x = (i);
					dest.y = line_count + 1;
					dest.color = get_color(next_array[i]);
					drawline(fdf, cartesian_to_iso(start, current_array[i], distance, start.color), cartesian_to_iso(dest, next_array[i], distance, dest.color));
				}
				i++;
		}
		current_line = current_line -> next;
		line_count++;
	}
}

int	get_color(char *str)
{
	int	color;
	char *colorstr;
	colorstr = NULL;
	colorstr = ft_strnstr(str, "0x", ft_strlen(str));
	if (colorstr)
		{
			color = ft_atoi_16(colorstr + 2);
		}
	else
		color = (0xFFFFFF);
	return (color);
}


