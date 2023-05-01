/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:18:34 by loadjou           #+#    #+#             */
/*   Updated: 2023/05/01 14:18:36 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_pcoordinates(t_cub *cub)
{
	t_mini_m	*mini_m;
	int			i;
	int			j;

	mini_m = cub->map->mini_m;
	j = 0;
	while (mini_m)
	{
		i = 0;
		while (mini_m->line[i])
		{
			if (strchr("NEWS", mini_m->line[i]))
			{
				cub->coord[X] = (i * cub->map->sq_size) + cub->map->sq_size / 2;
				cub->coord[Y] = j * cub->map->sq_size + cub->map->sq_size / 2;
			}
			i++;
		}
		mini_m = mini_m->next;
		j++;
	}
}

bool	get_p_angle(t_cub *cub)
{
	t_mini_m	*temp;

	temp = cub->map->mini_m;
	while (temp->next)
	{
		if (strchr(temp->line, 'E'))
			cub->p_a = deg_to_rad(0);
		else if (strchr(temp->line, 'W'))
			cub->p_a = deg_to_rad(180);
		else if (strchr(temp->line, 'N'))
			cub->p_a = deg_to_rad(90);
		else if (strchr(temp->line, 'S'))
			cub->p_a = deg_to_rad(270);
		temp = temp->next;
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
	int	n;

	n = 0;
	while (map[n])
	{
		free(map[n]);
		n++;
	}
	free(map);
}
