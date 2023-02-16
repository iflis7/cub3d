/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 00:01:34 by hsaadi            #+#    #+#             */
/*   Updated: 2023/02/16 10:17:01 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * @brief Init the line struct
 * 
 * @return t_mini_m* The line struct
 */
t_mini_m	*init_map_line()
{
	t_mini_m	*mini_m;

	mini_m = malloc(sizeof(t_mini_m));
	if (!mini_m)
		ft_msg_err("Error: malloc failed.");
	mini_m->line = NULL;
	mini_m->next = NULL;
	mini_m->prev = NULL;
	mini_m->place = 0;
	return (mini_m);
}

/**
 * @brief Init the map struct
 * 
 * @return t_map* The map struct
 */

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		ft_msg_err("Error: malloc failed.");
	map->width = 0;
	map->height = 0;
	map->ceil = 0;
	map->floor = 0;
	map->north = NULL;
	map->south = NULL;
	map->west = NULL;
	map->east = NULL;
	map->nb_lines = 1;
	map->max_line_len = 0;
	map->mini_m = init_map_line();
	return (map);
}

/**
 * @brief Init the cub struct
 * 
 * @return t_cub* The cub struct
 */

t_cub	*init_cub(void)
{
	t_cub	*cub;

	cub = malloc(sizeof(t_cub));
	if (!cub)
		ft_msg_err("Error: malloc failed.");
	cub->map = init_map();
	// cub->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", true);
	cub->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", false);
	if (!cub->mlx)
		exit(EXIT_FAILURE);
	cub->p_dir = 0;
	return (cub);
}

/**
 * @brief Init the game with the given cub struct
 * 
 * @param cub The cub struct
 */
void	init_game(t_cub *cub)
{
	// mlx_texture_t	*icon;

	// icon = NULL;
	cub->fov = M_PI / 3;
	cub->ray_depth = 30;
	get_p_angle(cub);
	// printf("1Main cub->x:: %ld ---- cub->y:: %ld\n", cub->p_x, cub->p_y);
	get_pcoordinates(cub);
	// printf("2Main cub->x:: %ld ---- cub->y:: %ld\n", cub->p_x, cub->p_y);
	cub->pdx = cos(cub->p_a) * 5;
	cub->pdy = cos(cub->p_a) * 5;
	cub->win = mlx_new_image(cub->mlx, cub->mlx->width, cub->mlx->height);
	mlx_set_cursor_mode(cub->mlx, MLX_MOUSE_NORMAL);  // show the mouse on the window
	mlx_image_to_window(cub->mlx, cub->win, 0, 0);
	// int fd =  open("assets/iflisen.png", O_RDONLY);
	// printf("FD: %d\n", fd);
	// icon = mlx_load_png("assets/iflisen.png");
	// printf("icon: %p\n", icon);
	// mlx_set_icon(cub->mlx, icon);
}
