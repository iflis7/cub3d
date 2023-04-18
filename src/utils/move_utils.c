#include "../../include/cub3d.h"


float    normalize_angle(float angle)
{
    angle = remainder(angle, 2 * M_PI);
    if (angle < 0)
        angle = 2 * M_PI + angle;
    return (angle);
}

float	fix_angle(t_cub *cub, float slice, int key)
{
	cub->p_a = normalize_angle(cub->p_a);
	if (key == MLX_KEY_LEFT)
		cub->p_a += slice;
	if (key == MLX_KEY_RIGHT)
		cub->p_a -= slice;

	return (cub->p_a);
}

float	degToRad(float a)
{
	return (a * M_PI / 180.0);
}

float	rad_to_deg(float a)
{
	  return a * (180.0 / M_PI);
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

 static void	adjust(t_cub *cub, float dx, float dy, unsigned char flag)
{
	// printf("dx = %.2f dy = %.2f\n", dx, dy);
	if (flag == 'a')
	{
		// cub->player->instances[0].x += (int)(dx * 2);
		// cub->player->instances[0].y += (int)(dy * 2);
		cub->coord[X] += dx;
		cub->coord[Y] += dy;
	}
	if (flag == 's')
	{
		// cub->player->instances[0].x -= (int)(dx * 2);
		// cub->player->instances[0].y -= (int)(dy * 2);
		cub->coord[X] -= dx;
		cub->coord[Y] -= dy;
	}
	// printf("%d %d\n", cub->player->instances[0].x, cub->player->instances[0].y);
}
 

void	move_p_hook(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	float dx, dy;
	
	// if(!is_wall(cub, cub->player->instances[0].x, cub->player->instances[0].y))
	// {
		dy = 0;
		dy = 0;
		if (mlx_is_key_down(cub->mlx, MLX_KEY_UP) || mlx_is_key_down(cub->mlx, MLX_KEY_W))
		{
			dx = cosf(cub->p_a );
			dy = -sinf(cub->p_a ); 
			// printf("UP : %f  \n ", cub->p_a);
			// if(!is_wall(cub, cub->player->instances[0].x  + dx * cub->map->sq_size / 8, cub->player->instances[0].y  + dy * cub->map->sq_size / 8))
				adjust(cub, dx, dy, 'a');
		}
		if (mlx_is_key_down(cub->mlx, MLX_KEY_DOWN) || mlx_is_key_down(cub->mlx, MLX_KEY_S))
		{
			dx = cosf(cub->p_a);
			dy = -sinf(cub->p_a);
			// printf("DOWN : %f \n  ", cub->p_a);
			// if(!is_wall(cub, cub->player->instances[0].x  - dx * cub->map->sq_size / 8, cub->player->instances[0].y  - dy * cub->map->sq_size / 8))
				adjust(cub, dx, dy, 's');
		}
		if (mlx_is_key_down(cub->mlx, MLX_KEY_A))
		{
			dx = cosf((cub->p_a + degToRad(90)));
			dy = -sinf((cub->p_a + degToRad(90)));
			// if(!is_wall(cub, cub->player->instances[0].x  + dx * cub->map->sq_size / 8, cub->player->instances[0].y  + dy * cub->map->sq_size / 8))
				adjust(cub, dx, dy, 'a');
			
		}
		if (mlx_is_key_down(cub->mlx, MLX_KEY_D))
		{
			dx = -cosf((cub->p_a - degToRad(90)));
			dy = sinf((cub->p_a - degToRad(90)));

			// if(!is_wall(cub, cub->player->instances[0].x  + dx * cub->map->sq_size / 8, cub->player->instances[0].y  + dy * cub->map->sq_size / 8))
				adjust(cub, dx, dy, 's');
			
		}
		// if (mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT))
		// {
		// 	dx = cosf(cub->p_a);
		// 	dy = -sinf(cub->p_a - degToRad(90));
		// 	printf("dx = %.2f dy= %.2f\n", dx, dy);
		// 	if(!is_wall(cub, cub->player->instances[0].x  - dx * cub->map->sq_size / 8, cub->player->instances[0].y  + dy * cub->map->sq_size / 8))
		// 		adjust(cub, dx, dy, 's');
		// }
		if (mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT))
			cub->p_a = fix_angle(cub, 0.05, MLX_KEY_RIGHT);
		if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT))
			cub->p_a = fix_angle(cub, 0.05, MLX_KEY_LEFT);
	
	// }
		print_mini_map(cub);
		cast_fov(cub);
		// printf("p_a = %.0f\n", cub->p_a);
		// printf("after: %d %d\n", cub->player->instances[0].x, cub->player->instances[0].y);
}

bool	get_p_angle(t_cub *cub)
{
	t_mini_m	*temp;

	temp = cub->map->mini_m;
	while (temp->next)
	{
		if (strchr(temp->line, 'E'))
			cub->p_a = degToRad(0);
		else if (strchr(temp->line, 'W'))
			cub->p_a = degToRad(180);
		else if (strchr(temp->line, 'N'))
			cub->p_a = degToRad(90);
		else if (strchr(temp->line, 'S'))
			cub->p_a = degToRad(270);
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
				// cub->p_x = (i * cub->map->sq_size); // + (cub->map->sq_size
				// cub->p_y = (j * cub->map->sq_size); // + (cub->map->sq_size
				cub->coord[X] = i * cub->map->sq_size;
				cub->coord[Y] = j * cub->map->sq_size;
			}
			i++;
		}
		mini_m = mini_m->next;
		j++;
	}
	// printf("Coor:: X::%zu -- Coord:: Y::%zu\n", cub->p_x, cub->p_y);
}

// bool check_colision()
