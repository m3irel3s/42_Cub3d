/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_raycasting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 22:13:53 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/23 22:25:42 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	ft_update_ray_position(t_ray *ray);
static void	ft_check_hit(t_game *game, t_ray *ray);

/**
 * @brief Performs the DDA algorithm to find the next wall hit.
 *
 * This function updates the ray's position and checks for a hit until a wall
 * is found or the ray exits the map boundaries.
 *
 * @param game The game struct containing the game state.
 * @param ray The ray struct containing the ray data.
 */
void	ft_perform_dda(t_game *game, t_ray *ray)
{
	while (ray->hit == 0)
	{
		ft_update_ray_position(ray);
		ft_check_hit(game, ray);
	}
}

/**
 * @brief Updates the ray's position based on the smallest side distance.
 *
 * This function increments the ray's side distance by its delta distance
 * in the x or y direction, depending on which side distance is smaller.
 * It updates the map position and sets the side of the ray to either
 * 0 for x-side or 1 for y-side accordingly.
 *
 * @param ray The ray struct containing the ray data.
 */

static void	ft_update_ray_position(t_ray *ray)
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
}

/**
 * @brief Checks if the ray has hit a wall or a gate.
 *
 * This function checks if the ray has hit a wall or a gate by checking if the
 * map cell at the ray's map position is either a wall ('1') or a gate ('D').
 * If the ray has hit a wall, the ray's hit flag is set to 1. If the ray has hit
 * a gate, the ray's hit and gate flags are set to 1, and the gate index is set
 * to the index of the gate in the map's gate array.
 *
 * @param game The game struct containing the game state.
 * @param ray The ray struct containing the ray data.
 */
static void	ft_check_hit(t_game *game, t_ray *ray)
{
	int	i;

	if (game->map->grid[(int)game->player->pos_y]
		[(int)game->player->pos_x] == '1'
		|| game->map->grid[ray->map_y][ray->map_x] == '1'
		|| ray->map_y < 0 || ray->map_y >= game->map->height
		|| ray->map_x < 0
		|| ray->map_x >= (int)ft_strlen(game->map->grid[ray->map_y]))
		ray->hit = 1;
	else if (game->map->grid[ray->map_y][ray->map_x] == 'D')
	{
		ray->hit = 1;
		ray->gate = 1;
		i = 0;
		while (i < game->map->num_gates)
		{
			if (game->map->gates[i].pos.x == ray->map_x
				&& game->map->gates[i].pos.y == ray->map_y)
			{
				ray->gate_index = i;
				break ;
			}
			i++;
		}
	}
}
