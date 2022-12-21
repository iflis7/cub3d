#ifndef CUB3D_H
# define CUB3D_H

/* *************** ***************           *************** *************** */
/*                                  INCLUDES                                 */
/* *************** ***************           *************** *************** */
# include "../include/utils.h"
# include "../mlx/include/MLX42/MLX42.h"
# include "libft/includes/libft.h"
# include "utils.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/* *************** ***************           *************** *************** */
/*                                   MACROS                                  */
/* *************** ***************           *************** *************** */
# define WIDTH 1920
# define HEIGHT 1080

/* *************** ***************           *************** *************** */
/*                                   STRUCTS                                 */
/* *************** ***************           *************** *************** */

typedef struct s_map
{
	int			width;
	int			height;
	t_line		*line;
	char 		*north; // TODO change to mlx_image_t once the image is loaded
	char		*south;
	char		*west;
	char		*east;
	char		*floor;
	char		*ceiling;
}				t_map;

typedef struct s_cub
{
	// char		*name;
	mlx_t		*mlx;
	mlx_image_t	*win;
	t_map		*map;
	// t_cam	*cam;
	// t_mouse	*mouse;

}				t_cub;

/* *************** ***************           *************** *************** */
/*                                 FUNCTIONS                                 */
/* *************** ***************           *************** *************** */

/* ***************  INIT  *************** */

/* ***************  PARSING  *************** */
bool			parse_map(t_cub *cub, char *file);

t_cub			*init_cub(void);

#endif