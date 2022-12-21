#include "../../include/cub3d.h"
const char	*directions[4] = {"NO", "SO", "WE", "EA"};

bool manage_settings(char *line, t_map *map)
{
	// if true line == NO and path is good store it in map->north else return error
	if(strcmp(line, "NO") == 0) // TODO add access_test for the path 
	{
		map->north = "./path_to_the_north_texture";
	}
	else if(strcmp(line, "SO") == 0)
	{
		map->south = "./path_to_the_south_texture";
	}
	else if(strcmp(line, "WE") == 0)
	{
		map->west = "./path_to_the_west_texture";
	}
	else if(strcmp(line, "EA") == 0)
	{
		map->east = "./path_to_the_east_texture";
	}
	else if(strcmp(line, "F") == 0) // TODO add color check in separate function
	{
		map->floor = 0x000000; // TODO convert the color to hex
	}
	else if(strcmp(line, "C") == 0)
	{
		map->ceiling = 0x000000; // TODO convert the color to hex
	}
	else
		return (false);
	return (true);
}

bool	store_map(char *file, t_cub *cub)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (!is_empty_line(line))
		{
			if (is_map_line(line) == 1)
				ft_line_add_back(&cub->map->line, line);
			else if (is_map_line(line) == 2)
				manage_settings(line, cub->map);
		}
		line = get_next_line(fd);
	}
	return (true);
}

bool	parse_map(t_cub *cub, char *file)
{
	if (!access_test(file, ".cub"))
		return (ft_msg_err("Map file not found."));
	if (!store_map(file, cub))
		return (ft_msg_err("Invalid map."));
	// printf("cub->name = %s\n", cub->name); // just to silence the error for now
	return (true);
}
