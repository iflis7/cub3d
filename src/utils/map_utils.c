#include "../../include/cub3d.h"

int	access_test(char *file, char *ext)
{
	int	fd;

	if (strcmp(file + strlen(file) - 4, ext))
		ft_msg_err("Wrong file type.");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

bool	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_iswhitespace(line[i]) == 0)
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

bool	manage_settings(t_map *map, char *line)
{
	// if true line == NO and path is good store it in map->north else return error
	if (strcmp(line, "NO") == 0) // TODO add access_test for the path
	{
		map->north = "./path_to_the_north_texture";
	}
	else if (strcmp(line, "SO") == 0)
	{
		map->south = "./path_to_the_south_texture";
	}
	else if (strcmp(line, "WE") == 0)
	{
		map->west = "./path_to_the_west_texture";
	}
	else if (strcmp(line, "EA") == 0)
	{
		map->east = "./path_to_the_east_texture";
	}
	else if (strcmp(line, "F") == 0)
	// TODO add color check in separate function
	{
		map->floor = 0x000000; // TODO convert the color to hex
	}
	else if (strcmp(line, "C") == 0)
	{
		map->ceil = 0x000000; // TODO convert the color to hex
	}
	else
		return (false);
	return (true);
}
