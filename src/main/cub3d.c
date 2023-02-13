/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:41:44 by loadjou           #+#    #+#             */
/*   Updated: 2023/02/12 22:11:19 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	print_mini_map(t_cub *cub)
{
	t_mini_m	*mini_m;
	int			i;
	int			j;
	int			dep;

	dep = ((cub->mlx->width / 16 / 2) - (cub->map->max_line_len) / 2);
	mini_m = cub->map->mini_m;
	j = (cub->mlx->height / 16) - cub->map->nb_lines;
	while (mini_m)
	{
		i = 0;
		while (mini_m->line[i])
		{
			if (mini_m->line[i] == '1')
				print_square(cub->win, i + dep, j, 0);
			else if (mini_m->line[i] != '\n')
				print_square(cub->win, i + dep, j, get_rgba(0, 255, 0, 255));
			if (strchr("NEWS", mini_m->line[i]))
			{
				cub->p_x = (dep + i) * 16 + 4;
				cub->p_y = j * 16 + 4;
				printf("X::%zu -- Y::%zu --> I::%i\n", cub->p_x * 16, cub->p_y,
						i);
				printf("AAngle:: %.2f \n\n", cub->p_a);
				// cub->player->instances[0].y = j * 16 + 4;
				// cub->player->instances[0].x = (dep + i) * 16 + 4;
			}
			i++;
		}
		mini_m = mini_m->next;
		j++;
	}
}

void	main_hook(void *param)
{
	int32_t	i;
	int32_t	j;

	t_cub *cub = param;
	i = 0;
	while (i < cub->mlx->width)
	{
		j = 0;
		while (j < cub->mlx->height)
		{
			if (j < cub->mlx->height / 2)
				mlx_put_pixel(cub->win, i, j, get_rgba(0, 0, 255, 100));
			else if (j > cub->mlx->height / 2)
				mlx_put_pixel(cub->win, i, j, get_rgba(0, 100, 100, 255));
			j++;
		}
		i++;
	}
	print_mini_map(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cub->mlx);
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	if (argc == 2)
	{
		cub = init_cub();
		parse_map(cub, argv[1]);
		init_game(cub);
		print_map_lines(cub->map->mini_m);
		mlx_loop_hook(cub->mlx, &main_hook, cub);
		cub->player = mlx_new_image(cub->mlx, 6, 6);
		memset(cub->player->pixels, get_rgba(255, 0, 0, 255), 6 * 6
				* sizeof(int));
		mlx_image_to_window(cub->mlx, cub->player, cub->p_x, cub->p_y);
		// mlx_image_to_window(cub->mlx, cub->player, 917, 1000);
		mlx_loop_hook(cub->mlx, &move_p_hook, cub);
		
		mlx_loop(cub->mlx);
		mlx_terminate(cub->mlx);
		return (EXIT_SUCCESS);
	}
	else
		ft_msg_err("No map given.");
}
