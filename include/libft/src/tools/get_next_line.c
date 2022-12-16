/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 10:44:59 by hsaadi            #+#    #+#             */
/*   Updated: 2022/12/15 23:02:10 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*get_next_line(int fd)
{
	char *str;
	char *buff;
	int i;
	i = 0;
	str = malloc(sizeof(char) * 5);
	buff = str;
	while (read(fd, buff, 1) > 0 && *buff++ != '\n')
		i++;
	if (buff > str)
	{
		buff = 0;
		return (str);
	}
	else
	{
		free(str);
		return (NULL);
	}
}