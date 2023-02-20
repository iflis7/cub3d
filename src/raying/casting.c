/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:22:56 by loadjou           #+#    #+#             */
/*   Updated: 2023/02/10 10:27:48 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// float	distance(ax, ay, bx, by, ang)
// {
// 	return (cos(degToRad(ang)) * (bx - ax) - sin(degToRad(ang)) * (by - ay));
// }

void	cast_ray(t_cub *cub)
{
	int	i;

	i = 0;
	while (i <= 100)
	{
		mlx_put_pixel(cub->win, cub->p_x - i, cub->p_y, get_rgba(255, 0, 0,
					255));
		i++;
	}
}

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