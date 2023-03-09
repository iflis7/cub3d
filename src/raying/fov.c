/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bylkus <bylkus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:51:31 by loadjou           #+#    #+#             */
/*   Updated: 2023/03/09 09:36:45 by bylkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool    is_wall(t_cub *cub, int32_t destx, int32_t desty)
{
    if(cub->map->map[desty / 64][destx / 64] == '1')
    {
        /* if(destx / 64 == 0)
        {
            cub->dest[X] = 64;
            cub->dest[Y] = desty * 64;
        }
        if(!cub->map->map[destx / 64 + 1])
        {
            cub->dest[X] = (destx * 64) - 64;
            cub->dest[Y] = desty * 64;   
        }
        if(desty / 64 == 0)
        {
            cub->dest[Y] = 64;
            cub->dest[X] = destx * 64;
        }
        if(!cub->map->map[desty / 64 + 1])
        {
            cub->dest[X] = (desty * 64) - 64;
            cub->dest[Y] = desty * 64;   
        } */
        return 1;
    }
    return 0;
}