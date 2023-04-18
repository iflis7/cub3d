/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:41:49 by loadjou           #+#    #+#             */
/*   Updated: 2023/04/18 17:31:17 by loadjou          ###   ########.fr       */
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
	j = y * cub->map->sq_size;
	while (j <= (y * cub->map->sq_size) + cub->map->sq_size)
	{
		i = x * cub->map->sq_size;
		mlx_put_pixel(cub->win, i, j, color);
		while (i <= (x * cub->map->sq_size) + cub->map->sq_size)
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

/* bool	get_p_angle(t_cub *cub)
{
	t_mini_m	*temp;
	int			i;
	size_t		dep;
	size_t		j;

	dep = ((WIDTH / 16 / 2) - (cub->map->max_line_len) / 2);
	j = (HEIGHT / 16) - cub->map->nb_lines;
	temp = cub->map->mini_m;
	while (temp)
	{
		i = 0;
		while (temp->line[i])
		{
			// i = 0;
			if (temp->line[i] == 'E' || temp->line[i] == 'W'
				|| temp->line[i] == 'N' || temp->line[i] == 'S')
			{
				cub->p_x = (dep + i) * 16 * 4;
				cub->p_y = j * 64 + 4;
				if (temp->line[i] == 'E')
					cub->p_a = 0;
				else if (temp->line[i] == 'W')
					cub->p_a = 180;
				else if (temp->line[i] == 'N')
					cub->p_a = 90;
				else if (temp->line[i] == 'S')
					cub->p_a = 270;
				// dprintf(2, "p_a: %.1f\n", cub->p_a);
				return (true);
			}
			i++;
		}
		temp = temp->next;
		j++;
	}
	return (false);
}
 */