#include "../../include/cub3d.h"

void	move_hook(void *param)
{
	t_cub	*cub;

	cub = param;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_UP))
		cub->win->instances->y -= 1;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_DOWN))
		cub->win->instances->y += 1;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT))
		cub->win->instances->x -= 5;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT))
		cub->win->instances->x += 5;
}
