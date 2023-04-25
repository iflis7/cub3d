/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:57:03 by loadjou           #+#    #+#             */
/*   Updated: 2023/04/25 15:58:00 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define PI 3.14159265359
# define X 0
# define Y 1
// # define HEIGHT 1080

# define HEIGHT 1000

/* *************** ***************           *************** *************** */
/*                                   STRUCTS                                 */
/* *************** ***************           *************** *************** */
typedef struct s_map
{
	int			width;
	int			height;
	char		**map;
	char		**mini_map;
	t_mini_m	*mini_m;
	xpm_t 		*north; // TODO change to mlx_image_t
	xpm_t		*south;
	xpm_t		*west;
	xpm_t		*east;
	UINT		floor;
	UINT		ceil;
	float		sq_size;
}				t_map;

typedef struct s_cub
{
	mlx_t		*mlx;
	mlx_image_t	*win;
	t_map		*map;
	mlx_image_t	*player;
	mlx_image_t	*lhid;
	mlx_image_t	*tagnit;
	int			dest[2];
	size_t		p_x;
	size_t		p_y;
	float		coord[2];
	char		p_dir;
	float		odo;
	float		p_a;
	float		ray_x;
	float		ray_y;
	float		ray_a;
	float		pdx;
	float		pdy;
	float		fov;

}				t_cub;

/* *************** ***************           *************** *************** */
/*                                 FUNCTIONS                                 */
/* *************** ***************           *************** *************** */

/* ***************  INIT  *************** */
void			init_game(t_cub *cub);

/* ***************  PARSING  *************** */
bool			parse_map(t_cub *cub, char *file);
t_cub			*init_cub(void);

bool			flood_fill_check(t_cub *cub);
bool			floodfill(t_cub *cub, bool **filled_map, int i, int j);
void			print_map(char **mini_m);
bool			manage_settings(t_map *map, char *line);

// TODO move to utils.h
void			print_mini_map(t_cub *cub);
/* ***************  COLOR  *************** */
void			load_color(UINT *c, char *line);

/* ***************  MINI_MAP  *************** */
// bool			img_init(t_cub *cub);
void			moves_hook(void *param);
void			print_mini_map(t_cub *cub);
void			print_square(t_cub *cub, uint32_t x, uint32_t y,
					uint32_t color);

UINT			get_rgba(int r, int g, int b, int a);
void			move_p_hook(void *param);
bool			get_p_angle(t_cub *cub);

/* ***************  MOVE_UTILS  *************** */
void			rotate(t_cub *cub);
/* ***************  RAYCASTING  *************** */

void			draw_fov(t_cub *cub);
float			normalize_angle(float angle);
float			deg_to_rad(float a);
bool			cast_ray(t_cub *cub, float angle, int pos_x);
void			cast_fov(t_cub *cub);
bool			is_wall(t_cub *cub, float destx, float desty);
void			get_pcoordinates(t_cub *cub);
void			print_mini_map(t_cub *cub);
int				ft_msg_err_close(char *error, int *fd);
bool			valid_elements(t_cub *cub, char c);
#endif
