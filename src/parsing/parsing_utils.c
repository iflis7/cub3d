/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:37:19 by loadjou           #+#    #+#             */
/*   Updated: 2023/05/01 17:32:21 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	print_map_lines(t_mini_m *mini_m)
{
	printf("\n ----------- Here is the map motherfuckers ----------- \n\n");
	while (mini_m)
	{
		printf("%s\n", mini_m->line);
		mini_m = mini_m->next;
	}
	printf("\n ----------- No More map motherfuckers ----------- \n\n");
}

void	print_map(char **mini_m)
{
	int	i;

	printf("\n ----------- Here is the map motherfuckers ----------- \n\n");
	i = 0;
	while (mini_m && mini_m[i])
	{
		printf("%s\n", mini_m[i++]);
	}
	printf("\n ----------- No More map motherfuckers ----------- \n\n");
}


bool	store_map_cases(t_cub *cub, char *line)
{
	if (is_map_line(line) == 1)
	{
		ft_mini_m_add_back(&cub->map->mini_m, line);
		cub->map->height++;
		if ((int)strlen(line) > cub->map->width)
			cub->map->width = strlen(line);
		// free(line);
	}
	else if (is_map_line(line) == 2)
	{	
		manage_settings(cub->map, line);
		// free(line);
	}

	else if (is_map_line(line) == 3)
	{
		free(line);
		return (false);
	}
	return (true);
}


