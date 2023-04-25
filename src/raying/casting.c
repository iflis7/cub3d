/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:22:56 by loadjou           #+#    #+#             */
/*   Updated: 2023/04/25 17:35:21 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_wall(t_cub *cub, float ray_a, float dest[2], int pos_x)
{
	int		j;
	float	dist;

	dist = sqrtf((dest[X] - cub->coord[X]) * (dest[X] - cub->coord[X])
			+ (dest[Y] - cub->coord[Y]) * (dest[Y] - cub->coord[Y]));
	dist = dist * cosf(ray_a - cub->p_a);
	dist = (cub->map->sq_size * HEIGHT / dist);
	if (dist >= HEIGHT)
		dist = HEIGHT;
	j = HEIGHT / 2 - (dist / 2);
	while (j < (HEIGHT / 2) + dist / 2)
	{
		if (j < HEIGHT)
			mlx_put_pixel(cub->win, pos_x, j, 0xF0F246);
		j++;
	}
}

bool	cast_ray(t_cub *cub, float angle, int pos_x)
{
	int		i;
	float	x;
	float	y;
	float	dest[2];

	i = 0;
	cub->ray_x = cos((angle));
	cub->ray_y = -sin((angle));
	while (1)
	{
		x = cub->coord[X] + cub->ray_x * i;
		y = cub->coord[Y] + cub->ray_y * i;
		if (is_wall(cub, x, y) && is_wall(cub, x + 1, y + 1) && is_wall(cub, x - 1, y - 1))
		{
			dest[X] = x;
			dest[Y] = y;
			draw_wall(cub, angle, dest, pos_x);
			return (false);
		}
		i++;
	}
	return (true);
}
