/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 00:01:34 by hsaadi            #+#    #+#             */
/*   Updated: 2023/05/02 18:00:36 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// /**
//  * @brief Init the line struct
//  * 
//  * @return t_mini_m* The line struct
//  */
// t_mini_m	*init_map_line(void)
// {
// 	t_mini_m	*mini_m;

// 	mini_m = ft_calloc(sizeof(t_mini_m), 1);
// 	ptr_addr("mini_m lqehba", (void *)mini_m);
// 	if (!mini_m)
// 		ft_msg_err("Error: malloc failed.");
// 	mini_m->line = NULL;
// 	mini_m->next = NULL;
// 	mini_m->prev = NULL;
// 	mini_m->place = 0;
// 	return (mini_m);
// }

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
	map->map = NULL;
	map->height = 0;
	map->width = 0;
	return (map);
}

t_cub	*init_cub(void)
{
	t_cub	*cub;

	cub = malloc(sizeof(t_cub));
	if (!cub)
		ft_msg_err("Error: malloc failed.");
	cub->map = init_map();
	cub->coord[X] = 0;
	cub->coord[Y] = 0;
	cub->pdx = 0;
	cub->pdy = 0;
	cub->odo = 0;
	cub->p_dir = 0;
	cub->check = 0;
	return (cub);
}

/**
 * @brief Init the game with the given cub struct
 * 
 * @param cub The cub struct
 */
void	init_game(t_cub *cub)
{
	cub->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", false);
	if (!cub->mlx)
		exit(EXIT_FAILURE);
	cub->map->cell_size = fminf((0.2 * cub->mlx->width) / cub->map->width,
			(0.2 * cub->mlx->height) / cub->map->height);
	cub->map->sq_size = 64;
	if (cub->map->sq_size < 1)
		cub->map->sq_size = 1;
	cub->fov = M_PI / 3;
	get_p_angle(cub);
	get_pcoordinates(cub);
	cub->win = mlx_new_image(cub->mlx, cub->mlx->width, cub->mlx->height);
	if (!cub->win)
		exit(EXIT_FAILURE);
	mlx_set_cursor_mode(cub->mlx, MLX_MOUSE_NORMAL);
	mlx_image_to_window(cub->mlx, cub->win, 0, 0);
}
