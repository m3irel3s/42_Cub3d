/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:09:46 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/22 16:27:45 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/**
 * @brief Checks if the player is facing a specific door.
 *
 * This function calculates the angle between the player's current direction and
 * the direction towards a given door. It determines if the player is within a
 * certain field of view (FOV) angle of the door, allowing for potential
 * interaction.
 *
 * @param game Pointer to the game structure.
 * @param door Pointer to the door data structure.
 * @return true if the player is facing the door within the FOV angle,
 * false otherwise.
 */
static bool	ft_is_facing_door(t_game *game, t_door_data *door)
{
	double	player_angle;
	double	target_angle;
	double	angle_diff;
	double	dx;
	double	dy;

	dx = door->pos.x + 0.5 - game->player->pos_x;
	dy = door->pos.y + 0.5 - game->player->pos_y;
	if (dx * dx + dy * dy > 4.0)
		return (false);
	player_angle = atan2(game->player->dir_y, game->player->dir_x);
	target_angle = atan2(dy, dx);
	angle_diff = target_angle - player_angle;
	while (angle_diff > M_PI)
		angle_diff -= 2 * M_PI;
	while (angle_diff < -M_PI)
		angle_diff += 2 * M_PI;
	return (fabs(angle_diff) <= FOV_ANGLE);
}

/**
 * @brief Updates the state of gates based on the player's position and
 * direction.
 *
 * This function loops through all gates in the game map and checks if the
 * player is facing the gate. If the player is facing the gate, the function
 * either opens or closes the gate based on its current state.
 *
 * @param game Pointer to the game structure.
 */
void	ft_handle_gate_animation(t_game *game)
{
	int				i;
	t_door_data		*door;

	i = 0;
	while (i < game->map->num_gates)
	{
		door = &game->map->gates[i];
		if (ft_is_facing_door(game, door))
		{
			if (door->state == DOOR_CLOSED)
				door->state = DOOR_OPENING;
			else if (door->state == DOOR_OPEN)
				door->state = DOOR_CLOSING;
		}
		i++;
	}
}
