/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bylkode <bylkode@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:03:42 by hsaadi            #+#    #+#             */
/*   Updated: 2023/04/20 19:46:35 by bylkode          ###   ########.fr       */
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
bool	map_is_valid(t_cub *cub)
{
	t_mini_m	*mini_m;
	int			i;

	mini_m = cub->map->mini_m;
	while (mini_m)
	{
		if (mini_m->prev && mini_m->next)
		{
			i = 0;
			while (mini_m->line && mini_m->line[i])
			{
				if (!valid_elements(cub, mini_m->line[i])
					&& !ft_iswhitespace(mini_m->line[i]))
					return (false);
				i++;
			}
		}
		mini_m = mini_m->next;
	}
	if (cub->p_dir == 0)
		ft_msg_err("No Player Bitch!");
	return (true);
}

/**
 * @brief Add the last node and incremnt the width and the height 
 *(number of elements and lines)
 * @param cub The cub structure
 * @param line The line to check and add
 */
static void	incerement(t_cub *cub, char *line)
{
	ft_mini_m_add_back(&cub->map->mini_m, line);
	cub->map->height++;
	if ((int)strlen(line) > cub->map->width)
		cub->map->width = strlen(line);
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
		ft_msg_err_close("Something went wrong while using malloc!", &fd);
	while (line)
	{
		if (!is_empty_line(line))
		{
			if (is_map_line(line) == 1)
				incerement(cub, line);
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
 * @brief Convert the linked list to an array
 * 
 * @param *mini_map The map linked list
 * @return char** Returns the map as an array
 */
char	**switch_toarray(t_map *mini_map)
{
	t_mini_m	*mini_m;
	char		**map;
	int			i;

	i = 0;
	map = ft_calloc(mini_map->height, sizeof(char *));
	if (!map)
		return (NULL);
	mini_m = mini_map->mini_m;
	while (mini_m)
	{
		map[i] = ft_strdup(mini_m->line);
		mini_m = mini_m->next;
		i++;
	}
	return (map);
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
		ft_msg_err_close("Invalid map.", &fd);
	close(fd);
	if (!map_is_valid(cub))
		return (ft_msg_err("Invalid map!"));
	cub->map->map = switch_toarray(cub->map);
	if (!cub->map->map)
		return (false);
	if (!flood_fill_check(cub))
		return (false);
	return (true);
}
