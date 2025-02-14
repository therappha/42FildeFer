/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:34:13 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/14 20:18:10 by rafaelfe         ###   ########.fr       */
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

typedef struct s_map
{
	t_vector	*line;
	int			line_count;
	struct	s_map *next;
}	t_map;

typedef	struct	s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		scale;
	int		map_width;
	int		map_height;
	int 	focal_length;
	t_map	*map;
	t_image	image;

}	t_fdf;

#ifndef SCREEN_SIZE_X
#define SCREEN_SIZE_X 1900
#endif
#ifndef SCREEN_SIZE_Y
#define SCREEN_SIZE_Y 1020
#endif
#ifndef FOCAL_LENGTH
#define FOCAL_LENGTH 100
#endif

void	drawline(t_fdf *fdf, t_point start, t_point dest);
int		free_displays(t_fdf *fdf);
int		get_color(char *str);
void	ft_pixelput(t_image *data, int x, int y, int color);

//linked list utils
t_map	*ft_newmap(char *line, int line_count, t_fdf *fdf);
void	ft_mapaddback(t_map **map, t_map *node);
void	ft_freemap(t_map **map);

//map parsing
t_map	*read_map(char *str, t_fdf *fdf);
void	drawmap(t_fdf *fdf);

//math prototypes
void	rotate_all(t_vector *v, int angle_x, int angle_y, int angle_z);
# define T(a) ((a) >> 24) & 0xFF
# define R(a) ((a) >> 16) & 0xFF
# define G(a) ((a) >> 8) & 0xFF
# define B(a) (a) & 0xFF
# define RGB(r, g, b) ((0xFF << 24) | ((r) << 16) | ((g) << 8) | (b))

# endif
