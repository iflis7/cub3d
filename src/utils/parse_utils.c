/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:49:10 by hsaadi            #+#    #+#             */
/*   Updated: 2022/12/28 16:21:25 by hsaadi           ###   ########.fr       */
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

/**
 * @brief Check if the first and last charactere of the line are 1
 * 
 * @param line The line to check
 * @return true Returns true if the first and last charactere are 1
 * @return false Returns false if the first and last charactere are not 1
 */
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

/**
 * @brief Check if the line is composed only of 1
 * 
 * @param line The line to check
 * @return true Returns true if the line is composed only of 1
 * @return false Returns false if the line is not composed only of 1
 */
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

/**
 * @brief Get the identifier object from the line like : "NO ./path/to/no.xpm"
 * 
 * @param line The line to check

	* @return Char*  Returns the path if the line is a valid map line or the RGB value
 * @return Null Returns NULL if the line is not a valid map line
 */
char	*get_identifier(char *line_in, char *str)
{
	int	i;

	i = 0;
	char *line = ft_strtrim(line_in, "\n");
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
