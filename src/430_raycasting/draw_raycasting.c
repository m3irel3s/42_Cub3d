/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 22:14:50 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/24 11:18:02 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * @brief Calculates the perpendicular wall distance from the ray.
 * @param game The game data structure.
 * @param ray The ray data structure containing the ray direction
 * and map position.
 *
 * This function calculates the perpendicular wall distance
 * from the ray. It first calculates the perpendicular wall
 * distance in the x or y direction, depending on which side the
 * ray hit. Then, it calculates the line height and draw start
 * and end positions. The draw start and end positions are adjusted to be within
 * the screen height.
 */
static void	ft_calc_wall_dist(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - game->player->pos_x
				+ (1 - ray->step.step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - game->player->pos_y
				+ (1 - ray->step.step_y) / 2) / ray->ray_dir_y;
	ray->line_height = (int)(SCREEN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + SCREEN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + SCREEN_HEIGHT / 2;
	if (ray->draw_end >= SCREEN_HEIGHT)
		ray->draw_end = SCREEN_HEIGHT - 1;
}


/**
 * @brief Calculates the wall x side from the ray.
 * @param game The game data structure.
 * @param ray The ray data structure containing the ray
 * direction and map position.
 *
 * This function calculates the wall x side from the ray. It first calculates the
 * wall x side by adding the perpendicular wall distance to the player's x or y
 * position, depending on which side the ray hit. It then subtracts the floor of
 * the wall x side to get the wall x side. Finally, it sets the wall side of the
 * ray to either EAST, WEST, NORTH, or SOUTH, depending on the ray direction.
 */
static void	ft_calc_wall_x_side(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_x = game->player->pos_y
			+ ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = game->player->pos_x
			+ ray->perp_wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			ray->wall_side = EAST;
		else
			ray->wall_side = WEST;
	}
	else
	{
		if (ray->ray_dir_y <= 0)
			ray->wall_side = NORTH;
		else
			ray->wall_side = SOUTH;
	}
}

/**
 * @brief Calculates the wall data from the ray.
 * @param game The game data structure.
 * @param ray The ray data structure containing the ray
 * direction and map position.
 *
 * This function calculates the wall data from the ray. It first calculates the
 * perpendicular wall distance and line height, then calculates the wall x side.
 */
void	ft_calc_wall(t_game *game, t_ray *ray)
{
	ft_calc_wall_dist(game, ray);
	ft_calc_wall_x_side(game, ray);
}
