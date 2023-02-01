/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:03:42 by hsaadi            #+#    #+#             */
/*   Updated: 2023/01/31 19:31:46 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * @brief Check if the file is valid (the map file and the textures)
 * 
 * checks if the file exists and if it has the right extension.
 * Cheks that the first and last lines of the map are only composed of 1s.
 * Checks that the first element and last element of each line are 1s.
 * Checks that the map includes only 0s, 1s, 2s, N, S, E, W.
 * @param *map The map to check 
 * @return Bool Returns true if the map is valid, false if not
 */
bool	map_is_valid(t_map *map)
{
	t_mini_m	*mini_m;

	mini_m = map->mini_m;
	while (mini_m)
	{
		if ((!mini_m->prev || !mini_m->next) && !only_ones(mini_m->line))
			return (false);
		else if (((mini_m->prev && mini_m->next)
					&& !first_and_last(mini_m->line)))
			return (false);
		mini_m = mini_m->next;
	}
	return (true);
}

/**
 * @brief Store the map in a linked list
 * if is_map_line returns 1, the line is added to the map->line linked list.
 * if is_map_line returns 2, the line is added to the map struct.
 * @param *cub The cub struct
 * @param fd The file descriptor of th`e map file
 * @return Bool Returns true if the map is valid, false if not
 */

bool	store_map(t_cub *cub, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		ft_msg_err("Something went wrong while using malloc!.");
	}
	while (line)
	{
		if (!is_empty_line(line))
		{
			if (is_map_line(line) == 1) 
				ft_mini_m_add_back(&cub->map->mini_m, line);
			else if (is_map_line(line) == 2)
				manage_settings(cub->map, line);
			else if (is_map_line(line) == 3)
			{
				free(line);
				return (false);
			}
		}
		line = get_next_line(fd);
	}
	free(line);
	return (true);
}

/**
 * @brief Parse the map file
 * 
 * @param *cub The cub struct
 * @param *file The map file path
 * @return Bool Returns true if the map is valid, false if not
 */
bool	parse_map(t_cub *cub, char *file)
{
	int	fd;

	if (!access_test(file, ".cub"))
		return (ft_msg_err("Map file not found."));
	fd = open(file, O_RDONLY);
	if (!store_map(cub, fd))
	{
		close(fd);
		ft_msg_err("Invalid map.");
	}
	close(fd);
	if (!map_is_valid(cub->map))
		return (ft_msg_err("Invalid map!"));
	return (true);
}
