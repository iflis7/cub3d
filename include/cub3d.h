#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <string.h>

// # include "libft.h"
// # include "get_next_line.h"

#define WIDTH 1920
#define HEIGHT 1080


typedef struct s_cub3d
{
	// t_map	*map;
	void	*mlx;
	void	*win;
	mlx_image_t	*g_img;
	// t_cam	*cam;
	// t_mouse	*mouse;

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}			t_cub3d;

#endif