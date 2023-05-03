/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:57:03 by loadjou           #+#    #+#             */
/*   Updated: 2023/05/03 07:46:22 by hsaadi           ###   ########.fr       */
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
# define HEIGHT 1080
# define PI 3.14159265359
# define X 0
# define Y 1

# define VOID 2604087295
# define WALLS 0
# define BG 0x213AA9

# define WE 0
# define SO 1
# define EA 2
# define NO 3

/* ***** COLORS ***** */
# define RESET "\e[0m"
# define BBLK "\e[1;30m"
# define BRED "\e[1;31m"
# define BGREEN "\e[1;32m"
# define BYEL "\e[1;33m"
# define BBLUE "\e[1;34m"
# define BMAG "\e[1;35m"
# define BCYAN "\e[1;36m"
# define BWHT "\e[1;37m"

/* *************** ***************           *************** *************** */
/*                                   STRUCTS                                 */
/* *************** ***************           *************** *************** */
typedef struct s_map
{
	int				width;
	int				height;
	char			**map;
	t_mini_m		*mini_m;
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_texture_t	*east;
	UINT			floor;
	UINT			ceil;
	float			sq_size;
	float			cell_size;
}					t_map;

typedef struct s_cub
{
	mlx_t			*mlx;
	mlx_image_t		*win;
	t_map			*map;
	mlx_texture_t	*texture;
	int				dest[2];
	float			coord[2];
	size_t			p_x;
	size_t			p_y;
	char			p_dir;
	float			odo;
	float			p_a;
	float			starting_a;
	float			ray_x;
	float			ray_y;
	float			ray_a;
	float			pdx;
	float			pdy;
	float			fov;
}					t_cub;

/* *************** ***************           *************** *************** */
/*                                 FUNCTIONS                                 */
/* *************** ***************           *************** *************** */

/* ***************  INIT  *************** */
void				init_game(t_cub *cub);
void				free_game(t_cub *cub);

/* ***************  PARSING  *************** */
bool				parse_map(t_cub *cub, char *file);
t_cub				*init_cub(void);
bool				flood_fill_check(t_cub *cub);
bool				floodfill(t_cub *cub, char **filled_map, int i, int j);
bool				manage_settings(t_map *map, char *line);
bool				store_map_cases(t_cub *cub, char *line);
char				*normalize_chars(char *line);

/* ***************  COLOR  *************** */
bool				load_color(UINT *c, char *line);

/* ***************  MINI_MAP  *************** */
void				moves_hook(void *param);
void				print_mini_map(t_cub *cub);
void				print_square(t_cub *cub, uint32_t x, uint32_t y,
						uint32_t color);
UINT				get_rgba(int r, int g, int b, int a);
void				move_p_hook(void *param);
bool				get_p_angle(t_cub *cub);

/* ***************  MOVE_UTILS  *************** */
void				rotate(t_cub *cub);
/* ***************  RAYCASTING  *************** */

void				draw_fov(t_cub *cub);
float				normalize_angle(float angle);
float				deg_to_rad(float a);
bool				cast_ray(t_cub *cub, float angle, int pos_x);
void				cast_fov(t_cub *cub);
bool				fov(t_cub *cub, float angle);
void				draw_fov(t_cub *cub);
int					get_text_dir(t_cub *cub, float angle);
mlx_texture_t		*get_texture(t_cub *cub, float dest[2]);
uint32_t			get_px(mlx_texture_t *buff, int x, int y);
bool				is_wall(t_cub *cub, float destx, float desty);
void				get_pcoordinates(t_cub *cub);
bool				valid_elements(t_cub *cub, char c);

#endif
