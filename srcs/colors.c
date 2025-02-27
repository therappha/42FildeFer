/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:16:49 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/27 21:43:50 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	get_r(int color)
{
	return ((color >> 16) & 0xFF);
}

int	get_g(int color)
{
	return ((color >> 8) & 0xFF);
}

int	get_b(int color)
{
	return (color & 0xFF);
}

int	get_rgb(int r, int g, int b)
{
	return (0xFF << 24 | r << 16 | g << 8 | b);
}

int	gradient(int startcolor, int endcolor, int len, int pix)
{
	t_color		color;
	int		newcolor;

	color.step_r = (double)(get_r(endcolor)) - (get_r(startcolor)) / (double)len;
	color.step_g = (double)(get_g(endcolor)) - (get_g(startcolor)) / (double)len;
	color.step_b = (double)(get_b(endcolor)) - (get_b(startcolor)) / (double)len;
	color.r = (get_r(startcolor)) + (pix * color.step_r);
	color.g = (get_g(startcolor)) + (pix * color.step_g);
	color.b = (get_b(startcolor)) + (pix * color.step_b);
	newcolor = get_rgb(color.r, color.g, color.b);
	return (newcolor);
}

