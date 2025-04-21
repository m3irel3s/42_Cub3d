/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 22:14:50 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/21 16:42:57 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include <math.h>

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

void	ft_calc_wall(t_game *game, t_ray *ray)
{
	ft_calc_wall_dist(game, ray);
	ft_calc_wall_x_side(game, ray);
}
