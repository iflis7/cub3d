#include "../../include/cub3d.h"

bool	valid_elements(char c)
{
	static char	news[4];

	if ((c == '0' || c == '1') || (c == 'N' && news[0] != 'N') || (c == 'E'
			&& news[1] != 'E') || (c == 'W' && news[2] != 'W') || (c == 'S'
			&& news[3] != 'S'))
	{
		if (c == 'N')
			news[0] = 'N';
		else if (c == 'E')
			news[1] = 'E';
		else if (c == 'W')
			news[2] = 'W';
		else if (c == 'S')
			news[3] = 'S';
		return (true);
	}
	else
		return (false);
}

bool	first_and_last(char *line)
{
	int	i;
	int	flag;
	int	len;

	i = 0;
	flag = 0;
	len = strlen(line) - 1;
	while (line && line[i])
	{
		if (!valid_elements(line[i]) && !ft_iswhitespace(line[i]))
			return (false);
		else if (ft_isdigit(line[i]) && !flag && line[i] == '1')
			flag = 1;
		else if (i == len && ft_isdigit(line[len]) && line[len] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	only_ones(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_iswhitespace(line[i]) && line[i] != '1')
			return (false);
		i++;
	}
	return (true);
}

char	*get_identifier(char *line, char *str)
{
	int	i;

	i = 0;
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
		return (NULL);
}
