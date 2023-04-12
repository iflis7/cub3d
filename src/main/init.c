/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 00:01:34 by hsaadi            #+#    #+#             */
/*   Updated: 2023/04/12 14:51:24 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	
#include "../../include/cub3d.h"

void	init_imgs(t_cub *cub)
{
	// cub->lhid = mlx_new_image(cub->mlx, WIDTH, HEIGHT / 2);
	// memset(cub->lhid->pixels, 0xffffff, WIDTH * (HEIGHT / 2) * sizeof(int));
	// cub->tagnit = mlx_new_image(cub->mlx, cub->map->sq_size, cub->map->sq_size);
	// memset(cub->tagnit->pixels, 200, cub->map->sq_size * cub->map->sq_size * sizeof(int));
	cub->player = mlx_new_image(cub->mlx, cub->map->sq_size / 4, cub->map->sq_size / 4);
	memset(cub->player->pixels, 200, cub->map->sq_size / 4 * cub->map->sq_size / 4 * sizeof(int));
	
}

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
	map->map = NULL;
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

	cub->map->sq_size = fmin((0.2 * cub->mlx->width) / cub->map->max_line_len, (0.2 * cub->mlx->height) / cub->map->nb_lines);
	// cub->map->sq_size = 60;
	// cub->map->sq_size = 64;
	if(cub->map->sq_size < 1) // TODO do a better check esti!!
		exit(0);
	cub->map->mini_map = ft_calloc(cub->map->nb_lines + 1, sizeof(char *));
	cub->fov = M_PI / 3;
	cub->ray_depth = 30;
	get_p_angle(cub);
	get_pcoordinates(cub);
	cub->win = mlx_new_image(cub->mlx, cub->mlx->width, cub->mlx->height);
	mlx_set_cursor_mode(cub->mlx, MLX_MOUSE_NORMAL);
	// show the mouse on the window
	mlx_image_to_window(cub->mlx, cub->win, 0, 0);
	// Init player
	init_imgs(cub);
	mlx_image_to_window(cub->mlx, cub->player, cub->p_x + cub->map->sq_size / 4, cub->p_y + cub->map->sq_size / 4);
}

/*

*/