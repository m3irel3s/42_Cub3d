/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_raycasting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 22:13:53 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/22 11:56:34 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * @brief Perform the Digital Differential Analyzer (DDA) raycasting algorithm.
 * @param game The game data structure.
 * @param ray The ray data structure containing the ray direction, side
 *            distance, delta distance, step, and wall hit information.
 *
 * This function performs the DDA algorithm to determine when a ray hits a wall.
 * It iterates through the map, checking if the ray has hit a wall or if the ray
 * is outside the map. When a wall is hit or the ray is outside the map, the
 * function sets the ray->hit variable to 1 and breaks out of the loop.
 */
void	ft_perform_dda(t_game *game, t_ray *ray)
{
	int	i;

	while (ray->hit == 0)
	{
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
		if (game->map->grid[(int)game->player->pos_y]
			[(int)game->player->pos_x] == '1'
			|| game->map->grid[ray->map_y][ray->map_x] == '1'
			|| ray->map_y < 0 || ray->map_y >= game->map->height
			|| ray->map_x < 0
			|| ray->map_x >= (int)ft_strlen(game->map->grid[ray->map_y]))
		{
			ray->hit = 1;
			break ;
		}
		else if (game->map->grid[ray->map_y][ray->map_x] == 'D')
		{
			ray->hit = 1;
			ray->gate = 1;
			i = 0;
			while (i < game->map->num_gates)
			{
				if (game->map->gates[i].pos.x == ray->map_x &&
					game->map->gates[i].pos.y == ray->map_y)
				{
					ray->gate_index = i;
					break;
				}
				i++;
			}
		}
	}
}

