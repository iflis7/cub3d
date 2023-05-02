/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:18:34 by loadjou           #+#    #+#             */
/*   Updated: 2023/05/02 17:58:23 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_pcoordinates(t_cub *cub)
{
	int			i;
	int			j;

	j = 0;
	while (cub->map->map && cub->map->map[i])
	{
		i = 0;
		while (cub->map->map[i] && cub->map->map[i][j])
		{
			if (strchr("NEWS", cub->map->map[i][j]))
			{
				cub->coord[X] = (i * cub->map->sq_size) + cub->map->sq_size / 2;
				cub->coord[Y] = j * cub->map->sq_size + cub->map->sq_size / 2;
			}
			i++;
		}
		j++;
	}
}

bool	get_p_angle(t_cub *cub)
{

	int i = 0;
	while (cub->map->map[i])
	{
		if (strchr(cub->map->map[i], 'E'))
			cub->p_a = deg_to_rad(0);
		else if (strchr(cub->map->map[i], 'W'))
			cub->p_a = deg_to_rad(180);
		else if (strchr(cub->map->map[i], 'N'))
			cub->p_a = deg_to_rad(90);
		else if (strchr(cub->map->map[i], 'S'))
			cub->p_a = deg_to_rad(270);
		i++;
	}
	return (true);
}

char	**duplicate_map(char **map)
{
	int		n;
	char	**new_map;

	n = 0;
	while (map[n])
		n++;
	new_map = (char **)malloc((n + 1) * sizeof(char *));
	memcpy(new_map, map, (n + 1) * sizeof(char *));
	return (new_map);
}

void	free_map(char **map)
{
	char	**p;

	if (map == NULL)
		return ;
	p = map;
	while (*p)
	{
		free(*p++);
	}
	free(map);
}

void	assign_free(char **idfs)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		free(idfs[i]);
		i++;
	}
	free(idfs);
}
