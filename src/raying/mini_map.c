// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   mini_map.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/02/05 11:25:28 by loadjou           #+#    #+#             */
// /*   Updated: 2023/02/05 13:20:11 by loadjou          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../../include/cub3d.h"


// bool	img_init(t_cub *cub)
// {
    
//     cub->wall = mlx_new_image(cub->mlx, 16, 16);
//     cub->floor = mlx_new_image(cub->mlx, 16, 16);
//     if(!img->wall || !img->floor)
//     {
//         ft_putstr_fd("Error while trying to init img", 2);
//         return false;
//     }
// 	// Set every pixel to white
// 	memset(cub->wall->pixels, 255, cub->wall->width * cub->wall->height * sizeof(int32_t));
// 	memset(cub->floor->pixels, 110, cub->floor->width * cub->floor->height * sizeof(int32_t));
//     return true;
// }



// void	moves_hook(void *param)
// {
// 	t_cub	*cub;

// 	cub = param;
// 	if (mlx_is_key_down(cub->mlx, MLX_KEY_UP))
// 		cub->player->instances[0].y -= 1;
// 	if (mlx_is_key_down(cub->mlx, MLX_KEY_DOWN))
// 		cub->player->instances[0].y += 1;
// 	if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT))
// 		cub->player->instances[0].x -= 1;
// 	if (mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT))
// 		cub->player->instances[0].x += 1;
// }

// void	print_mini_map(t_cub *cub)
// {
// 	t_mini_m	*mini_m;
// 	int			i;
// 	int			j;
// 	int			dep;

// 	dep = ((WIDTH / 16 / 2) - (cub->map->max_line_len) / 2);
// 	mini_m = cub->map->mini_m;
// 	// mini_m->coord[0] = dep; 							// x_min
// 	j = (HEIGHT / 16) - cub->map->nb_lines;
// 	// mini_m->coord[2] = j; 								// y_min
// 	while (mini_m)
// 	{
// 		i = 0;
// 		while (mini_m->line[i])
// 		{
// 			if (mini_m->line[i] == '1')
//                 mlx_image_to_window(cub->win, cub->wall, i + dep, j);
// 			else if (mini_m->line[i] == '0')
//                 mlx_image_to_window(cub->win, cub->floor, i + dep, j);
// 			if (strchr("NEWS", mini_m->line[i]))
// 			{
// 				cub->p_x = (dep + (i));
// 				cub->p_y = j * 16;
//                 mlx_image_to_window(cub->win, cub->floor, i + dep, j);
// 				// printf("%zu %zu\n", cub->p_x, cub->p_y);
// 				// cub->player->instances[0].y = j;
// 				// cub->player->instances[0].y = dep + i;
// 			}
// 			i++;
// 		}
// 		mini_m = mini_m->next;
// 		j++;
// 	}
// 	// mini_m->coord[1] = dep + i; 						// x_max
// 	// mini_m->coord[3] = j;								// y_max
// }


