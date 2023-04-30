/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:22:56 by loadjou           #+#    #+#             */
/*   Updated: 2023/04/29 23:00:58 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_wall(t_cub *cub, float ray_a, float dest[2], int pos_x)
{
	int			j;
	float		dist;
	uint32_t	color;

	dist = sqrtf((dest[X] - cub->coord[X]) * (dest[X] - cub->coord[X])
			+ (dest[Y] - cub->coord[Y]) * (dest[Y] - cub->coord[Y]));
	dist = dist * cosf(ray_a - cub->p_a);
	dist = (cub->map->sq_size * HEIGHT / dist);
	if (dist >= HEIGHT)
		dist = HEIGHT;
	j = HEIGHT / 2 - (dist / 2);
	while (j < (HEIGHT / 2) + dist / 2)
	{
		if (cub->texture)
			color = get_px(cub->texture, pos_x % cub->texture->width, j
					% cub->texture->height);
		else
			color = 0x00FF0000;
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
		if (is_wall(cub, x, y))
		{
			dest[X] = x;
			dest[Y] = y;
			// printf("x = %f, y = %f\n", floorf(x), floorf(y));
			cub->texture = get_texture(cub, dest);
			// cub->texture = &cub->map->north->texture;
			draw_wall(cub, angle, dest, pos_x);
			return (false);
		}
		i++;
	}
	return (true);
}
