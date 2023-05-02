/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:24:10 by loadjou           #+#    #+#             */
/*   Updated: 2023/05/02 07:53:01 by hsaadi           ###   ########.fr       */
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
}

void	print_legend(t_cub *cub)
{
	static mlx_image_t	*img;

	mlx_delete_image(cub->mlx, img);
	img = mlx_put_string(cub->mlx, "NORTH  SOUTH  EAST   WEST", WIDTH * 0.5
			- 60, HEIGHT - 96);
	mlx_draw_texture(cub->win, cub->map->north, WIDTH * 0.5 - 64,
		HEIGHT - 74);
	mlx_draw_texture(cub->win, cub->map->south, WIDTH * 0.5, HEIGHT
		- 74);
	mlx_draw_texture(cub->win, cub->map->east, WIDTH * 0.5 + 64,
		HEIGHT - 74);
	mlx_draw_texture(cub->win, cub->map->west, WIDTH * 0.5 + 128,
		HEIGHT - 74);
}

void	display_footer(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = HEIGHT - 100;
		while (j < HEIGHT)
		{
			mlx_put_pixel(cub->win, i, j, BG);
			j++;
		}
		i++;
	}
	print_legend(cub);
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
	display_footer(cub);
}
