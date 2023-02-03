#include "../../include/cub3d.h"

void	print_square(mlx_image_t *win, uint32_t x, uint32_t y, uint32_t color)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = y * 16;
	while (j <= (y * 16) + 16)
	{
		i = x * 16;
		mlx_put_pixel(win, i, j, color);
		while (i <= (x * 16) + 16)
		{
			mlx_put_pixel(win, i, j, color);
			i++;
		}
		j++;
	}
}

void	print_mini_p(mlx_image_t *win, uint32_t x, uint32_t y, uint32_t color)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = y * 16 + 4;
	while (j <= (y * 16) + 12)
	{
		i = x * 16 + 4;
		mlx_put_pixel(win, i, j, color);
		while (i <= (x * 16) + 12)
		{
			mlx_put_pixel(win, i, j, color);
			i++;
		}
		j++;
	}
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
