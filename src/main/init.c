#include "../../include/cub3d.h"

t_line	*init_map_line()
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	if (!line)
		ft_msg_err("Error: malloc failed.");
	line->content = NULL;
	line->next = NULL;
	line->prev = NULL;
	line->place = 0;
	return (line);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		ft_msg_err("Error: malloc failed.");
	map->width = 0;
	map->height = 0;
	map->line = init_map_line();
	return (map);
}

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


void	init_game(t_cub *cub)
{
	cub->fov = (80 * M_PI / 180);
	cub->ray_depth = 30;
	cub->win = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	mlx_set_cursor_mode(cub->mlx, MLX_MOUSE_HIDDEN);
	mlx_image_to_window(cub->mlx, cub->win, 0, 0);
}
