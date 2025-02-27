/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawlines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:11:04 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/27 19:29:41 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	gradient(int startcolor, int endcolor, int len, int pix);
int	get_steps(int point1, int point2);

void	drawline_low(t_fdf *fdf, t_point start, t_point dest, int steps)
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

void	drawline_high(t_fdf *fdf, t_point start, t_point dest, int steps)
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
	int	steps;
	int	increment;

	start.x += SCREEN_SIZE_X / 4;
	start.y += SCREEN_SIZE_Y / 2;
	dest.x += SCREEN_SIZE_X / 4;
	dest.y += SCREEN_SIZE_Y / 2;
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

/*# define T(a) ((a) >> 24) & 0xFF
# define R(a) ((a) >> 16) & 0xFF
# define G(a) ((a) >> 8) & 0xFF
# define B(a) (a) & 0xFF
# define RGB(r, g, b) ((0xFF << 24) | ((r) << 16) | ((g) << 8) | (b))
*/

int	gradient(int startcolor, int endcolor, int len, int pix)
{
	double	increment[3];
	int		new[3];
	int		newcolor;

	increment[0] = (double)((R(endcolor)) - (R(startcolor))) / (double)len;
	increment[1] = (double)((G(endcolor)) - (G(startcolor))) / (double)len;
	increment[2] = (double)((B(endcolor)) - (B(startcolor))) / (double)len;
	new[0] = (R(startcolor)) + round(pix * increment[0]);
	new[1] = (G(startcolor)) + round(pix * increment[1]);
	new[2] = (B(startcolor)) + round(pix * increment[2]);
	newcolor = RGB((new[0]), new[1], new[2]);
	return (newcolor);
}
