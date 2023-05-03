/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:03:42 by hsaadi            #+#    #+#             */
/*   Updated: 2023/05/03 14:17:51 by loadjou          ###   ########.fr       */
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
		i = 0;
		while (mini_m->line && mini_m->line[i])
		{
			if (!valid_elements(cub, mini_m->line[i])
				&& !ft_iswhitespace(mini_m->line[i]))
				return (false);
			i++;
		}
		mini_m = mini_m->next;
	}
	if (cub->p_dir == 0)
		ft_msg_err("No Player!");
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
		ft_msg_err_close("Empty file", &fd);
	while (line)
	{
		if (!is_empty_line(line))
		{
			if (!store_map_cases(cub, line))
				return (false);
		}
		else
			free(line);
		line = get_next_line(fd);
	}
	if (cub->map->mxln != 6 || !cub->map->idfs[0] || !cub->map->idfs[1]
		|| !cub->map->idfs[2] || !cub->map->idfs[3] || !cub->map->idfs[4]
		|| !cub->map->idfs[5])
	{
		assign_free(cub->map->idfs);
		return (false);
	}
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

static bool	correct_map(t_cub *cub)
{
	int	i;

	if (!cub->map->map)
		return (false);
	i = 0;
	while (i < cub->map->height)
	{
		cub->map->map[i] = normalize_chars(cub->map->map[i]);
		i++;
	}
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
		ft_msg_err_close("Invalid map!", &fd);
	close(fd);
	if (!map_is_valid(cub))
		return (false);
	cub->map->map = switch_toarray(cub->map);
	if (!cub->map->map)
		return (false);
	if (!flood_fill_check(cub) || !correct_map(cub))
		return (false);
	return (true);
}
