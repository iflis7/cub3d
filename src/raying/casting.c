/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bylkus <bylkus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:22:56 by loadjou           #+#    #+#             */
/*   Updated: 2023/03/10 12:36:48 by bylkus           ###   ########.fr       */
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
    int i, j;
    float px = cub->player->instances[0].x + cub->map->sq_size / 8;
    float py = cub->player->instances[0].y + cub->map->sq_size / 8;
    float angle_range = 60.0; // 60 degree field of view
    float angle_increment = angle_range / WIDTH; // divide the field of view equally over the screen width
    float start_angle = cub->p_a - (angle_range / 2.0); // start angle is the player angle minus half the field of view
    float angle;
    
    for (i = 0; i < WIDTH; i++) {
        angle = start_angle + i * angle_increment;
        cub->ray_x = px * cos(angle * M_PI / 180.0) - py * sin(angle * M_PI / 180.0);
        cub->ray_y = px * sin(angle * M_PI / 180.0) + py * cos(angle * M_PI / 180.0);
        len = sqrtf(cub->ray_x * cub->ray_x + cub->ray_y * cub->ray_y);
        cub->ray_x /= len;
        cub->ray_y /= len;

        j = 0;
        while (j < WIDTH) {
            float t = (float)j / WIDTH;
            int x = px + t * cub->ray_x * len ;
            int y = py + t * cub->ray_y * len ;
            if(x > cub->map->max_line_len * (int)cub->map->sq_size || x <= 0 || y > cub->map->nb_lines * (int)cub->map->sq_size || y <= 0 || is_wall(cub, x, y))
                break;
            mlx_put_pixel(cub->win, x, y, 255);
            j++;
        }
    }
}

/* void cast_ray(t_cub *cub)
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
 */