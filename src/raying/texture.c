/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:39:38 by loadjou           #+#    #+#             */
/*   Updated: 2023/04/30 12:13:11 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

uint32_t	get_px(mlx_texture_t *buff, int x, int y)
{
	return ((((uint32_t *)buff->pixels)[x + buff->width * y]));
}

bool	is_multiple_of(float pos, int x)
{
	return ((int)pos % x == 0);
}

mlx_texture_t	*set_texture(t_cub *cub, int dir)
{
	if (dir == EA)
		return (&cub->map->east->texture);
	else if (dir == NO)
		return (&cub->map->north->texture);
	else if (dir == WE)
		return (&cub->map->west->texture);
	else if (dir == SO)
		return (&cub->map->south->texture);
	return (NULL);
}

mlx_texture_t	*get_texture(t_cub *cub, float dest[2])
{
	int	dir;
	int	yes_x;
	int	yes_y;

	yes_x = is_multiple_of(dest[X], cub->map->sq_size);
	yes_y = is_multiple_of(dest[Y], cub->map->sq_size);
	dir = -1;
	if (cub->coord[X] > dest[X] && yes_x)
		dir = WE;
	else if (cub->coord[Y] < dest[Y] && yes_y)
		dir = SO;
	else if (cub->coord[X] < dest[X] && yes_x)
		dir = EA;
	else if (cub->coord[Y] > dest[Y] && yes_y)
		dir = NO;
	// printf("dir = %s\n", ft_log(dir));
	return (set_texture(cub, dir));
}






/*
int	texture_selection(t_ray *ray)
{
	int			x;
	int			y;
	static int	texture = 0;

	x = (int) floor(ray->x - ray->cos);
	y = (int) floor(ray->y - ray->sin);
	if (x < floor(ray->x) && y == floor(ray->y))
		texture = 3;
	else if (x > floor(ray->x) && y == floor(ray->y))
		texture = 2;
	else if (y < floor(ray->y) && x == floor(ray->x))
		texture = 1;
	else if (y > floor(ray->y) && x == floor(ray->x))
		texture = 0;
	return (texture);
}

*/