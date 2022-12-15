/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:19:29 by hsaadi            #+#    #+#             */
/*   Updated: 2022/06/07 18:06:16 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char *read_and_keep(int fd, char *keep)
{
	char *buff;
	int rd_bytes;

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
		keep = ft_strjoin(keep, buff);
	}
	free(buff);
	return (keep);
}

static char *get_line(char *keep)
{
	int i;
	char *str;

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

static char *delete_shit(char *keep)
{
	int i;
	int j;
	char *str;

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
	while (keep[i] != '\0')
		str[j++] = keep[i++];
	str[j] = '\0';
	free(keep);
	return (str);
}

char *get_next_line(int fd)
{
	char *str;
	static char *keep[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	keep[fd] = read_and_keep(fd, keep[fd]);
	if (!keep[fd])
		return (NULL);
	str = get_line(keep[fd]);
	keep[fd] = delete_shit(keep[fd]);
	return (str);
}
