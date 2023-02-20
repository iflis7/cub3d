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

void adjust(int32_t *val, char flag)
{
	if (flag == 'a')
	{
		*val += 5;
	}
	if (flag == 's')
	{
		*val -= 5;
	}
}


void	move_p_hook(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_UP))
	{
		adjust(&cub->player->instances[0].y, 's');
	}
	if (mlx_is_key_down(cub->mlx, MLX_KEY_DOWN))
	{
		adjust(&cub->player->instances[0].y, 'a');
	}
	if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT))
	{
		adjust(&cub->player->instances[0].x, 's');
	}
	if (mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT))
	{
		adjust(&cub->player->instances[0].x, 'a');
	}
	if (mlx_is_key_down(cub->mlx, MLX_KEY_A))
	{
		cub->p_a = fix_angle(cub, 5, MLX_KEY_A);
		cub->pdx = cos(degToRad(cub->p_a));
		cub->pdy = -sin(degToRad(cub->p_a));
	}
	if (mlx_is_key_down(cub->mlx, MLX_KEY_D))
	{
		cub->p_a = fix_angle(cub, 5, MLX_KEY_D);
		cub->pdx = cos(degToRad(cub->p_a));
		cub->pdy = -sin(degToRad(cub->p_a));
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
	int			dep;

	dep = ((cub->mlx->width / 16 / 2) - (cub->map->max_line_len) / 2);
	mini_m = cub->map->mini_m;
	j = (cub->mlx->height / 16) - cub->map->nb_lines;
	while (mini_m)
	{
		i = 0;
		while (mini_m->line[i])
		{
			if (strchr("NEWS", mini_m->line[i]))
			{
				cub->p_x = (dep + i) * 16 + 4;
				cub->p_y = j * 16 + 4;
				// printf("Coor:: X::%zu -- Coord:: Y::%zu --> I::%i\n", cub->p_x,
						// cub->p_y, i);
			}
			i++;
		}
		mini_m = mini_m->next;
		j++;
	}
	// printf("Coor:: X::%zu -- Coord:: Y::%zu\n", cub->p_x, cub->p_y);
}
