/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:37:19 by loadjou           #+#    #+#             */
/*   Updated: 2023/05/01 15:29:27 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	store_map_cases(t_cub *cub, char *line)
{
	if (is_map_line(line) == 1)
	{
		ft_mini_m_add_back(&cub->map->mini_m, line);
		cub->map->height++;
		if ((int)strlen(line) > cub->map->width)
			cub->map->width = strlen(line);
	}
	else if (is_map_line(line) == 2)
		manage_settings(cub->map, line);
	else if (is_map_line(line) == 3)
	{
		free(line);
		return (false);
	}
	return (true);
}
