#include "../../include/cub3d.h"

int	fix_angle(int a)
{
	if (a < 0)
		a += 360;
	if (a > 359)
		a -= 360;
	return (a);
}

void	move_p_hook(void *param)
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
	if (mlx_is_key_down(cub->mlx, MLX_KEY_A))
	{
		cub->p_a += 5;
		cub->p_a = fix_angle(cub->p_a);
	}
	if (mlx_is_key_down(cub->mlx, MLX_KEY_D))
	{
		cub->p_a -= 5;
		cub->p_a = fix_angle(cub->p_a);
	}
}

bool	get_p_angle(t_cub *cub)
{
	t_mini_m	*temp;

	temp = cub->map->mini_m;
	while (temp->next)
	{
		if (strchr(temp->line, 'E'))
			cub->p_a = 0;
		else if (strchr(temp->line, 'W'))
			cub->p_a = 180;
		else if (strchr(temp->line, 'N'))
			cub->p_a = 90;
		else if (strchr(temp->line, 'S'))
			cub->p_a = 270;
		temp = temp->next;
	}
	return (true);
}
