/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bylkus <bylkus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:22:56 by loadjou           #+#    #+#             */
/*   Updated: 2023/03/09 15:11:07 by bylkus           ###   ########.fr       */
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


void cast_ray(t_cub *cub)
{
	float len;
	int i = 0;
	float px = cub->player->instances[0].x + cub->map->sq_size / 8;
	float py = cub->player->instances[0].y + cub->map->sq_size / 8;
	cub->ray_x =  px;
	cub->ray_y =  py ;
	len = sqrtf(cub->ray_x * cub->ray_x + cub->ray_y * cub->ray_y);
	cub->ray_x = px * cos(cub->p_a * M_PI / 180);
	cub->ray_y = py * -sin(cub->p_a * M_PI / 180);
	cub->ray_y /= len;
	cub->ray_x /= len;
	
	while (i < WIDTH)
	{
		float t = (float)i / WIDTH;
		int x = px + t * cub->ray_x * len ;
		int y = py + t * cub->ray_y * len ;
		if(x > cub->map->max_line_len * 64 || x <= 0 || y > cub->map->nb_lines * 64 || y <= 0 || is_wall(cub, x, y))
			break;
		mlx_put_pixel(cub->win, x, y, get_rgba(255, 255, 255, 1));
		i++;
	}
}

void	draw_fov(t_cub *cub)
{
    int num_rays = 60;
    cub->fov = 60 * M_PI / 180;
    float ray_spacing = cub->fov / num_rays;
    float dir_x, dir_y;
    float len;
    int x, y, i;
	
    i = 0;
    while (i < num_rays)
    {
        cub->ray_a = cub->p_a - cub->fov / 2 + i * ray_spacing;
        dir_x = cos(cub->ray_a);
        dir_y = sin(cub->ray_a);
        len = 0;
        while (len < WIDTH)
        {
            x = cub->player->instances[0].x + len * dir_x;
            y = cub->player->instances[0].y + len * dir_y;
            if (x < 0 || x >= cub->map->max_line_len || y < 0 || y >= cub->map->nb_lines)
                break;
            if (cub->map->map[y][x] == '1')
                break;
            mlx_put_pixel(cub->win, (uint32_t)x, (uint32_t)y, get_rgba(255, 255, 71, 1));
            len += 1;
        }
        i++;
    }
}
/* 
int main()
{
    double player_angle = 0;
    double ray_angle;
    double fov = FOV_ANGLE * M_PI / 180;
    double ray_spacing = fov / NUM_RAYS;
    double dir_x, dir_y;
    double length;
    int x, y;

    for (int i = 0; i < NUM_RAYS; i++)
    {
        ray_angle = player_angle - fov / 2 + i * ray_spacing;
        dir_x = cos(ray_angle);
        dir_y = sin(ray_angle);
        length = 0;

        while (length < WIDTH)
        {
            x = player_x + length * dir_x;
            y = player_y + length * dir_y;
            mlx_pixel_put(mlx, win, x, y, 0xffffff);
            length += 1;
        }
	}
} */
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
