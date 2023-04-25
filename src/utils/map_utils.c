/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:45:34 by hsaadi            #+#    #+#             */
/*   Updated: 2023/04/25 18:49:52 by hsaadi           ###   ########.fr       */
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
	int			i;
	static int	check[1];

	i = 0;
	while (line && line[i])
	{
		while (ft_iswhitespace(line[i]))
			i++;
		if (ft_isdigit(line[i]))
		{
			check[0] = 1;
			return (1);
		}
		else if (ft_isalpha(line[i]) && !check[0])
			return (2);
		else
			return (3);
		i++;
	}
	return (0);
}

/**
 * @brief print the map lines
 *
 * @param line The first line (node) of the map
 */
void	print_map_lines(t_mini_m *mini_m)
{
	printf("\n ----------- Here is the map motherfuckers ----------- \n\n");
	while (mini_m)
	{
		printf("%s\n", mini_m->line);
		mini_m = mini_m->next;
	}
	printf("\n ----------- No More map motherfuckers ----------- \n\n");
}

void	print_map(char **mini_m)
{
	int	i;

	printf("\n ----------- Here is the map motherfuckers ----------- \n\n");
	i = 0;
	while (mini_m && mini_m[i])
	{
		printf("%s\n", mini_m[i++]);
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
	if (access_test(get_identifier(line, "NO"), ".xpm"))
		map->north = mlx_load_xpm42(convert_path(get_identifier(line, "NO")));
	else if (access_test(get_identifier(line, "SO"), ".xpm"))
		map->south = mlx_load_xpm42(convert_path(get_identifier(line, "SO")));
	else if (access_test(get_identifier(line, "WE"), ".xpm"))
		map->west = mlx_load_xpm42(convert_path(get_identifier(line, "WE")));
	else if (access_test(get_identifier(line, "EA"), ".xpm"))
		map->east = mlx_load_xpm42(convert_path(get_identifier(line, "EA")));
	else if (get_identifier(line, "F")) 
		load_color(&map->floor, get_identifier(line, "F"));
	else if (get_identifier(line, "C"))
		load_color(&map->ceil, get_identifier(line, "C"));
	else
		return (false);
	return (true);
}
