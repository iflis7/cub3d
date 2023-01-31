/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 00:01:34 by hsaadi            #+#    #+#             */
/*   Updated: 2023/01/30 11:18:06 by hsaadi           ###   ########.fr       */
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
	cub->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", true);
	if (!cub->mlx)
		exit(EXIT_FAILURE);
	cub->map = init_map();
	return (cub);
}

/**
 * @brief Init the game with the given cub struct
 * 
 * @param cub The cub struct
 */
void	init_game(t_cub *cub)
{
	cub->fov = (80 * M_PI / 180);
	cub->ray_depth = 30;
	cub->win = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	mlx_set_cursor_mode(cub->mlx, MLX_MOUSE_HIDDEN);
	mlx_image_to_window(cub->mlx, cub->win, 0, 0);
}
