/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:51:31 by loadjou           #+#    #+#             */
/*   Updated: 2023/04/25 15:58:34 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// bool	is_wall(t_cub *cub, int32_t destx, int32_t desty)
// {
// 	return (cub->map->map[desty / cub->map->sq_size][destx
// 		/ cub->map->sq_size] == '1');
// }

bool	is_wall(t_cub *cub, float destx, float desty)
{
	return (cub->map->map[(int)(desty / cub->map->sq_size)][(int)(destx / cub->map->sq_size)] == '1');
}
