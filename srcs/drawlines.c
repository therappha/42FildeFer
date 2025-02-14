/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawlines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:11:04 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/14 18:24:21 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int gradient(int startcolor, int endcolor, int len, int pix);
int	get_steps(int point1, int point2);

void	drawline_low(t_fdf *fdf, t_point start, t_point dest, int steps)
{
	t_line	line;
	int		i;

	line.dx = dest.x - start.x;
	line.dy = dest.y - start.y;
	line.yi = 1;
	if (line.dy < 0)
	{
		line.yi = -1;
		line.dy = -line.dy;
	}
	line.D = (2 * line.dy) - line.dx;
	i = 0;
	while (start.x <= dest.x)
	{
		line.color = gradient(start.color, dest.color, line.dx, i++);
		ft_pixelput(&fdf->image, start.x++, start.y, line.color);
		if (line.D > 0)
		{
			start.y = start.y + line.yi;
			line.D = line.D + (2 * (line.dy - line.dx));
		}
		else
			line.D = line.D + 2 * line.dy;
	}
}

void	drawline_high(t_fdf *fdf, t_point start, t_point dest, int steps)
{
	t_line	line;
	int		i;

	i = 0;
	line.dx = dest.x - start.x;
	line.dy = dest.y - start.y;
	line.xi = 1;
	if (line.dx < 0)
	{
		line.xi = -1;
		line.dx = -line.dx;
	}
	line.D = (2 * line.dx) - line.dy;
	while (start.y <= dest.y)
	{
		line.color = gradient(start.color, dest.color, line.dy, i++);
		ft_pixelput(&fdf->image, start.x, start.y++, line.color);
		if (line.D > 0)
		{
			start.x = start.x + line.xi;
			line.D = line.D + (2 * (line.dx - line.dy));
		}
		else
			line.D = line.D + 2 * line.dx;
	}
}

void	drawline(t_fdf *fdf, t_point start, t_point dest)
{
	int steps;
	int increment;
	//steps = ABS_MAX((x1-x0), (y1-y0)) || steps = distance
	steps = get_steps(dest.x - start.x, dest.y - start.y);

	if (abs(dest.y - start.y) < abs(dest.x - start.x))
	{
		if (start.x > dest.x)
			drawline_low(fdf, dest, start, steps);
		else
			drawline_low(fdf, start, dest, steps);
	}
	else
	{
		if (start.y > dest.y)
			drawline_high(fdf, dest, start, steps);
		else
			drawline_high(fdf, start, dest, steps);
	}
}
int	get_steps(int point1, int point2)
{
	if (abs(point1) > abs(point2))
		return (abs(point1));
	else
		return (abs(point2));
}
int gradient(int startcolor, int endcolor, int len, int pix)
{
	double increment[3];
	int new[3];
	int newcolor;

	increment[0] = (double)((R(endcolor)) - (R(startcolor))) / (double)len;
	increment[1] = (double)((G(endcolor)) - (G(startcolor))) / (double)len;
	increment[2] = (double)((B(endcolor)) - (B(startcolor))) / (double)len;
	new[0] = (R(startcolor)) + round(pix * increment[0]);
	new[1] = (G(startcolor)) + round(pix * increment[1]);
	new[2] = (B(startcolor)) + round(pix * increment[2]);
	newcolor = RGB((new[0]), new[1], new[2]);
	return (newcolor);
}
