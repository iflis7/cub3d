/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:22:56 by loadjou           #+#    #+#             */
/*   Updated: 2023/04/09 15:58:22 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	print_mini_map(t_cub *cub)
{
	t_mini_m	*mini_m;
	int			i;
	int			j;
	int			dep;

	dep = 0;
	mini_m = cub->map->mini_m;
	j = 0;
	while (mini_m)
	{
		i = 0;
		while (mini_m->line[i])
		{
			if (mini_m->line[i] == '1')
				print_square(cub, i + dep, j, 0);
			else if (mini_m->line[i] != '\n')
				print_square(cub, i + dep, j, get_rgba(155, 055, 55, 255));
			i++;
		}
		mini_m = mini_m->next;
		j++;
	}
}

void	draw_wall(t_cub *cub, float b, int dist, float x)
{
	// float	d;

	// i = (int)b;
	// printf("azul\n");
	// d = sqrtf(((x - cub->player->instances[0].x) * (x - cub->player->instances[0].x)) + (dist - cub->player->instances[0].y) * (dist - cub->player->instances[0].y));
	// d = sqrt((x2 - x1)^2 + (y2 - y1)^2)
	// printf("%.0f\n", d );
	while (b <= dist)
	{
		// printf("i = %d		j = %d", i, j);
		mlx_put_pixel(cub->win, (int)x, (int)b, 0xffffff);
		b++;
	}
}

bool	cast_ray(t_cub *cub, float angle)
{
	int		i;
	float	px;
	float	py;
	int		x;
	int		y;

	i = 0;
	px = cub->player->instances[0].x + cub->map->sq_size / 8;
	py = cub->player->instances[0].y + cub->map->sq_size / 8;
	cub->ray_x = cos(degToRad(angle));
	cub->ray_y = -sin(degToRad(angle));
	// printf("pa= %.2f\n", angle );
	while (1)
	{
		x = (int)(px + cub->ray_x * i);
		y = (int)(py + cub->ray_y * i);
		if (is_wall(cub, x, y))
		{
			// float d = sqrtf(((x - cub->player->instances[0].x) * (x - cub->player->instances[0].x)) + (y - cub->player->instances[0].y) * (y - cub->player->instances[0].y));
			draw_wall(cub, y + 0200, (y - cub->player->instances[0].y) * 2, x + WIDTH/2);
			return (false);
		}
		mlx_put_pixel(cub->win, x, y, 0xffffffff);
		i++;
	}
	return (true);
}

void	cast_fov(t_cub *cub)
{
	float	i;
	float	incr;
	float	start;

	i = 0;
	start = cub->p_a - cub->fov / 2;
	// printf("fov = %.2f pa= %.2f\n", cub->fov, cub->p_a);
	incr = cub->fov / WIDTH;
	while (i < WIDTH)
	{
		// printf("i = %.2f\n", i);
		cast_ray(cub, start + (degToRad((float)i + incr)));
		// if(cast_ray(cub, start + (degToRad((float) i + incr))))
		// draw_wall(cub, 200, 600, 700);
		i++;
	}
}
