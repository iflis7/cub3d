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

int main()
{
    t_cub3d *cub3d;

    cub3d = (t_cub3d *)malloc(sizeof(t_cub3d));
    cub3d->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", true);
    if (!cub3d->mlx)
		exit(EXIT_FAILURE);
    g_img = mlx_new_image(cub3d->mlx, 128, 128);
    memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	mlx_image_to_window(cub3d->mlx, g_img, 0, 0);
	mlx_loop_hook(cub3d->mlx, &hook, cub3d->mlx);
	mlx_loop(cub3d->mlx);
	mlx_terminate(cub3d->mlx);
	return (EXIT_SUCCESS);
}
