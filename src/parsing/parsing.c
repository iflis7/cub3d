/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:03:42 by hsaadi            #+#    #+#             */
/*   Updated: 2023/05/02 18:21:38 by hsaadi           ###   ########.fr       */
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
	int	i;
	int	j;

	i = 0;
	while (cub->map->map && cub->map->map[i])
	{
		j = 0;
		while (cub->map->map[i] && cub->map->map[i][j])
		{
			if (!valid_elements(cub, cub->map->map[i][j])
				&& !ft_iswhitespace(cub->map->map[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	if (cub->p_dir == 0)
		ft_msg_err("No Player Bitch!!");
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
	// char *trim;
	int		i;

	i = 0;
	line = get_next_line(fd);
	if (!line)
		ft_msg_err_close("Empty file", &fd);
	while (line)
	{
		if (!is_empty_line(line) && is_map_line(cub, line) == 1)
		{
			// trim = ft_strtrim(line, "	 \n");
			// cub->map->map[i] = trim;
			cub->map->map[i] = line;
			i++;
			cub->map->height++;
			if ((int)strlen(line) > cub->map->width)
				cub->map->width = strlen(line);
		}
		else if (!is_empty_line(line) && !store_map_cases(cub, line))
			return (false);
		else
			free(line);
		line = get_next_line(fd);
	}
	print_map(cub->map->map);
	return (true);
}

/**
 * @brief Convert the linked list to an array
 * 
 * @param *mini_map The map linked list
 * @return char** Returns the map as an array
 */
// char	**switch_toarray(t_map *mini_map)
// {
// 	t_mini_m	*mini_m;
// 	char		**map;
// 	int			i;
// 	i = 0;
// 	map = ft_calloc(mini_map->height, sizeof(char *));
// 	if (!map)
// 		return (NULL);
// 	mini_m = mini_map->mini_m;
// 	while (mini_m)
// 	{
// 		map[i] = ft_strdup(mini_m->line);
// 		mini_m = mini_m->next;
// 		i++;
// 	}
// 	return (map);
// }

bool	correct_map(t_cub *cub)
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
	cub->map->map = ft_calloc(sizeof(char *), count_lines(cub, file) + 1);
	if (!store_map(cub, fd))
		ft_msg_err_close("Invalid map <store>!", &fd);
	close(fd);
	if (!map_is_valid(cub))
		return (false);
	if (!flood_fill_check(cub) || !correct_map(cub))
		return (false);
	return (true);
}
