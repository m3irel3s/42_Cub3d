/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:50:50 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/25 14:34:57 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/cub3d_bonus.h"

/**
 * @brief Moves the player forward in the game world.
 *
 * The player's position is updated by moving in the direction of their current
 * direction, scaled by the given move speed.
 *
 * @param game A pointer to the central game structure containing game state
 * and data.
 * @param move_speed The speed at which the player moves.
 */
void	ft_move_forward(t_game *game, double move_speed)
{
	ft_move_player(game,
		game->player->dir_x * move_speed,
		game->player->dir_y * move_speed);
}

/**
 * @brief Moves the player backward in the game world.
 *
 * The player's position is updated by moving in the opposite direction of
 * their current direction, scaled by the given move speed.
 *
 * @param game A pointer to the central game structure containing game
 * state and data.
 * @param move_speed The speed at which the player moves.
 */
void	ft_move_backward(t_game *game, double move_speed)
{
	ft_move_player(game,
		-game->player->dir_x * move_speed,
		-game->player->dir_y * move_speed);
}

/**
 * @brief Moves the player to the left in the game world.
 *
 * The player's position is updated by moving perpendicularly to the left
 * of their current direction, scaled by the given move speed.
 *
 * @param game A pointer to the central game structure containing game state
 *             and data.
 * @param move_speed The speed at which the player moves.
 */
void	ft_move_left(t_game *game, double move_speed)
{
	double	perp_x;
	double	perp_y;

	perp_x = -game->player->dir_y;
	perp_y = game->player->dir_x;
	ft_move_player(game,
		perp_x * move_speed,
		perp_y * move_speed);
}

/**
 * @brief Moves the player to the right in the game world.
 *
 * The player's position is updated by moving perpendicularly to the left
 * of their current direction, scaled by the given move speed.
 *
 * @param game A pointer to the central game structure containing game state
 *             and data.
 * @param move_speed The speed at which the player moves.
 */

void	ft_move_right(t_game *game, double move_speed)
{
	double	perp_x;
	double	perp_y;

	perp_x = game->player->dir_y;
	perp_y = -game->player->dir_x;
	ft_move_player(game,
		perp_x * move_speed,
		perp_y * move_speed);
}
