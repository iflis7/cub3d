/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:37:19 by loadjou           #+#    #+#             */
/*   Updated: 2023/05/02 18:09:08 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*normalize_chars(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (!ft_strchr("NEWS", line[i]))
		{
			if (ft_strchr(" \t", line[i]))
				line[i] = '1';
			if (i == (int)ft_strlen(line) - 1 && line[i] != '1')
				line[i] = '1';
		}
		i++;
	}
	return (line);
}

int	count_lines(t_cub *cub, char *file)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line)
	{
		if(is_map_line(cub, line) == 1)
			i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	cub->check = 0;
	printf("i %d\n\n\n", i);
	return (i);
}

bool	store_map_cases(t_cub *cub, char *line)
{
	// printf("line manage : %s\n", line);
	if (is_map_line(cub, line) == 2)
	{
		// printf("line IN NEMMI 2: %s\n", line);
		if (!manage_settings(cub->map, line))
		{
			free(line);
			return (false);
		}
		// free(line);
	}
	else if (is_map_line(cub, line) == 3)
	{
		// printf("line IN NEMMI 3: %s\n", line);
		free(line);
		return (false);
	}
	return (true);
}
