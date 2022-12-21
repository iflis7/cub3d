#include "../../include/cub3d.h"

mlx_image_t	*g_img;

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		g_img->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		g_img->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		g_img->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		g_img->instances[0].x += 5;
}

int	main(int argc, char **argv)
{
	(void)argc;
	// (void)argv;
	t_cub	*cub;

	if (argc < 2)
		ft_msg_err("No map given.");
	if (argc > 2)
		ft_msg_err("Too many arguments.");
	cub = malloc(sizeof(t_cub));
	// cub->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", true);
	// if (!cub->mlx)
	// 	exit(EXIT_FAILURE);
	parse_map(cub, argv[1]);
	// g_img = mlx_new_image(cub->mlx, 128, 128);
	// memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	// mlx_image_to_window(cub->mlx, g_img, 0, 0);
	// mlx_loop_hook(cub->mlx, &hook, cub->mlx);
	// mlx_loop(cub->mlx);
	// mlx_terminate(cub->mlx);
	return (EXIT_SUCCESS);
}
