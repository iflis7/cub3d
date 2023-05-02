/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:45:34 by hsaadi            #+#    #+#             */
/*   Updated: 2023/05/02 18:11:54 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * @brief Check if the file is valid
 *
 * @param file The path to the file to check
 * @param ext The extension of the file to check
 * @return int Returns 1 if the file is valid, 0 if not
 */
int	access_test(char *file, char *ext)
{
	int		fd;
	char	*str;

	if (!file)
		return (0);
	str = ft_strtrim(file, "\n");
	if (!str)
		return (0);
	if (strcmp(str + strlen(str) - strlen(ext), ext))
	{
		free(str);
		ft_msg_err("Wrong file type: ext <map | texture>");
	}
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		free(str);
		ft_msg_err("Can't open file <map | texture>");
	}
	free(str);
	close(fd);
	return (1);
}

/**
 * @brief Check if the line is empty
 *
 * @param line The line to check
 * @return bool Returns true if the line is  empty, false if not
 */
bool	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (!ft_iswhitespace(line[i]))
			return (false);
		i++;
	}
	return (true);
}

/**
 * @brief Checks if the line is a map line
 *
 * @param line The line to check
 * @return int returns 1 if the line is a map line, 2 if it's a setting line
 */
int	is_map_line(t_cub *cub, char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (ft_isdigit(line[i]))
		{
			cub->check = 1;
			// printf("line map_line 1: %s\n", line);
			return (1);
		}
		else if (ft_isalpha(line[i]) && !cub->check)
		{
			// printf("line map_line 2: %s\n", line);
			return (2);
		}
		else if (!ft_iswhitespace(line[i]))
		{
			// printf("line map_line 3: %s\n", line);
			return (3);
		}
		i++;
	}
	return (0);
}

/**
 * @brief Assign the path to the right identifier
 *
 * @param line The line to check
 * @return char** Returns an array of strings containing the path to the
 * different identifiers
 */
char	**assign_path(char *line)
{
	char	**idfs;

	idfs = malloc(6 * sizeof(char *));
	if (!idfs)
		ft_msg_err("Malloc error");
	idfs[0] = get_identifier(line, "NO");
	idfs[1] = get_identifier(line, "SO");
	idfs[2] = get_identifier(line, "WE");
	idfs[3] = get_identifier(line, "EA");
	idfs[4] = get_identifier(line, "F");
	idfs[5] = get_identifier(line, "C");
	
	return (idfs);
}
/**
 * @brief 
 * 
 * @param map 
 * @param idfs 
 * @param line 
 * @return true 
 * @return false 
 */
static bool	manage_colors(t_map *map, char **idfs, int line)
{
	if (line == 4)
	{
		if (!load_color(&map->floor, idfs[4]))
		{
			free(idfs[4]);
			return (false);
		}
		assign_free(idfs);
	}
	else if (line == 5)
	{
		if (!load_color(&map->ceil, idfs[5]))
		{
			free(idfs[5]);
			return (false);
		}
		assign_free(idfs);
	}
	return (true);
}

/**
 * @brief Nabage setting lines and store them in the map struct
 *
* @param line The line to check and store. Check if it's a setting
	line and if the path is valid then store it in the map struct.
 * @return bool Returns true if the line is a map line, false if not
 */
bool	manage_settings(t_map *map, char *line)
{
	char	**idfs;

	idfs = assign_path(line);
	if (idfs[0] != NULL && access_test(idfs[0], ".png"))
		map->north = mlx_load_png(idfs[0]);
	else if (idfs[1] != NULL && access_test(idfs[1], ".png"))
		map->south = mlx_load_png(idfs[1]);
	else if (idfs[2] != NULL && access_test(idfs[2], ".png"))
		map->west = mlx_load_png(idfs[2]);
	else if (idfs[3] != NULL && access_test(idfs[3], ".png"))
		map->east = mlx_load_png(idfs[3]);
	else if (idfs[4] != NULL)
		return (manage_colors(map, idfs, 4));
	else if (idfs[5] != NULL)
		return (manage_colors(map, idfs, 5));
	else
	{
		assign_free(idfs);
		return (false);
	}
	assign_free(idfs);
	return (true);
}
