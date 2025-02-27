/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:04:57 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/27 21:32:25 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		get_color(char *str);
void	draw_down(t_fdf *fdf, t_point iterate, char **c_line, char **n_line);
void	draw_right(t_fdf *fdf, t_point iterate, char **c_line);

void	drawmap(t_fdf *fdf, t_line **line)
{
	t_line	*current_line;
	char	**cur_arr;
	char	**ne_arr;
	t_point	iterate;

	iterate.y = 0;
	current_line = (*line);
	while (current_line)
	{
		iterate.x = 0;
		ne_arr = NULL;
		cur_arr = current_line -> line;
		if (current_line -> next)
			ne_arr = current_line -> next -> line;
		while (cur_arr[iterate.x])
		{
			if (cur_arr[iterate.x + 1] && cur_arr[iterate.x + 1][0] != '\n')
				draw_right(fdf, iterate, cur_arr);
			if (ne_arr && ne_arr[iterate.x] && ne_arr[iterate.x][0] != '\n')
				draw_down(fdf, iterate, cur_arr, ne_arr);
			iterate.x++;
		}
		current_line = current_line -> next;
		iterate.y++;
	}
}

void	draw_right(t_fdf *fdf, t_point iterate, char **c_line)
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

void	draw_down(t_fdf *fdf, t_point iterate, char **c_line, char **n_line)
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
		color = ft_atoi_16(colorstr + 2);
	else
		color = (0xFFFFFF);
	return (color);
}
