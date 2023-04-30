/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:39:38 by loadjou           #+#    #+#             */
/*   Updated: 2023/04/29 23:00:20 by loadjou          ###   ########.fr       */
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
	dir = 0;
	if (cub->coord[X] > dest[X] && yes_x)
		dir = WE;
	else if (cub->coord[X] < dest[X] && yes_x)
		dir = EA;
	else if (cub->coord[Y] > dest[Y] && yes_y)
		dir = NO;
	else if (cub->coord[Y] < dest[Y] && yes_y)
		dir = SO;
	return (set_texture(cub, dir));
}
