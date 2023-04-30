/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:37:43 by loadjou           #+#    #+#             */
/*   Updated: 2023/04/30 11:03:00 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

float	normalize_angle(float angle)
{
	angle = remainder(angle, 2 * M_PI);
	if (angle < 0)
		angle = 2 * M_PI + angle;
	return (angle);
}

float	fix_angle(t_cub *cub, float slice, int key)
{
	cub->p_a = normalize_angle(cub->p_a);
	if (key == MLX_KEY_LEFT)
		cub->p_a += slice;
	if (key == MLX_KEY_RIGHT)
		cub->p_a -= slice;
	return (cub->p_a);
}

void	rotate(t_cub *cub)
{
	if (mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT))
		cub->p_a = fix_angle(cub, 0.08, MLX_KEY_RIGHT);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT))
		cub->p_a = fix_angle(cub, 0.08, MLX_KEY_LEFT);
}

char	*ft_log(int dir)
{
	char *str;

	str = malloc(sizeof(char) * 3);
	str = "**";
	if (dir == SO)
		str = "SO";
	else if (dir == NO)
		str = "NO";
	else if (dir == WE)
		str = "WE";
	else if (dir == EA)
		str = "EA";
	return str;
}
