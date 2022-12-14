#include "../../include/cub3d.h"

mlx_image_t *g_img;

void printErr(char *str)
{
	write(1, str, strlen(str));
	exit(EXIT_FAILURE);
}

void hook(void *param)
{
	mlx_t *mlx;

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

bool parsing_map(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);

	if (fd <= 0)
		printErr("Map invalid.\n");

	return (true);
}

int main(int argc, char **argv)
{
	// t_cub3d *cub3d;

	if (argc != 2)
		printErr("Map is missing.\n");

	parsing_map(argv[1]);

	// cub3d = (t_cub3d *)malloc(sizeof(t_cub3d));
	// cub3d->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", true);
	// if (!cub3d->mlx)
	// 	exit(EXIT_FAILURE);

	// g_img = mlx_new_image(cub3d->mlx, 128, 128);
	// memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	// mlx_image_to_window(cub3d->mlx, g_img, 0, 0);
	// mlx_loop_hook(cub3d->mlx, &hook, cub3d->mlx);
	// mlx_loop(cub3d->mlx);
	// mlx_terminate(cub3d->mlx);
	return (EXIT_SUCCESS);
}
