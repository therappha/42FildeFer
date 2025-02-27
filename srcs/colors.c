/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:16:49 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/27 20:30:58 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int R(int color)
{
	return ((color >> 16) & 0xFF);
}
int G(int color)
{
	return ((color >> 8)  & 0xFF);
}
int B(int color)
{
	return (color & 0xFF);
}
int RGB(int r, int g, int b)
{
	return ( 0xFF << 24 | r << 16 | g << 8 | b);
}

int	gradient(int startcolor, int endcolor, int goal, int pix)
{
	t_color color;
	int		newcolor;

	color.step_r = (double)((R(endcolor)) - (R(startcolor))) / (double)goal;
	color.step_g = (double)((G(endcolor)) - (G(startcolor))) / (double)goal;
	color.step_b = (double)((B(endcolor)) - (B(startcolor))) / (double)goal;
	color.r = (R(startcolor)) + (pix * color.step_r);
	color.g = (G(startcolor)) + (pix * color.step_g);
	color.b = (B(startcolor)) + (pix * color.step_b);
	newcolor = RGB(color.r, color.g, color.b);
	return (newcolor);
}

