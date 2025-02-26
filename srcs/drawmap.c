/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:04:57 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/26 19:57:53 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		get_color(char *str);
void	drawline_down(t_fdf *fdf, t_point iterate,
			char **c_line, char **n_line);
void	drawline_right(t_fdf *fdf, t_point iterate, char **c_line);

void	drawmap(t_fdf *fdf, t_line **line, int distance)
{
	t_line	*current_line;
	char	**current_array;
	char	**next_array;
	t_point	iterate;

	iterate.y = 0;
	current_line = (*line);
	while (current_line)
	{
		iterate.x = 0;
		next_array = NULL;
		current_array = current_line -> line;
		if (current_line -> next)
			next_array = current_line -> next -> line;
		while (current_array[iterate.x])
		{
			if (current_array[iterate.x + 1])
				drawline_right(fdf, iterate, current_array);
			if (next_array && next_array[iterate.x])
				drawline_down(fdf, iterate, current_array, next_array);
			iterate.x++;
		}
		current_line = current_line -> next;
		iterate.y++;
	}
}

void	drawline_right(t_fdf *fdf, t_point iterate, char **c_line)
{
	t_point	start;
	t_point	dest;

	start = iterate;
	start.color = get_color(c_line[iterate.x]);
	start = cart_to_iso(start, c_line[iterate.x], (*fdf).scale, start.color);
	dest.x = iterate.x + 1;
	dest.y = iterate.y;
	dest.color = get_color(c_line[iterate.x + 1]);
	dest = cart_to_iso(dest, c_line[iterate.x + 1], (*fdf).scale, dest.color);
	drawline(fdf, start, dest);
}

void	drawline_down(t_fdf *fdf, t_point iterate, char **c_line, char **n_line)
{
	t_point	start;
	t_point	dest;

	start = iterate;
	start.color = get_color(c_line[iterate.x]);
	start = cart_to_iso(start, c_line[iterate.x], (*fdf).scale, start.color);
	dest.x = iterate.x;
	dest.y = iterate.y + 1;
	dest.color = get_color(n_line[iterate.x]);
	dest = cart_to_iso(dest, n_line[iterate.x], (*fdf).scale, dest.color);
	drawline(fdf, start, dest);
}

int	get_color(char *str)
{
	int		color;
	char	*colorstr;

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


