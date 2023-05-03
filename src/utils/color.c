/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:48:10 by hsaadi            #+#    #+#             */
/*   Updated: 2023/05/03 13:51:38 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

UINT	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	ft_arraylen(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
		i++;
	return (i);
}

bool	load_color(UINT *c, char *line)
{
	int		r;
	int		g;
	int		b;
	char	**colors;

	
	colors = ft_split(line, ',');
	if (!colors)
		return (false);
	if (ft_arraylen(colors) < 3)
	{
		printf("Bad color format (RGB)\n");
		free_map(colors);
		return (false);
	}
	r = atoi(colors[0]);
	g = atoi(colors[1]);
	b = atoi(colors[2]);
	*c = get_rgba(r, g, b, 255);
	free_map(colors);
	return (true);
}
