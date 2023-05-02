/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:41:44 by loadjou           #+#    #+#             */
/*   Updated: 2023/05/02 18:05:51 by hsaadi           ###   ########.fr       */
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
				mlx_put_pixel(cub->win, i, j, cub->map->ceil);
			else if (j > cub->mlx->height / 2)
				mlx_put_pixel(cub->win, i, j, cub->map->floor);
			j++;
		}
		i++;
	}
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
		{
		mlx_close_window(cub->mlx);}
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
	free(mini_m);
}







// void free_map_line(t_mini_m *mini_m) {
//     if (mini_m == NULL) {
//         return;
//     }
//     free_map_line(mini_m->next); // free the rest of the list
//     free(mini_m->line); // free the string in this node
//     free(mini_m); // free this node
// 	// if (mini_m->prev != NULL) {
//     //     mini_m->prev->next = NULL; // set the next pointer of the previous node to NULL
//     //     free(mini_m->prev); // free the previous node itself
//     // }
// }

void	ptr_addr(char *var_name, void *ptr)
{
	if(ptr)
		printf("%s %p\n\n", var_name, ptr);
	else
		printf("%s Already freed\n\n", var_name);
}

void	free_game(t_cub *cub)
{
	// free_map_line(cub->map->mini_m);
	free_map(cub->map->map);

	mlx_delete_texture(cub->map->east);
	mlx_delete_texture(cub->map->north);
	mlx_delete_texture(cub->map->south);
	mlx_delete_texture(cub->map->west);
	
	if (cub->map)
		free(cub->map);
	if (cub)
		free(cub);
	printf("freed\n");
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	if (argc == 2)
	{
		cub = init_cub();
		if (!parse_map(cub, argv[1]))
			ft_msg_err("Bad Map Buddy!");
		init_game(cub);
		mlx_loop_hook(cub->mlx, &main_hook, cub);
		mlx_loop_hook(cub->mlx, &move_p_hook, cub);
		// printf("DAGI!! \n");
		mlx_loop(cub->mlx);
		mlx_terminate(cub->mlx);
		// free_game(cub);
		return (EXIT_SUCCESS);
	}
	else
		ft_msg_err("No map given.");
}
