/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bylkus <bylkus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:22:56 by loadjou           #+#    #+#             */
/*   Updated: 2023/04/26 00:07:22 by bylkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

unsigned int get_color(t_cub *cub, float angle);

void	draw_wall(t_cub *cub, float ray_a, float dest[2], int pos_x)
{
	int			j;
	float		dist;
	uint32_t	color;
	// mlx_texture_t	*dir;

	dist = sqrtf((dest[X] - cub->coord[X]) * (dest[X] - cub->coord[X])
			+ (dest[Y] - cub->coord[Y]) * (dest[Y] - cub->coord[Y]));
	dist = dist * cosf(ray_a - cub->p_a);
	dist = (cub->map->sq_size * HEIGHT / dist);
	if (dist >= HEIGHT)
		dist = HEIGHT;
	j = HEIGHT / 2 - (dist / 2);
	while (j < (HEIGHT / 2) + dist / 2)
	{
		// dir = set_texture(cub);
		// if(dir)
		// 	color = get_px(dir, pos_x % dir->width, j % dir->height);
		color = get_color(cub, ray_a);
		// color = 0x00FF0000;
		mlx_put_pixel(cub->win, pos_x, j, color);
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
		if (is_wall(cub, x, y) && is_wall(cub, x + 1, y + 1) && is_wall(cub, x
				- 1, y - 1))
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
