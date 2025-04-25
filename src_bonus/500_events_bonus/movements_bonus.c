/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:00:00 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/25 14:34:57 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/cub3d_bonus.h"

/**
 * @brief Moves the player in the game world.
 *
 * The player's position is updated according to the given delta x and y
 * values. The player's movement is split into two separate operations:
 * horizontal movement (ft_try_move_x) and vertical movement (ft_try_move_y).
 *
 * @param game A pointer to the central game structure containing game
 * state and data.
 * @param dx The change in x position of the player.
 * @param dy The change in y position of the player.
 */
void	ft_move_player(t_game *game, double dx, double dy)
{
	ft_try_move_x(game, dx);
	ft_try_move_y(game, dy);
}

/**
 * @brief Checks if a door is open at a given position in the game world.
 *
 * Checks if the cell at the given position is a door ('D'). If it is, finds the
 * index of the door in the map's gate array and checks if its state is
 * DOOR_OPEN. If the door is open, the function returns true; otherwise, it
 * returns false.
 *
 * @param game A pointer to the central game structure containing game
 * state and data.
 * @param x The x-coordinate of the position to check.
 * @param y The y-coordinate of the position to check.
 * @return true if the door is open, false otherwise.
 */
bool	ft_is_open_door(t_game *game, int x, int y)
{
	int	idx;

	if (game->map->grid[y][x] != 'D')
		return (false);
	idx = ft_find_gate_index(game, x, y);
	if (idx != -1 && game->map->gates[idx].state == DOOR_OPEN)
		return (true);
	return (false);
}

/**
 * @brief Checks if a given position is blocked by a wall or a closed door.
 *
 * Checks if the cell at the given position is a wall ('1') or a closed door.
 * If either of these conditions is true, the function returns true to indicate
 * that the position is blocked; otherwise, it returns false.
 *
 * @param game A pointer to the central game structure containing
 * game state and data.
 * @param x The x-coordinate of the position to check.
 * @param y The y-coordinate of the position to check.
 * @return true if the position is blocked, false otherwise.
 */
bool	ft_is_blocked(t_game *game, double x, double y)
{
	int		map_x;
	int		map_y;
	char	cell;

	map_x = (int)x;
	map_y = (int)y;
	if (!ft_is_valid_cell(game, map_x, map_y))
		return (true);
	cell = game->map->grid[map_y][map_x];
	if (cell == '1')
		return (true);
	if (cell == 'D' && !ft_is_open_door(game, map_x, map_y))
		return (true);
	return (false);
}

/**
 * @brief Checks if a given position is within the bounds of the game world.
 *
 * Checks if the given x and y coordinates are within the bounds of the game
 * world. If the coordinates are within the bounds of the game world, the
 * function returns true; otherwise, it returns false.
 *
 * @param game A pointer to the central game structure containing game
 * state and data.
 * @param x The x-coordinate of the position to check.
 * @param y The y-coordinate of the position to check.
 * @return true if the position is within the bounds of the game world,
 * false otherwise.
 */
bool	ft_is_valid_cell(t_game *game, int x, int y)
{
	if (y < 0 || y >= game->map->height
		|| x < 0 || x >= (int)ft_strlen(game->map->grid[y]))
		return (false);
	return (true);
}
