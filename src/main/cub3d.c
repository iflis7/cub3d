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

void	print_small_map(t_cub *cub);
void	print_sqaure(t_cub *cub, uint32_t x, uint32_t y, uint32_t color);

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
	print_small_map(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cub->mlx);
}

void	print_sqaure(t_cub *cub, uint32_t x, uint32_t y, uint32_t color)
{
	size_t i = 0;
	size_t j = y * 64;
	while(j <= (y * 64) + 64)
	{
		i = x * 64;
		mlx_put_pixel(cub->win, i, j, color);
		while(i <= (x * 64) + 64)
		{
			mlx_put_pixel(cub->win, i, j, color);
			i++;
		}
		j++;
	}
	mlx_put_string(cub->mlx, "MINI-MAP", 120, 20);
}

void	print_small_map(t_cub *cub)
{
	t_line *line = cub->map->line;
	int i;
	int j = 0;

	while(line->next)
	{
		i = 0;
		// printf("s: %s", line->content);
		while(line->content && line->content[i])
		{
			// printf("%c ", line->content[i]);
			if(line->content[i] == '1')
				print_sqaure(cub, i, j, 0);
			// else if(line->content[i] == '0')
			// 	print_sqaure(cub, i, j, 0);
			else if(line->content[i] == 'S')
				print_sqaure(cub, i, j, 168746);
			else
				print_sqaure(cub, i, j, -167761);
			i++;
		}
		line = line->next;
		j++;

	}
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	if (argc < 2)
		ft_msg_err("No map given.");
	if (argc > 2)
		ft_msg_err("Too many arguments.");
	cub = init_cub();
	// (void)argv;
	// (void)cub;
	parse_map(cub, argv[1]);
	init_game(cub);
	print_small_map(cub);
	// print_map_lines(cub->map->line);
	// printf("map->north %s\n", cub->map->north);
	// printf("map->south %s\n", cub->map->south);
	// printf("map->east %s\n", cub->map->east);
	// printf("map->west %s\n", cub->map->west);
	printf("map->floor %d\n", cub->map->floor);
	printf("map->ceil %d\n", cub->map->ceil);
	mlx_loop_hook(cub->mlx, &main_hook, cub);
	mlx_loop(cub->mlx);
	mlx_terminate(cub->mlx);
	return (EXIT_SUCCESS);
}
