/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:30:00 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/21 17:06:34 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	ft_init_step_x(t_game *game, t_ray *ray);
static void	ft_init_step_y(t_game *game, t_ray *ray);

void	ft_init_ray(t_game *game, int x, t_ray *ray)
{
	ray->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	ray->ray_dir_x = game->player->dir_x + game->player->plane_x
		* ray->camera_x;
	ray->ray_dir_y = game->player->dir_y + game->player->plane_y
		* ray->camera_x;
	ray->map_x = (int)game->player->pos_x;
	ray->map_y = (int)game->player->pos_y;
	ray->hit = 0;
	if (ray->ray_dir_x == 0)
		ray->step.delta_dist_x = 1e30;
	else
		ray->step.delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->step.delta_dist_y = 1e30;
	else
		ray->step.delta_dist_y = fabs(1 / ray->ray_dir_y);
	ft_init_step_x(game, ray);
	ft_init_step_y(game, ray);
}

static void	ft_init_step_x(t_game *game, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step.step_x = -1;
		ray->step.side_dist_x = (game->player->pos_x - ray->map_x)
			* ray->step.delta_dist_x;
	}
	else
	{
		ray->step.step_x = 1;
		ray->step.side_dist_x = (ray->map_x + 1.0 - game->player->pos_x)
			* ray->step.delta_dist_x;
	}
}

static void	ft_init_step_y(t_game *game, t_ray *ray)
{
	if (ray->ray_dir_y < 0)
	{
		ray->step.step_y = -1;
		ray->step.side_dist_y = (game->player->pos_y - ray->map_y)
			* ray->step.delta_dist_y;
	}
	else
	{
		ray->step.step_y = 1;
		ray->step.side_dist_y = (ray->map_y + 1.0 - game->player->pos_y)
			* ray->step.delta_dist_y;
	}
}
