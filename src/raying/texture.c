/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:39:38 by loadjou           #+#    #+#             */
/*   Updated: 2023/04/25 17:53:38 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

uint32_t    get_px(mlx_texture_t	*buff, int x, int y)
{
    return((((uint32_t*)buff->pixels)[x + buff->width * y]));
}
