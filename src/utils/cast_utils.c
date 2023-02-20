/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:41:49 by loadjou           #+#    #+#             */
/*   Updated: 2023/02/16 19:11:25 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	print_square(t_cub *cub, uint32_t x, uint32_t y, uint32_t color)
{
	size_t	i;
	size_t	j;

	i = 0;
	// printf("dep (%d, %d)\n",x, y);
	// printf("sq_size: (%ld)\n",cub->map->sq_size);
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

void	print_line(mlx_image_t *win, uint32_t x, uint32_t y, uint32_t color)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = y * 5 + 1;
	while (j <= (y * 5) + 5 - 1)
	{
		i = x * 5 + 1;
		mlx_put_pixel(win, i, j, color);
		while (i <= (x * 5) + 5 - 1)
		{
			mlx_put_pixel(win, i, j, color);
			i++;
		}
		j++;
	}
}

// print_square(cub->win, i + dep, j, get_rgba(0, 255, 0, 255));

// glVertex2i(px,py); glVertex2i(px+pdx*20,py+pdy*20)

void	print_mini_p(mlx_image_t *win, uint32_t x, uint32_t y, uint32_t color)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = y * 16 + 4;
	while (j <= (y * 16) + 12)
	{
		i = x * 16 + 4;
		mlx_put_pixel(win, i, j, color);
		while (i <= (x * 16) + 12)
		{
			mlx_put_pixel(win, i, j, color);
			i++;
		}
		j++;
	}
}


