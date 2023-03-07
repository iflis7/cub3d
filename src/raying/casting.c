/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loadjou <loadjou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:22:56 by loadjou           #+#    #+#             */
/*   Updated: 2023/03/06 14:05:06 by loadjou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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




/* typedef struct    s_img
{
    void        *img;
    int            *data;
    int            bpp;
    int            line_size;
    int            endian;
}                t_img;
 
typedef struct    s_game
{
    void        * mlx;
    void        *win;
    int            map[ROW][COL];
    t_img        img;
}                t_game;
 

 */

bool draw_dir_ray(t_cub *cub, float angle)
{
	// double angle = 0;
	double max_value;
	int i = 1;
	// float ray_x = 10;
	// float ray_y = 10;

	cub->ray_x = cub->player->instances[0].x;
	cub->ray_y = cub->player->instances[0].y;
	
	cub->pdx = cos(angle) * 10 - sin(angle) * 10;
	cub->pdy = sin(angle) * 10 - cos(angle) * 10;

	max_value = fmax(fabs(cub->pdx), fabs(cub->pdy));
	cub->pdx /= max_value;
	cub->pdy /= max_value;
	while(i--)
	{
		cub->ray_x += cub->pdx;		
		cub->ray_y += cub->pdy;
	}
	return true;
}

void draw_ray(t_cub *cub, int length)
{
	float angle;
	int x, y, dx, dy;

	get_p_angle(cub);
	angle = cub->p_a;
    // Convert the direction from degrees to radians
    angle = cub->p_dir;

    // Calculate the change in x and y based on the angle and length
    dx = length * cos(angle);
    dy = length * sin(angle);

    // Draw the line
	x = cub->p_x;
	y = cub->p_y;
    while (length > 0)
	{
		mlx_put_pixel(cub->win, x, y, get_rgba(255, 0, 0, 255));
        x += dx;
        y += dy;
        length--;
    }
	// while(angle < PI / 6)
	// {
	// 	draw_dir_ray(cub, angle);
	// 	draw_dir_ray(cub, -angle);
	// 	angle += PI/72;
	// }
	mlx_put_string(cub->mlx, ".", cub->player->instances[0].x, cub->player->instances[0].y);
}

