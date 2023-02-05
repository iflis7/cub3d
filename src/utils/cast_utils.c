/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:41:49 by loadjou           #+#    #+#             */
/*   Updated: 2023/02/05 14:06:17 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	print_square(mlx_image_t *win, uint32_t x, uint32_t y, uint32_t color)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = y * 16 + 1;
	while (j <= (y * 16) + 16 - 1)
	{
		i = x * 16 + 1;
		mlx_put_pixel(win, i, j, color);
		while (i <= (x * 16) + 16 - 1)
		{
			mlx_put_pixel(win, i, j, color);
			i++;
		}
		j++;
	}
}

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


