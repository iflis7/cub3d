#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// # include "../libft/libft.h"

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define TILE_SIZE 64
# define FOV_ANGLE 60 * (M_PI / 180)

# define NUM_RAYS 1200

# define MINIMAP_SCALE_FACTOR 0.3

# define FALSE 0
# define TRUE 1

# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

# define NUM_TEXTURES 5

# define NUM_ROWS 11
# define NUM_COLS 15

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_img;

#endif