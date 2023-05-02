/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:39:38 by loadjou           #+#    #+#             */
/*   Updated: 2023/05/02 07:53:26 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

uint32_t	get_px(mlx_texture_t *buff, int x, int y)
{
	return ((((uint32_t *)buff->pixels)[x + buff->width * y]));
}

bool	is_multiple_of(float pos, int x)
{
	int	coord;

	coord = (int)floorf(pos);
	if ((coord % x) == 0 || (coord - 1) % x == 0 || (coord + 1) % x == 0)
		return (true);
	return (false);
}

mlx_texture_t	*get_texture(t_cub *cub, float dest[2])
{
	int	yes_x;
	int	yes_y;

	yes_x = is_multiple_of(dest[X], cub->map->sq_size);
	yes_y = is_multiple_of(dest[Y], cub->map->sq_size);
	if ((yes_x && !yes_y) && cub->coord[X] > dest[X])
		return (cub->map->west);
	else if ((yes_y && !yes_x) && (cub->coord[Y] < dest[Y]))
		return (cub->map->south);
	else if (cub->coord[X] < dest[X] && (yes_x && !yes_y))
		return (cub->map->east);
	else if (cub->coord[Y] > dest[Y] && (yes_y && !yes_x))
		return (cub->map->north);
	return (NULL);
}
