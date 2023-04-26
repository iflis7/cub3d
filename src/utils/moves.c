/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bylkus <bylkus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:24:10 by loadjou           #+#    #+#             */
/*   Updated: 2023/04/26 00:14:01 by bylkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	adjust(t_cub *cub, float dx, float dy, unsigned char flag)
{
	dx *= 4;
	dy *= 4;
	if (flag == 'a')
	{
		if (!is_wall(cub, cub->coord[X] + cub->pdx * 4, cub->coord[Y] + cub->pdy
				* 4))
		{
			cub->coord[X] += dx;
			cub->coord[Y] += dy;
		}
	}
	if (flag == 's')
	{
		if (!is_wall(cub, cub->coord[X] - cub->pdx * 4, cub->coord[Y] - cub->pdy
				* 4))
		{
			cub->coord[X] -= dx;
			cub->coord[Y] -= dy;
		}
	}
	cub->odo += 0.05;
}


void ft_log(int dir)
{
	if(dir == SO)
		printf("SO\n");
	else if(dir == NO)
		printf("NO\n");
	else if(dir == WE)
		printf("WE\n");
	else if(dir == EA)
		printf("EA\n");
}

static void	apply_moves(t_cub *cub)
{
	if (mlx_is_key_down(cub->mlx, 265) || mlx_is_key_down(cub->mlx, 87))
	{
		cub->pdx = cosf(cub->p_a);
		cub->pdy = -sinf(cub->p_a);
		adjust(cub, cub->pdx, cub->pdy, 'a');
	}
	if (mlx_is_key_down(cub->mlx, 264) || mlx_is_key_down(cub->mlx, 83))
	{
		cub->pdx = cosf(cub->p_a);
		cub->pdy = -sinf(cub->p_a);
		adjust(cub, cub->pdx, cub->pdy, 's');
	}
	if (mlx_is_key_down(cub->mlx, MLX_KEY_A))
	{
		cub->pdx = cosf((cub->p_a + deg_to_rad(90)));
		cub->pdy = -sinf((cub->p_a + deg_to_rad(90)));
		adjust(cub, cub->pdx, cub->pdy, 'a');
	}
	if (mlx_is_key_down(cub->mlx, MLX_KEY_D))
	{
		cub->pdx = -cosf((cub->p_a - deg_to_rad(90)));
		cub->pdy = sinf((cub->p_a - deg_to_rad(90)));
		adjust(cub, cub->pdx, cub->pdy, 's');
	}
	// ft_log(get_text_dir(cub, cub->p_a));
}

void	move_p_hook(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	apply_moves(cub);
	rotate(cub);
	cast_fov(cub);
	print_mini_map(cub);
	draw_fov(cub);
}
