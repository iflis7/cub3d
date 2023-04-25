/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bylkode <bylkode@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:49:10 by hsaadi            #+#    #+#             */
/*   Updated: 2023/04/25 17:14:22 by bylkode          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * @brief Check if the charactere is a valid element
 * 
 * @param c The charactere to check. Char must be 1, 0, N, E,
	W or S. Letter must be unique.
 * @return true returns true if the charactere is valid
 * @return false returns false if the charactere is not valid
 */
bool	valid_elements(t_cub *cub, char c)
{
	if ((c == '0' || c == '1') || ((c == 'N' || c == 'E' || c == 'W'
				|| c == 'S') && cub->p_dir == 0))
	{
		if (c == 'N')
			cub->p_dir = 'N';
		else if (c == 'E')
			cub->p_dir = 'E';
		else if (c == 'W')
			cub->p_dir = 'W';
		else if (c == 'S')
			cub->p_dir = 'S';
		return (true);
	}
	else
		return (false);
}

/**
 * @brief Get the identifier object from the line like : "NO ./path/to/no.xpm"
 * 
 * @param line The line to check

	* @return Char*  Returns the path if the line is a valid map line or the RGB value
 * @return Null Returns NULL if the line is not a valid map line
 */
char	*get_identifier(char *line_in, char *str)
{
	int		i;
	char	*line;

	i = 0;
	line = ft_strtrim(line_in, "\n");
	while (line && line[i] && ft_iswhitespace(line[i]))
		i++;
	if (!strncmp(&line[i], str, strlen(str)))
	{
		i += strlen(str);
		while (ft_iswhitespace(line[i]))
			i++;
		return (&line[i]);
	}
	else
	{
		free(line);
		return (NULL);
	}
}

/**
 * @brief Get the player pos object
 * 
 * @param map the map to check
 * @param pos te array where to store the X and Y positions
 * @return true if ther are player positions
 * @return false if no player positions
 */
bool	get_player_pos(char **map, size_t *pos)
{
	int	i;
	int	j;

	i = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'W'
				|| map[i][j] == 'S')
			{
				pos[0] = i;
				pos[1] = j;
				return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}

/**
 * @brief Check if the srrounding elements are walls using the flood fill algo 
 *  Copy the map to new one, get the initial position of the player
 * @param cub the cub structure
 * @return true if everything is surrounded by walls
 * @return false if not everything is surrounded by walls
 */
bool	flood_fill_check(t_cub *cub)
{
	size_t	pos[2];
	char	**new_map;
	bool	is_surrounded;

	if(!get_player_pos(cub->map->map, pos))
		return (ft_msg_err("No player position found"));		
	new_map = duplicate_map(cub->map->map);
	if (!new_map)
		return (ft_msg_err("Something went wrong with calloc!"));
	is_surrounded = floodfill(cub, new_map, pos[0], pos[1]);
	if (!is_surrounded)
	{ 
		free_map(new_map);
		return (ft_msg_err("Map isn't surrounded by wall"));
	}
	return (true);
}

/**

	* @brief Check if the srrounding elements are walls using the flood fill algo recursively
 * 
 * @param cub The cub structure

	* @param new_map  The map where the old map is copied (to be able to change elements)
 * @param i The x coordinates of the player
 * @param j The y coordinates of the player
 * @return true if everything is surrounded by walls
 * @return false if not everything is surrounded by walls
 */
bool	floodfill(t_cub *cub, char **new_map, int i, int j)
{
	bool is_surrounded;
	if (i < 0 || i >= cub->map->height - 1 || j < 0 || j >= cub->map->width)
		return (false);
	if (cub->map->map[i][j] == '1' || new_map[i][j] == true)
		return (true);
	else
		new_map[i][j] = true;
	is_surrounded = true;
	is_surrounded &= floodfill(cub, new_map, i - 1, j);
	is_surrounded &= floodfill(cub, new_map, i + 1, j);
	is_surrounded &= floodfill(cub, new_map, i, j - 1);
	is_surrounded &= floodfill(cub, new_map, i, j + 1);
	return (is_surrounded);
}
