/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawlines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:11:04 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/03/08 21:58:39 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	drawline_low(t_fdf *fdf, t_point start, t_point dest)
{
	t_drawline	line;
	int			i;

	line.dx = dest.x - start.x;
	line.dy = dest.y - start.y;
	line.yi = 1;
	if (line.dy < 0)
	{
		line.yi = -1;
		line.dy = -line.dy;
	}
	line.d = (2 * line.dy) - line.dx;
	i = 0;
	while (start.x <= dest.x)
	{
		line.color = gradient(start.color, dest.color, line.dx, i++);
		ft_pixelput(&fdf->image, start.x++, start.y, line.color);
		if (line.d > 0)
		{
			start.y = start.y + line.yi;
			line.d = line.d + (2 * (line.dy - line.dx));
		}
		else
			line.d = line.d + 2 * line.dy;
	}
}

void	drawline_high(t_fdf *fdf, t_point start, t_point dest)
{
	t_drawline	line;
	int			i;

	i = 0;
	line.dx = dest.x - start.x;
	line.dy = dest.y - start.y;
	line.xi = 1;
	if (line.dx < 0)
	{
		line.xi = -1;
		line.dx = -line.dx;
	}
	line.d = (2 * line.dx) - line.dy;
	while (start.y <= dest.y)
	{
		line.color = gradient(start.color, dest.color, line.dy, i++);
		ft_pixelput(&fdf->image, start.x, start.y++, line.color);
		if (line.d > 0)
		{
			start.x = start.x + line.xi;
			line.d = line.d + (2 * (line.dx - line.dy));
		}
		else
			line.d = line.d + 2 * line.dx;
	}
}

void	drawline(t_fdf *fdf, t_point start, t_point dest)
{
	start.x += SCREEN_SIZE_X / 4;
	start.y += SCREEN_SIZE_Y / 2;
	dest.x += SCREEN_SIZE_X / 4;
	dest.y += SCREEN_SIZE_Y / 2;
	if (abs(dest.y - start.y) < abs(dest.x - start.x))
	{
		if (start.x > dest.x)
			drawline_low(fdf, dest, start);
		else
			drawline_low(fdf, start, dest);
	}
	else
	{
		if (start.y > dest.y)
			drawline_high(fdf, dest, start);
		else
			drawline_high(fdf, start, dest);
	}
}
