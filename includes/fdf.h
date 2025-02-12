/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:34:13 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/12 21:23:44 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libs/libft/includes/libft.h"
# include "../libs/mlx/mlx.h"
# include "../libs/mlx/mlx_int.h"
# include <strings.h>
# include <limits.h>
# include <math.h>

typedef struct	s_point
{
	int	x;
	int	y;
	int color;
}	t_point;

typedef struct s_line
{
	int	dx;
	int	dy;
	int	xi;
	int yi;
	int	D;
	int color;
}	t_line;

typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct	s_vector
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_vector;


typedef	struct	s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		scale;
	int		map_size;
	t_image	map_image;

}	t_fdf;

#ifndef SCREEN_SIZE_X
#define SCREEN_SIZE_X 1920
#endif
#ifndef SCREEN_SIZE_Y
#define SCREEN_SIZE_Y 1080
#endif
void	drawline(t_fdf *fdf, t_point start, t_point dest);
int		free_displays(t_fdf *fdf);
int		get_color(char *str);

//math prototypes

# define T(a) ((a) >> 24) & 0xFF
# define R(a) ((a) >> 16) & 0xFF
# define G(a) ((a) >> 8) & 0xFF
# define B(a) (a) & 0xFF
# define RGB(r, g, b) ((0xFF << 24) | ((r) << 16) | ((g) << 8) | (b))

# endif
