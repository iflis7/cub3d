/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:22:56 by loadjou           #+#    #+#             */
/*   Updated: 2023/02/20 10:44:55 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	print_mini_map(t_cub *cub)
{
	t_mini_m	*mini_m;
	int			i;
	int			j;
	int			dep;

	dep = ((cub->mlx->width / 16 / 2) - (cub->map->max_line_len) / 2);
	mini_m = cub->map->mini_m;
	j = (cub->mlx->height / 16) - cub->map->nb_lines;
	while (mini_m)
	{
		i = 0;
		while (mini_m->line[i])
		{
			if (mini_m->line[i] == '1')
				print_square(cub->win, i + dep, j, 0);
			else if (mini_m->line[i] != '\n')
				print_square(cub->win, i + dep, j, get_rgba(0, 255, 0, 255));
			i++;
		}
		mini_m = mini_m->next;
		j++;
	}
}

// 	i = 0;
// 	while (i <= 100)
// 	{
// 		mlx_put_pixel(cub->win, cub->p_x - i, cub->p_y, get_rgba(255, 0, 0,
// 					255));
// 		i++;
// 	}
// }

/* void	buttons(unsigned char key, int x, int y)
{
	if (key == 'a')
	{
		pa -= 0.1;
		if (pa < 0)
		{
			pa += 2 * PI;
		}
		pdx = cos(pa) * 5;
		pdy = sin(pa) * 5;
	}
	if (key == 'd')
	{
		pa += 0.1;
		if (pa > 2 * PI)
		{
			pa -= 2 * PI;
		}
		pdx = cos(pa) * 5;
		pdy - sin(pa) * 5;
	}
	if (key == 'w')
	{
		px += pdx;
		py += pdy;
	}
	if (key == 's')
	{
		px-- pdx;
		py - pdy;
	}
	glutPostRedisplay();
} */