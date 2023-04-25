/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:39:38 by loadjou           #+#    #+#             */
/*   Updated: 2023/04/25 19:15:26 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

uint32_t	get_px(mlx_texture_t *buff, int x, int y)
{
	return ((((uint32_t *)buff->pixels)[x + buff->width * y]));
}

int	get_text_dir(t_cub *cub, float angle)
{
	(void)cub;
	if (angle < deg_to_rad(90) && angle >= deg_to_rad(270))
		return (EA);
	if (angle < deg_to_rad(180) && angle >= deg_to_rad(0))
		return (NO);
	if (angle < deg_to_rad(270) && angle >= deg_to_rad(90))
		return (WE);
	if (angle < deg_to_rad(360) && angle >= deg_to_rad(180))
		return (SO);
	return (-1);
}

mlx_texture_t	*set_texture(t_cub *cub)
{
	if (get_text_dir(cub, cub->ray_a) == EA)
		return (&cub->map->east->texture);
	if (get_text_dir(cub, cub->ray_a) == NO)
		return (&cub->map->north->texture);
	if (get_text_dir(cub, cub->ray_a) == WE)
		return (&cub->map->west->texture);
	if (get_text_dir(cub, cub->ray_a) == SO)
		return (&cub->map->south->texture);
    return NULL;
}
