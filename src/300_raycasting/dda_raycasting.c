/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_raycasting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 22:13:53 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/02 10:21:40 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_perform_dda(t_game *game, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->map_x < 0 || ray->map_x >= (int)game->map->width ||
			ray->map_y < 0 || ray->map_y >= (int)game->map->height)
			break;
		if (ray->step.side_dist_x < ray->step.side_dist_y)
		{
			ray->step.side_dist_x += ray->step.delta_dist_x;
			ray->map_x += ray->step.step_x;
			ray->side = 0;
		}
		else
		{
			ray->step.side_dist_y += ray->step.delta_dist_y;
			ray->map_y += ray->step.step_y;
			ray->side = 1;
		}
		if (ray->map_x >= 0 && ray->map_x < (int)game->map->width &&
			ray->map_y >= 0 && ray->map_y < (int)game->map->height)
		{
			if (game->map->grid[ray->map_y][ray->map_x] == '1')
				ray->hit = 1;
		}
	}
}
