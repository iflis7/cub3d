#include "../../include/cub3d.h"

int	fix_angle(t_cub *cub, int slice, int key)
{
	if (cub->p_a < 0)
		cub->p_a += 360;
	else if (cub->p_a > 359)
		cub->p_a -= 360;
	else
	// (cub->p_a > 0 && cub->p_a < 359)
	{
		if (key == 65)
			cub->p_a += slice;
		if (key == 68)
			cub->p_a -= slice;
	}
	return (cub->p_a);
}

float	degToRad(int a)
{
	return (a * M_PI / 180.0);
}

void	advance(t_cub *cub)
{
	cub->p_x += cub->pdx * 5;
	cub->p_y += cub->pdy * 5;
	// printf("cub->px %.2ld ------ cub->py %.2ld\n: ", cub->p_x, cub->p_y);
	// printf("cub->pdx %.2f ------ cub->pdy %.2f\n: ", cub->pdx, cub->pdy);
}

void	rotate(t_cub *cub, int slice, int key)
{
	cub->p_a = fix_angle(cub, slice, key);
	cub->pdx = cos(degToRad(cub->p_a));
	cub->pdy = sin(degToRad(cub->p_a));
}

bool	collision(t_cub *cub)
{
	t_mini_m	*mini;

	mini = cub->map->mini_m;
	cub->p_x = cub->player->instances[0].x;
	cub->p_y = cub->player->instances[0].y;
	printf("---------------------%ld\n", cub->p_y);
	while (mini)
	{
		if (cub->map->mini_m->line[cub->p_x / cub->map->sq_size] == '1')
			return (false);
	}
	return (true);
}

void	adjust(t_cub *cub, int32_t *val, char flag)
{
	if (flag == 'a')
	{
		*val += cub->map->sq_size / 4;
		// collision(cub);
	}
	if (flag == 's')
	{
		*val -= cub->map->sq_size / 4;
	}
}

void	move_p_hook(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	// draw_ray(cub, 5);
		// mlx_put_string(cub->mlx, ".", cub->player->instances[0].x, cub->player->instances[0].y);
	if(!is_wall(cub, cub->player->instances[0].x, cub->player->instances[0].y))
	{

		if (mlx_is_key_down(cub->mlx, MLX_KEY_UP))
		{
			// cub->player->instances[0].y -= cub->map->sq_size / 4;
			adjust(cub, &cub->player->instances[0].y, 's');
		}
		if (mlx_is_key_down(cub->mlx, MLX_KEY_DOWN))
		{
			adjust(cub, &cub->player->instances[0].y, 'a');
		}
		if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT))
		{
			adjust(cub, &cub->player->instances[0].x, 's');
		}
		if (mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT))
		{
			adjust(cub, &cub->player->instances[0].x, 'a');
		}
		if (mlx_is_key_down(cub->mlx, MLX_KEY_A))
		{
			cub->p_a = fix_angle(cub, 5, MLX_KEY_A);
		}
		if (mlx_is_key_down(cub->mlx, MLX_KEY_D))
		{
			cub->p_a = fix_angle(cub, 5, MLX_KEY_D);
			// cub->pdx = cos(degToRad(cub->p_a));
			// cub->pdy = -sin(degToRad(cub->p_a));
		}
	
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

void	get_pcoordinates(t_cub *cub)
{
	t_mini_m	*mini_m;
	int			i;
	int			j;

	mini_m = cub->map->mini_m;
	j = 0;
	while (mini_m)
	{
		i = 0;
		while (mini_m->line[i])
		{
			if (strchr("NEWS", mini_m->line[i]))
			{
				cub->p_x = (i * cub->map->sq_size); // + (cub->map->sq_size
				cub->p_y = (j * cub->map->sq_size); // + (cub->map->sq_size
			}
			i++;
		}
		mini_m = mini_m->next;
		j++;
	}
	// printf("Coor:: X::%zu -- Coord:: Y::%zu\n", cub->p_x, cub->p_y);
}

// bool check_colision()
