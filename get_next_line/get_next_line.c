/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:21:35 by hsaadi            #+#    #+#             */
/*   Updated: 2022/06/07 17:13:28 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_keep(int fd, char *keep)
{
	char	*buff;
	int		rd_bytes;

	buff = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(keep, '\n') && rd_bytes > 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		keep = ft_strjoin(keep, buff);
	}
	free(buff);
	return (keep);
}

char	*get_line(char *keep)
{
	int		i;
	char	*str;

	i = 0;
	if (!keep[i])
		return (NULL);
	while (keep[i] && keep[i] != '\n')
		i++;
	str = ft_calloc(sizeof(char), (i + 2));
	if (!str)
		return (NULL);
	ft_strlcpy(str, keep, i + 2);
	return (str);
}

char	*delete_shit(char *keep)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = 0;
	while (keep[i] && keep[i] != '\n')
		i++;
	if (!keep[i])
	{
		free(keep);
		return (NULL);
	}
	str = ft_calloc(sizeof(char), (ft_strlen(keep) - i + 1));
	if (!str)
		return (NULL);
	i++;
	while (keep[i])
		str[j++] = keep[i++];
	str[j] = '\0';
	free(keep);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*keep;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	keep = read_and_keep(fd, keep);
	if (!keep)
		return (NULL);
	str = get_line(keep);
	keep = delete_shit(keep);
	return (str);
}
