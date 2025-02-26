/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:34:13 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/02/26 22:06:54 by rafaelfe         ###   ########.fr       */
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

# define SCREEN_SIZE_X 1920
# define SCREEN_SIZE_Y 1080

typedef struct s_point
{
	int	x;
	int	y;
	int	color;
}	t_point;

typedef struct s_line
{
	char			**line;
	struct s_line	*next;
}	t_line;

typedef struct s_drawline
{
	int	dx;
	int	dy;
	int	xi;
	int	yi;
	int	d;
	int	color;
}	t_drawline;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		map_x;
	int		map_y;
	int		scale;
	t_image	image;
}	t_fdf;

void	drawline(t_fdf *fdf, t_point start, t_point dest);
void	drawmap(t_fdf *fdf, t_line **line);
int		read_map(t_line **map_line, t_fdf *fdf, char *av);
int		free_displays(t_fdf *fdf);
void	ft_pixelput(t_image *data, int x, int y, int color);
int		input_handler(int keysym, t_fdf *fdf);

//math convertions
t_point	cart_to_iso(t_point cartesian, char *s_height, int distance, int color);
int		ft_atoi_16(char *str);
//struct utils
void	ft_linefree(t_line **line);
t_line	*ft_newline(t_fdf *fdf, char **content);
void	ft_lineadd_back(t_line **lst, t_line *new);
int		ft_linelen(char **line);
int		get_scale(t_fdf *fdf);

# define T(a) ((a) >> 24) & 0xFF
# define R(a) ((a) >> 16) & 0xFF
# define G(a) ((a) >> 8) & 0xFF
# define B(a) (a) & 0xFF
# define RGB(r, g, b) ((0xFF << 24) | ((r) << 16) | ((g) << 8) | (b))

#endif
