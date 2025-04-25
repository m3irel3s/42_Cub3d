/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_gates_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:51:29 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/25 14:14:37 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

/**
 * @brief Updates the state of all gates in the game.
 * @param game The game struct with the gates data.
 *
 * This function is responsible for updating the state of the gates in the game.
 * It checks if the gate is opening or closing and updates the frame count and
 * state accordingly. If the gate is fully open, it sets the state to DOOR_OPEN.
 * If the gate is fully closed, it sets the state to DOOR_CLOSED.
 *
 * This function is called in the main game loop and is used to animate the
 * opening and closing of the gates.
 */
void	ft_update_gates(t_game *game)
{
	int			i;
	t_door_data	*door;

	i = -1;
	while (++i < game->map->num_gates)
	{
		door = &game->map->gates[i];
		if (door->state == DOOR_OPENING && ++door->frame_count >= 5)
		{
			door->frame_count = 0;
			if (++door->frame >= 7)
				door->state = DOOR_OPEN;
		}
		else if (door->state == DOOR_CLOSING && ++door->frame_count >= 5)
		{
			door->frame_count = 0;
			if (--door->frame <= 0)
				door->state = DOOR_CLOSED;
		}
	}
}
