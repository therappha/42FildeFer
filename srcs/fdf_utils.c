/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:07:28 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/16 00:31:52 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	char_value(char c)
{
	int	value;
	char *baselow = "0123456789abcdef";
	char *baseup = "0123456789ABCDEF";

	value = 0;
	while (c != baselow[value] && c != baseup[value])
		value++;
	if (c == baselow[value] || c == baseup[value])
		return (value);
	else
		return (-1);
}

int	ft_atoi_16(char *str)
{
	long	num;
	int		signal;

	num = 0;
	signal = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signal *= -1;
		str++;
	}
	while (*str && char_value(*str) != -1)
	{
		num = num * 16 + char_value(*str);
		str++;
	}
	num *= signal;
	return ((int)num);
}

int	get_color(char *str)
{
	int	color;
	char *colorstr;
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

void	ft_pixelput(t_image *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < SCREEN_SIZE_X && y >= 0 && y < SCREEN_SIZE_Y)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

void reset_image(t_fdf *fdf)
{
    if (fdf->image.img)
        mlx_destroy_image(fdf->mlx_ptr, fdf->image.img);

    fdf->image.img = mlx_new_image(fdf->mlx_ptr, SCREEN_SIZE_X, SCREEN_SIZE_Y);
    fdf->image.addr = mlx_get_data_addr(fdf->image.img, &fdf->image.bits_per_pixel,
                                        &fdf->image.line_length, &fdf->image.endian);
}
