/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bylkus <bylkus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:39:38 by loadjou           #+#    #+#             */
/*   Updated: 2023/04/26 00:10:02 by bylkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

uint32_t	get_px(mlx_texture_t *buff, int x, int y)
{
	return ((((uint32_t *)buff->pixels)[x + buff->width * y]));
}

/*

int	determine_wall_direction(t_cub *cub, float angle)
{
	float	diff_x;
	float	diff_y;
	float	wall_angle;
	float	diff_a;

	// Calculate the difference between the wall and player positions
	diff_x = cub->dest[X] - cub->coord[X];
	diff_y = cub->dest[Y] - cub->coord[Y];
	// Calculate the angle between the player's view direction and the wall
	wall_angle = atan2f(diff_x, diff_y);
	diff_a = (wall_angle - angle);
	printf("diff_a: %f\n", diff_a);
	// Determine the wall direction

	if (diff_a >= deg_to_rad(315) || diff_a < deg_to_rad(45))
		return (EA);
	else if (diff_a >= deg_to_rad(45) && diff_a < deg_to_rad(315))
		return (NO);
	else if (diff_a >= deg_to_rad(315) && diff_a < deg_to_rad(225))
		return (WE);
	else
		return (SO);
}
*/


#include <math.h>

#define DIRECTION_EAST 0
#define DIRECTION_NORTH 1
#define DIRECTION_WEST 2
#define DIRECTION_SOUTH 3

int determine_wall_direction(float wall_x, float wall_y, float player_x, float player_y, float player_angle) {
    // Calculate the difference between the wall and player positions
    float diff_x = wall_x - player_x;
    float diff_y = wall_y - player_y;

    // Calculate the angle between the player's view direction and the wall
    float wall_angle = atan2(diff_y, diff_x);

    // Normalize the wall angle to be in the range [0, 2*PI]
    if (wall_angle < 0) {
        wall_angle += 2*M_PI;
    }

    // Convert the wall angle to degrees
    float wall_angle_degrees = wall_angle * 180/M_PI;

    // Determine the wall direction based on the player angle and the wall angle
    float player_angle_degrees = player_angle * 180/M_PI;
    float angle_difference = wall_angle_degrees - player_angle_degrees;
    if (angle_difference < 0) {
        angle_difference += 360;
    }

    if (angle_difference >= 315 || angle_difference < 45) {
        return EA;
    } else if (angle_difference >= 45 && angle_difference < 135) {
        return NO;
    } else if (angle_difference >= 135 && angle_difference < 225) {
        return WE;
    } else {
        return SO;
    }
}



int	get_text_dir(t_cub *cub, float angle)
{
	return(determine_wall_direction(cub->dest[X], cub->dest[Y], cub->coord[X], cub->coord[Y], angle));
	// return (determine_wall_direction(cub, angle));
}

/* mlx_texture_t	*set_texture(t_cub *cub)
{
	if (get_text_dir(cub, cub->ray_a) == EA)
		return (&cub->map->east->texture);
	if (get_text_dir(cub, cub->ray_a) == NO)
		return (&cub->map->north->texture);
	if (get_text_dir(cub, cub->ray_a) == WE)
		return (&cub->map->west->texture);
	if (get_text_dir(cub, cub->ray_a) == SO)
		return (&cub->map->south->texture);
	return (NULL);
}
 */

unsigned int get_color(t_cub *cub, float angle)
{
	if(get_text_dir(cub, angle) == EA)
		return (0xaae3ec);
	if(get_text_dir(cub, angle) == NO)
		return (0x873e23);
	if(get_text_dir(cub, angle) == WE)
		return (0xFFFFFFFF);
	else
		return (0x00FFFF00);
}