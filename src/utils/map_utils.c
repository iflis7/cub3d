/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:45:34 by hsaadi            #+#    #+#             */
/*   Updated: 2022/12/28 16:32:56 by hsaadi           ###   ########.fr       */
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
	while (line[i])
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
int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			return (1);
		else if (ft_isalpha(line[i]))
			return (2);
		i++;
	}
	return (0);
}

/**
 * @brief print the map lines
 * 
 * @param line The first line (node) of the map
 */
void	print_map_lines(t_line *line)
{
	printf("\n ----------- Here is the map motherfuckers ----------- \n\n");
	while (line)
	{
		printf("%s\n", line->content);
		line = line->next;
	}
	printf("\n ----------- No More map motherfuckers ----------- \n\n");
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
	// TODO add access_test for the path
	if (access_test(get_identifier(line, "NO"), ".png"))
		map->north = get_identifier(line, "NO");
	else if (access_test(get_identifier(line, "SO"), ".png"))
		map->south = get_identifier(line, "SO");
	else if (access_test(get_identifier(line, "WE"), ".png"))
		map->west = get_identifier(line, "WE");
	else if (access_test(get_identifier(line, "EA"), ".png"))
		map->east = get_identifier(line, "EA");
	else if (get_identifier(line, "F")) // TODO add color check
		// map->floor = (UINT *)get_identifier(line, "F");
			// TODO convert the color to hex
		load_color(&map->floor, get_identifier(line, "F"));
	else if (get_identifier(line, "C"))
		// 	map->ceil = (UINT *)get_identifier(line, "C");
				// TODO convert the color to hex
		load_color(&map->ceil, get_identifier(line, "C"));
	else
		return (false);
	return (true);
}
