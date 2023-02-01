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


// void move_hook(void *param)
// {
// 	t_cub *const cub = param;
// 	if (mlx_is_key_down(cub->mlx, MLX_KEY_W))
// 	{
// 		if (cub->map->mini_m->line[(int)(cub->player->pos_x + cub->player->dir_x * cub->player->move_speed)] != '1')
// 			cub->player->pos_x += cub->player->dir_x * cub->player->move_speed;
// 		if (cub->map->mini_m->line[(int)(cub->player->pos_y + cub->player->dir_y * cub->player->move_speed)] != '1')
// 			cub->player->pos_y += cub->player->dir_y * cub->player->move_speed;
// 	}
// 	if (mlx_is_key_down(cub->mlx, MLX_KEY_S))
// 	{
// 		if (cub->map->mini_m->line[(int)(cub->player->pos_x - cub->player->dir_x * cub->player->move_speed)] != '1')
// 			cub->player->pos_x -= cub->player->dir_x * cub->player->move_speed;
// 		if (cub->map->mini_m->line[(int)(cub->player->pos_y - cub->player->dir_y * cub->player->move_speed)] != '1')
// 			cub->player->pos_y -= cub->player->dir_y * cub->player->move_speed;
// 	}
// 	if (mlx_is_key_down(cub->mlx, MLX_KEY_A))
// 	{
// 		if (cub->map->mini_m->line[(int)(cub->player->pos_x - cub->player->plane_x * cub->player->move_speed)] != '1')
// 			cub->player->pos_x -= cub->player->plane_x * cub->player->move_speed;
// 		if (cub->map->mini_m->line[(int)(cub->player->pos_y - cub->player->plane_y * cub->player->move_speed)] != '1')
// 			cub->player->pos_y -= cub->player->plane_y * cub->player->move_speed;
// 	}
// 	if (mlx_is_key_down(cub->mlx, MLX_KEY_D))
// 	{
// 		if (cub->map->mini_m->line[(int)(cub->player->pos_x + cub->player->plane
// }




void	main_hook(void *param)
{
	unsigned int	i;

	t_cub *const cub = param;
	i = 0;
	while (i < WIDTH * HEIGHT)
	{
		// printf("I:: %d\n", i);
		if (i < HEIGHT * (WIDTH / 2))
			mlx_put_pixel(cub->win, i, 0, get_rgba(0,0,255,100));
			// mlx_put_pixel(cub->win, i, 0, cub->map->ceil);
		else if (i > HEIGHT * (WIDTH / 2))
			mlx_put_pixel(cub->win, i, 0, get_rgba(0,100,100,255));
			// mlx_put_pixel(cub->win, i, 0, cub->map->floor);
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
		// mlx_put_pixel(cub->win, i, 0, get_rgba(255,0,0,255));

		mlx_loop_hook(cub->mlx, &main_hook, cub);
		// mlx_loop_hook(cub->mlx, &move_hook, cub);
		// mlx_loop_hook(cub->mlx, &mini_map_hook, cub);

		mlx_loop(cub->mlx);
		mlx_terminate(cub->mlx);
		return (EXIT_SUCCESS);
	}
	else
		ft_msg_err("No map given.");
}
