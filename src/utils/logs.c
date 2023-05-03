/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:49:45 by hsaadi            #+#    #+#             */
/*   Updated: 2023/05/03 13:07:48 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_msg_err(char *error)
{
	write(2, "Error\n", 6);
	write(2, error, strlen(error));
	write(2, "\n", 1);
	exit(1);
	return (0);
}

int	ft_msg_err_close(char *error, int *fd)
{
	write(2, "Error\n", 6);
	write(2, error, strlen(error));
	write(2, "\n", 1);
	exit(1);
	close(*fd);
	return (0);
}

void	free_map_line(t_mini_m *mini_m)
{
	t_mini_m	*temp;

	while (mini_m)
	{
		temp = mini_m;
		mini_m = mini_m->next;
		free(temp->line);
		free(temp);
	}
}

void	free_game(t_cub *cub)
{
	free_map_line(cub->map->mini_m);
	free_map(cub->map->map);
	free_map(cub->map->idfs);
	mlx_delete_texture(cub->map->east);
	mlx_delete_texture(cub->map->north);
	mlx_delete_texture(cub->map->south);
	mlx_delete_texture(cub->map->west);
	if (cub->map)
		free(cub->map);
	if (cub)
		free(cub);
	printf("Done ✅\n");
}

/**
 * @brief Checks if the line is a map line
 *
 * @param line The line to check
 * @return int returns 1 if the line is a map line, 2 if it's a setting line
 */
int	is_map_line(char *line)
{
	int			i;
	static int	check[1];

	i = 0;
	while (line && line[i])
	{
		while (ft_iswhitespace(line[i]))
			i++;
		if (ft_isdigit(line[i]))
		{
			check[0] = 1;
			return (1);
		}
		else if (ft_isalpha(line[i]) && !check[0])
			return (2);
		else
			return (3);
		i++;
	}
	return (0);
}
