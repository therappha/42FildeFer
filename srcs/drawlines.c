/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawlines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:11:04 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/15 23:11:48 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int gradient(int startcolor, int endcolor, int len, int pix);
int	get_steps(int point1, int point2);
#define LEFT  1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

// Check if the point is inside the screen or outside
int computeOutcode(t_point p) {
    int code = 0;
    if (p.x < 0) code |= LEFT;
    if (p.x > SCREEN_SIZE_X) code |= RIGHT;
    if (p.y < 0) code |= BOTTOM;
    if (p.y > SCREEN_SIZE_Y) code |= TOP;
    return code;
}

// Cohen-Sutherland line clipping function that takes two t_point arguments
void clipLine(t_point *start, t_point *dest) {
    int outcode0 = computeOutcode(*start);
    int outcode1 = computeOutcode(*dest);
    int accept = 0;

    while (1) {
        if (!(outcode0 | outcode1)) {
            // Both points inside, accept the line
            accept = 1;
            break;
        } else if (outcode0 & outcode1) {
            // Both points outside, reject the line
            break;
        } else {
            // Calculate the intersection point
            int x, y;
            int outcodeOut = outcode0 ? outcode0 : outcode1;

            // Find the intersection point
            if (outcodeOut & TOP) {
                x = start->x + (dest->x - start->x) * (SCREEN_SIZE_Y - start->y) / (dest->y - start->y);
                y = SCREEN_SIZE_Y;
            } else if (outcodeOut & BOTTOM) {
                x = start->x + (dest->x - start->x) * (0 - start->y) / (dest->y - start->y);
                y = 0;
            } else if (outcodeOut & RIGHT) {
                y = start->y + (dest->y - start->y) * (SCREEN_SIZE_X - start->x) / (dest->x - start->x);
                x = SCREEN_SIZE_X;
            } else if (outcodeOut & LEFT) {
                y = start->y + (dest->y - start->y) * (0 - start->x) / (dest->x - start->x);
                x = 0;
            }

            // Update the point that was outside
            if (outcodeOut == outcode0) {
                start->x = x;
                start->y = y;
                outcode0 = computeOutcode(*start);
            } else {
                dest->x = x;
                dest->y = y;
                outcode1 = computeOutcode(*dest);
            }
        }
    }
}


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

	clipLine(&start, &dest);
	//start.y -= 500;
	//dest.y -= 500;
	//start.x -= 300;
	//dest.x -= 300;
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
