/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:22:56 by loadjou           #+#    #+#             */
/*   Updated: 2023/04/07 11:49:32 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	print_mini_map(t_cub *cub)
{
	t_mini_m	*mini_m;
	int			i;
	int			j;
	int			dep;

	dep = 0;
	mini_m = cub->map->mini_m;
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

void cast_ray(t_cub *cub, float angle)
{
	int i = 0;
	float px = cub->player->instances[0].x + cub->map->sq_size / 8;
	float py = cub->player->instances[0].y + cub->map->sq_size / 8;

	cub->ray_x =  cos(degToRad( angle)) ;
	cub->ray_y =  -sin(degToRad( angle));
	// printf("pa= %.2f\n", angle );
	while (1)
	{
		int	x = (int)(px + cub->ray_x * i);
		int	y = (int)(py + cub->ray_y * i);
		if (is_wall(cub, x, y))
			break ;
		mlx_put_pixel(cub->win, x, y, 0xffffffff);
		i++;
	}
}


void	cast_fov(t_cub *cub)
{
	float i = 0;
	float incr;


	float start;
	start = cub->p_a - cub->fov / 2;
	// printf("fov = %.2f pa= %.2f\n", cub->fov, cub->p_a);
	incr = cub->fov / WIDTH;
	while(i < WIDTH)
	{
		// printf("i = %.2f\n", i);
		cast_ray(cub, start + (degToRad((float) i + incr)));
		i++;
	} 
}
