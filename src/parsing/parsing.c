#include "../../include/cub3d.h"

bool	map_is_valid(t_map *map)
{
	t_line	*line;

	line = map->line;
	while (line)
	{
		if ((!line->prev && !only_ones(line->content)) || (!line->next
				&& !only_ones(line->content)))
			return (false);
		else if (((line->prev || line->next) && !first_and_last(line->content)) )
			return (false);
		line = line->next;
	}
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
				manage_settings(cub->map, line);
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
	if (!map_is_valid(cub->map))
		return (ft_msg_err("Invalid map!"));
	// printf("cub->name = %s\n", cub->name);
	// just to silence the error for now
	return (true);
}
