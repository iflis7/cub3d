/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bylkus <bylkus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:22:56 by loadjou           #+#    #+#             */
/*   Updated: 2023/03/09 16:07:11 by bylkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	print_mini_map(t_cub *cub)
{
	t_mini_m	*mini_m;
	int			i;
	int			j;
	int			dep;

	// dep = ((cub->mlx->width / 16 / 2) - (cub->map->max_line_len) / 2);
	dep = 0;
	mini_m = cub->map->mini_m;
	// j = (cub->mlx->height / 16) - cub->map->nb_lines;
	j= 0;
	while (mini_m)
	{
		i = 0;
		while (mini_m->line[i])
		{
			if (mini_m->line[i] == '1')
				print_square(cub, i + dep, j, 0);
			else if (mini_m->line[i] != '\n')
				print_square(cub, i + dep, j, get_rgba(155, 055, 55, 255));
			i++;
		}
		mini_m = mini_m->next;
		j++;
        
	}
}


void cast_ray(t_cub *cub)
{
	float len;
	int i = 0;
	float px = cub->player->instances[0].x + cub->map->sq_size / 8;
	float py = cub->player->instances[0].y + cub->map->sq_size / 8;
	cub->ray_x =  px;
	cub->ray_y =  py ;
	len = sqrtf(cub->ray_x * cub->ray_x + cub->ray_y * cub->ray_y);
	cub->ray_x = px * cos(cub->p_a * M_PI / 180);
	cub->ray_y = py * -sin(cub->p_a * M_PI / 180);
	cub->ray_y /= len;
	cub->ray_x /= len;
	
	while (i < WIDTH)
	{
		float t = (float)i / WIDTH;
		int x = px + t * cub->ray_x * len ;
		int y = py + t * cub->ray_y * len ;
		if(x > cub->map->max_line_len * (int)cub->map->sq_size || x <= 0 || y > cub->map->nb_lines * (int)cub->map->sq_size || y <= 0 || is_wall(cub, x, y))
			break;
		mlx_put_pixel(cub->win, x, y, get_rgba(255, 255, 255, 1));
		i++;
	}
}
