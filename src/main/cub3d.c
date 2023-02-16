/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:41:44 by loadjou           #+#    #+#             */
/*   Updated: 2023/02/16 10:22:20 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
				mlx_put_pixel(cub->win, i, j, get_rgba(0, 100, 100, 255));
			j++;
		}
		i++;
	}
	print_mini_map(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cub->mlx);
	// access the player position using the cub->player->instances
	printf("cub->player->instances[0].y %.2d\n: ", cub->player->instances[0].y);
	printf("cub->player->instances[0].x %.2d\n: ", cub->player->instances[0].x);
	printf("cub->player angle:: %.2f\n: ", cub->p_a);
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
		cub->player = mlx_new_image(cub->mlx, 6, 6);
		memset(cub->player->pixels, get_rgba(255, 0, 0, 255), 6 * 6
				* sizeof(int));
		mlx_image_to_window(cub->mlx, cub->player, cub->p_x, cub->p_y);
		mlx_loop_hook(cub->mlx, &main_hook, cub);
		mlx_loop_hook(cub->mlx, &move_p_hook, cub);
		mlx_loop(cub->mlx);
		mlx_terminate(cub->mlx);
		return (EXIT_SUCCESS);
	}
	else
		ft_msg_err("No map given.");
}
