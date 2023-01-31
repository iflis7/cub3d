#include "../../include/cub3d.h"

// void	hook(void *param)
// {
// 	mlx_t	*mlx;
// 	mlx = param;
// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	if (mlx_is_key_down(mlx, MLX_KEY_UP))
// 		g_img->instances[0].y -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
// 		g_img->instances[0].y += 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
// 		g_img->instances[0].x -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
// 		g_img->instances[0].x += 5;
// }

void	main_hook(void *param)
{
	unsigned int	i;

	t_cub *const cub = param;
	i = 0;
	while (i < WIDTH * HEIGHT)
	{
		if (i < WIDTH * (HEIGHT / 2))
			mlx_put_pixel(cub->win, i, 0, cub->map->ceil);
		else if (i > WIDTH * (HEIGHT / 2))
			mlx_put_pixel(cub->win, i, 0, cub->map->floor);
		i++;
	}
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cub->mlx);
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	if (argc == 2)
	{
		cub = init_cub();
		// (void)argv;
		// (void)cub;
		parse_map(cub, argv[1]);
		init_game(cub);
		print_map_lines(cub->map->mini_m);
		// printf("map->north %s\n", cub->map->north);
		// printf("map->south %s\n", cub->map->south);
		// printf("map->east %s\n", cub->map->east);
		// printf("map->west %s\n", cub->map->west);
		// printf("map->floor %d\n", cub->map->floor);
		// printf("map->ceil %d\n", cub->map->ceil);
		mlx_loop_hook(cub->mlx, &main_hook, cub);
		mlx_loop(cub->mlx);
		mlx_terminate(cub->mlx);
		return (EXIT_SUCCESS);
	}
	else
		ft_msg_err("No map given.");
}
