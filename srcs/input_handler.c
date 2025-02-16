/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 23:59:59 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/16 00:54:51 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	input_handler(int key, t_fdf *fdf)
{
	if (key == XK_Left)
	{
		(*fdf).y_angle--;
	}
	if (key == XK_Right)
	{
		(*fdf).y_angle++;
	}
	if (key == XK_Up)
	{
		(*fdf).x_angle++;
	}
	if (key == XK_Down)
	{
		(*fdf).x_angle--;
	}
	if (key == XK_W || key == XK_w)
	{
		(*fdf).z_move++;
	}
	if (key == XK_s || key == XK_S)
		(*fdf).z_move--;
	if (key == XK_a || key == XK_A)
	{
		(*fdf).x_move++;
	}
	if (key == XK_D || key == XK_d)
		(*fdf).x_move--;
	if (key == XK_space)
		(*fdf).y_move--;
	if (key == XK_Shift_L)
		(*fdf).y_move++;
	drawmap(fdf);

}
