/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_colision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:23:37 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/22 16:28:13 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/**
 * @brief Finds the index of the gate at the given position in the map.
 *
 * Iterates through the array of gates in the game map and checks if the
 * position of each gate matches the given position. If a match is found, the
 * index of the gate is returned; otherwise, -1 is returned to indicate that
 * no gate was found at the given position.
 *
 * @param game Pointer to the game structure.
 * @param x The x-coordinate of the position to search for.
 * @param y The y-coordinate of the position to search for.
 * @return The index of the gate at the given position, or -1 if no gate was
 * found.
 */
int	ft_find_gate_index(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < game->map->num_gates)
	{
		if (game->map->gates[i].pos.x == x && game->map->gates[i].pos.y == y)
			return (i);
		i++;
	}
	return (-1);
}

/**
 * @brief Checks for a collision with a door at the specified new position.
 *
 * This function determines if a move to a new position in the game would result
 * in a collision with a door that is not open. It first checks if the new
 * position is within the map boundaries, then verifies if the cell contains a
 * door ('D'). If so, it finds the index of the door and checks its state.
 * Returns true if the door is not open, indicating a collision, otherwise false.
 *
 * @param game Pointer to the game structure.
 * @param new_x The new x-coordinate to check.
 * @param new_y The new y-coordinate to check.
 * @return True if the move would result in a collision with a closed door,
 * otherwise false.
 */
bool	ft_handle_door_collision(t_game *game, double new_x, double new_y)
{
	int		map_x;
	int		map_y;
	int		gate_index;

	map_x = (int)new_x;
	map_y = (int)new_y;
	if (map_y < 0 || map_y >= game->map->height || map_x < 0
		|| map_x >= (int)ft_strlen(game->map->grid[map_y]))
		return (false);
	if (game->map->grid[map_y][map_x] == 'D')
	{
		gate_index = ft_find_gate_index(game, map_x, map_y);
		if (gate_index != -1 && game->map->gates[gate_index].state != DOOR_OPEN)
			return (true);
	}
	return (false);
}
