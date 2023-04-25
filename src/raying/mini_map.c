/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:25:28 by loadjou           #+#    #+#             */
/*   Updated: 2023/04/25 16:04:44 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	print_square(t_cub *cub, uint32_t x, uint32_t y, uint32_t color)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = y * cub->map->sq_size + 1;
	while (j <= (y * cub->map->sq_size) + cub->map->sq_size - 1)
	{
		i = x * cub->map->sq_size + 1;
		mlx_put_pixel(cub->win, i, j, color);
		while (i <= (x * cub->map->sq_size) + cub->map->sq_size - 1)
		{
			mlx_put_pixel(cub->win, i, j, color);
			i++;
		}
		j++;
	}
}

void	print_mini_map(t_cub *cub)
{
	t_mini_m	*mini_m;
	int			i;
	int			j;
	int			dep;

	dep = 0;
	mini_m = cub->map->mini_m;
	j = 0;
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

void	cast_fov(t_cub *cub)
{
	float	i;
	float	incr;
	float	start;

	i = 0;
	incr = 0;
	start = cub->p_a + cub->fov / 2;
	incr = cub->fov / WIDTH;
	while (i < WIDTH)
	{
		cast_ray(cub, start, i);
		start -= incr;
		start = normalize_angle(start);
		i++;
	}
}
