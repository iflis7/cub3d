/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:22:56 by loadjou           #+#    #+#             */
/*   Updated: 2023/04/14 14:20:18 by loadjou          ###   ########.fr       */
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
				// mlx_image_to_window(cub->mlx, cub->lhid, i + dep, j);
			else if (mini_m->line[i] != '\n')
				// mlx_image_to_window(cub->mlx, cub->tagnit, i + dep, j);
				print_square(cub, i + dep, j, get_rgba(155, 055, 55, 255));
			i++;
		}
		mini_m = mini_m->next;
		j++;
	}
}



// // Function to calculate the distance between two points
// float get_dist(point_t point1, point_t point2) {
//     int dx = point2.x - point1.x;
//     int dy = point2.y - point1.y;
//     float distance = sqrt(dx * dx + dy * dy);
//     return distance;
// }

float	distance(ax, ay, bx, by, ang)
{
	return (cos(degToRad(ang)) * (bx - ax) - sin(degToRad(ang)) * (by - ay));
}

void	draw_wall(t_cub *cub, float dest[2], int pos_x)
{
	int j;
	float dist = (5 / distance(cub->player->instances[0].x, cub->player->instances[0].y, dest[X], dest[Y], cub->p_a)) * HEIGHT;
	
	// dist = (5 / dist) * HEIGHT;
	j = HEIGHT / 2 - (dist / 2);
	// j = (HEIGHT / 2) - dist;
	// printf("dist = %.0f   j = %d   dest[X] = %.0f    dest[Y] = %.0f\n", dist, j, dest[X], dest[Y] );
	// printf("dist = %.0f   j = %d\n", dist, j);
	while(j <= (HEIGHT / 2) + dist / 2)
	{
	// 	// printf("i = %d, j = %d\n", i, j);
		mlx_put_pixel(cub->win, pos_x, j, 0x3b3101);
		j++;
	}
}

bool	cast_ray(t_cub *cub, float angle, int pos_x)
{
	int		i;
	float	px;
	float	py;
	int		x;
	int		y;
	float dest[2];

	i = 0;
	px = cub->player->instances[0].x + cub->map->sq_size / 8;
	py = cub->player->instances[0].y + cub->map->sq_size / 8;

	cub->ray_x = cos(degToRad(angle));
	cub->ray_y = -sin(degToRad(angle));
	// printf("pa");
	while (1)
	{
		x = (int)(px + cub->ray_x * i);
		y = (int)(py + cub->ray_y * i);
		if (is_wall(cub, x, y))
		{
			dest[X] = x /* * 2 */;
			dest[Y] = y /* +100 */ ;
			// float d = sqrtf(((x - cub->player->instances[0].x) * (x - cub->player->instances[0].x)) + (y - cub->player->instances[0].y) * (y - cub->player->instances[0].y));
			// draw_wall(cub, dest);
			// printf("distance: %.0f\n", distance(cub->player->instances[0].x, cub->player->instances[0].y, dest[X], dest[Y], cub->p_a));
			draw_wall(cub, dest, pos_x);
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
	// float dest[2];

	i = 0;
	start = cub->p_a - cub->fov / 2;
	incr = cub->fov / WIDTH;
	// printf("fov = %.2f pa= %.2f INCR= %.2f start = %.2f\n", rad_to_deg(cub->fov), rad_to_deg(cub->p_a), incr, rad_to_deg(start));
	while (i < WIDTH)
	{
		// dest[X] = i;
		// dest[Y] = start + (degToRad((float)i + incr));
		cast_ray(cub, start + (degToRad((float)i + incr)), i);
		// printf("dest[Y] = %.0f\n", dest[Y]);
		// draw_wall(cub, dest);
		// if(cast_ray(cub, start + (degToRad((float) i + incr))))
		// draw_wall(cub, 200, 600, 700);
		// incr += incr;
		i++;
	}
	// printf("end = %.2f\n", rad_to_deg(start + (degToRad((float)i + incr))));
}
