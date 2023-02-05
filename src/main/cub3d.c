/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:41:44 by loadjou           #+#    #+#             */
/*   Updated: 2023/02/05 13:56:57 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"




bool	img_init(t_cub *cub)
{
    
    cub->wall = mlx_new_image(cub->mlx, 16, 16);
    cub->floor = mlx_new_image(cub->mlx, 16, 16);
    if(!cub->wall || !cub->floor)
    {
        ft_putstr_fd("Error while trying to init img", 2);
        return false;
    }
	// Set every pixel to white
	memset(cub->wall->pixels, 255, cub->wall->width * cub->wall->height * sizeof(int32_t));
	memset(cub->floor->pixels, 110, cub->floor->width * cub->floor->height * sizeof(int32_t));
    return true;
}



void	moves_hook(void *param)
{
	t_cub	*cub;

	cub = param;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_UP))
		cub->player->instances[0].y -= 1;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_DOWN))
		cub->player->instances[0].y += 1;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT))
		cub->player->instances[0].x -= 1;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT))
		cub->player->instances[0].x += 1;
}

void	print_mini_map(t_cub *cub)
{
	t_mini_m	*mini_m;
	int			i;
	int			j;
	int			dep;

	dep = ((WIDTH / 16 / 2) - (cub->map->max_line_len) / 2);
	mini_m = cub->map->mini_m;
	// mini_m->coord[0] = dep; 							// x_min
	j = (HEIGHT / 16) - cub->map->nb_lines;
	img_init(cub);
	// mini_m->coord[2] = j; 								// y_min
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
				cub->p_x = (dep + (i));
				cub->p_y = j * 16;
				// printf("%zu %zu\n", cub->p_x, cub->p_y);
				// cub->player->instances[0].y = j;
				// cub->player->instances[0].y = dep + i;
			}
			i++;
		}
		mini_m = mini_m->next;
		j++;
	}
	// mini_m->coord[1] = dep + i; 						// x_max
	// mini_m->coord[3] = j;								// y_max
}






void	main_hook(void *param)
{
	unsigned int	i;

	t_cub *const cub = param;
	i = 0;
	while (i < WIDTH * HEIGHT)
	{
		if (i < HEIGHT * (WIDTH / 2))
			mlx_put_pixel(cub->win, i, 0, get_rgba(0, 0, 255, 100));
		else if (i > HEIGHT * (WIDTH / 2))
			mlx_put_pixel(cub->win, i, 0, get_rgba(0, 100, 100, 255));
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
		mlx_image_to_window(cub->mlx, cub->player, 917, 1029);
		mlx_loop_hook(cub->mlx, &moves_hook, cub);
		mlx_loop(cub->mlx);
		mlx_terminate(cub->mlx);
		return (EXIT_SUCCESS);
	}
	else
		ft_msg_err("No map given.");
}
