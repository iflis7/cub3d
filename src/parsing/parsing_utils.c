/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:37:19 by loadjou           #+#    #+#             */
/*   Updated: 2023/05/03 13:47:45 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*normalize_chars(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (!ft_strchr("NEWS", line[i]))
		{
			if (ft_strchr(" \t", line[i]))
				line[i] = '1';
			if (i == (int)ft_strlen(line) - 1 && line[i] != '1')
				line[i] = '1';
		}
		i++;
	}
	return (line);
}

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
	{
		if (!manage_settings(cub->map, line))
		{
			free(line);
			return (false);
		}
		free(line);
	}
	else if (is_map_line(line) == 3)
	{
		free(line);
		return (false);
	}
	return (true);
}

void	print_line_map(t_mini_m *map)
{
	t_mini_m	*temp;

	temp = map;
	while (temp)
	{
		printf("%s\n", temp->line);
		temp = temp->next;
	}
}
