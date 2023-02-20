#include "../../include/cub3d.h"

void	print_mini_map(t_cub *cub)
{
	t_mini_m	*mini_m;
	int			i;
	int			j;
	int			dep;

	// dep = ((cub->mlx->width / 16 / 2) - (cub->map->max_line_len) / 2);
	dep = 0;
	mini_m = cub->map->mini_m;
	// j = (cub->mlx->height / 16) - cub->map->nb_lines;
	j= 0;
	while (mini_m)
	{
		i = 0;
		while (mini_m->line[i])
		{
			if (mini_m->line[i] == '1')
				print_square(cub, i + dep, j, 0);
			else if (mini_m->line[i] != '\n')
				print_square(cub, i + dep, j, get_rgba(155, 055, 55, 255));
			i++;
		}
		mini_m = mini_m->next;
		j++;
        
	}
}


