#include "../../include/cub3d.h"

void	moves_hook(void *param)
{
	t_cub	*cub;

	cub = param;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_UP))
		cub->player->instances[0].y -= 1;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_DOWN))
		cub->player->instances[0].y += 1;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT))
		cub->player->instances[0].x -= 1;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT))
		cub->player->instances[0].x += 1;
}

void	main_hook(void *param)
{
	unsigned int	i;

	t_cub *const cub = param;
	i = 0;
	while (i < WIDTH * HEIGHT)
	{
		if (i < HEIGHT * (WIDTH / 2))
			mlx_put_pixel(cub->win, i, 0, get_rgba(0, 0, 255, 100));
		else if (i > HEIGHT * (WIDTH / 2))
			mlx_put_pixel(cub->win, i, 0, get_rgba(0, 100, 100, 255));
		i++;
	}
	print_mini_map(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cub->mlx);
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	if (argc == 2)
	{
		cub = init_cub();
		parse_map(cub, argv[1]);
		init_game(cub);
		print_map_lines(cub->map->mini_m);
		mlx_loop_hook(cub->mlx, &main_hook, cub);
		cub->player = mlx_new_image(cub->mlx, 6, 6);
		memset(cub->player->pixels, get_rgba(255, 0, 0, 255), 6 * 6
				* sizeof(int));
		mlx_image_to_window(cub->mlx, cub->player, 917, 1029);
		mlx_loop_hook(cub->mlx, &moves_hook, cub);
		mlx_loop(cub->mlx);
		mlx_terminate(cub->mlx);
		return (EXIT_SUCCESS);
	}
	else
		ft_msg_err("No map given.");
}
