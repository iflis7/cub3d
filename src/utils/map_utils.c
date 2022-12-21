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

bool is_empty_line(char *line)
{
	int i = 0;
	while(line[i])
	{
		if(ft_iswhitespace(line[i]) == 0)
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
int is_map_line(char *line)
{
	int i = 0;
	while(line[i])
	{
		if(ft_isdigit(line[i]))
			return (1);
		else if(ft_isalpha(line[i]))
			return (2);
		i++;
	}
	return (0);
}

void print_map_lines(t_line *line)
{
	printf("\n ----------- Here is the map motherfuckers ----------- \n\n");
	while(line)
	{
		printf("%s\n", line->content);
		line = line->next;
	}
	printf("\n ----------- No More map motherfuckers ----------- \n\n");
}
