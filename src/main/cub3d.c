/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:41:44 by loadjou           #+#    #+#             */
/*   Updated: 2023/04/12 11:02:05 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"



// void draw_ray(t_cub *cub);
void	main_hook(void *param)
{
	int32_t	i;
	int32_t	j;
	t_cub	*cub;

	cub = (t_cub *)param;
	i = 0;
	while (i < cub->mlx->width)
	{
		j = 0;
		while (j < cub->mlx->height)
		{
			if (j < cub->mlx->height / 2)
				mlx_put_pixel(cub->win, i, j, get_rgba(0, 0, 255, 100));
			if (j > cub->mlx->height / 2)
				mlx_put_pixel(cub->win, i, j, get_rgba(155, 055, 55, 255));
			j++;
		}
		i++;
	}
	print_mini_map(cub);
	// print_line(cub->player, cub->p_x, cub->p_x, 0);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cub->mlx);
	// NewCastRays(cub);
	// draw_ray(cub, 50);
	// access the player position using the cub->player->instances
	// printf("{%.2d, %.2d}\n",cub->player->instances[0].x, cub->player->instances[0].y);
	// printf("cub->player->instances[0].x %.2d\n: ", cub->player->instances[0].x);
	
	// printf("pa: %.2f\n", cub->p_a); 
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	// int i = 0;
	if (argc == 2)
	{
		cub = init_cub();
		parse_map(cub, argv[1]);
		
		init_game(cub);
		// print_map_lines(cub->map->mini_m);

		mlx_loop_hook(cub->mlx, &main_hook, cub);
		mlx_loop_hook(cub->mlx, &move_p_hook, cub);	
		mlx_loop(cub->mlx);
		// printf("gher dagi\n");
		// printf("cub->map->nb_lines: %d \n", cub->map->nb_lines);
		mlx_terminate(cub->mlx);
		// while(cub->map->mini_map[i])		
			// printf("%s", cub->map->mini_map[i++]);
		return (EXIT_SUCCESS);
	}
	else
		ft_msg_err("No map given.");
}

