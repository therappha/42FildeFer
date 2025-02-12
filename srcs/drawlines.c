/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawlines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:11:04 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/12 21:05:50 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int gradient(int startcolor, int endcolor, int len, int pix);
int	get_steps(int point1, int point2);

void	drawline_low(t_fdf *fdf, t_point start, t_point dest, int steps)
{
	int	dx;
	int	dy;
	int	yi;
	int	D;
	int color;
	int i;

	dx = dest.x - start.x;
	dy = dest.y - start.y;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	D = (2 * dy) - dx;
	i = 0;
	while (start.x <= dest.x)
	{
		color = gradient(start.color, dest.color, dx, i++);
		mlx_pixel_put((fdf)->mlx_ptr, (fdf)->win_ptr, start.x++, start.y, color);
		if (D > 0)
		{
			start.y = start.y + yi;
			D = D + (2 * (dy - dx));
		}
		else
			D = D + 2 * dy;
	}
}

void	drawline_high(t_fdf *fdf, t_point start, t_point dest, int steps)
{
	int	dx;
	int	dy;
	int	xi;
	int	D;
	int i;
	int color;
	i = 0;
	dx = dest.x - start.x;
	dy = dest.y - start.y;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	D = (2 * dx) - dy;
	while (start.y <= dest.y)
	{
		color = gradient(start.color, dest.color, dy, i++);
		mlx_pixel_put((fdf)->mlx_ptr, (fdf)->win_ptr, start.x, start.y++, color);
		if (D > 0)
		{
			start.x = start.x + xi;
			D = D + (2 * (dx - dy));
		}
		else
			D = D + 2 * dx;
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
