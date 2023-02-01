#ifndef CUB3D_H
# define CUB3D_H

/* *************** ***************           *************** *************** */
/*                                  INCLUDES                                 */
/* *************** ***************           *************** *************** */
# include "../include/utils.h"
# include "../mlx/include/MLX42/MLX42.h"
# include "libft/includes/libft.h"
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
	t_mini_m	*mini_m;
	char *north; // TODO change to mlx_image_t once the image is loaded
	char		*south;
	char		*west;
	char		*east;
	UINT		floor;
	UINT		ceil;
	int max_line_len;
	int chunk_cub;
	int nb_lines;
}				t_map;

typedef struct s_cub
{
	mlx_t		*mlx;
	mlx_image_t	*win;
	t_map		*map;

	mlx_image_t *player;
	float		player_angle;
	float		fov;
	int			ray_depth;

}				t_cub;

/* *************** ***************           *************** *************** */
/*                                 FUNCTIONS                                 */
/* *************** ***************           *************** *************** */

/* ***************  INIT  *************** */
void			init_game(t_cub *cub);

/* ***************  PARSING  *************** */
bool			parse_map(t_cub *cub, char *file);
t_cub			*init_cub(void);

bool			manage_settings(t_map *map, char *line);
// TODO move to utils.h
bool			only_ones(char *line);

bool			first_and_last(char *line);
void    print_mini_map(t_cub *cub);

/* ***************  COLOR  *************** */
void			load_color(UINT *c, char *line);


UINT	get_rgba(int r, int g, int b, int a);
void	move_hook(void *param);

#endif
