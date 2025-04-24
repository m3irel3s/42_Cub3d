/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:26:50 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/24 17:48:09 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * @brief Attempts to move the player in the y direction by a given distance.
 *
 * If the destination is not blocked, the player is moved to the destination.
 * If the destination is blocked by a closed door, the player is moved to
 * the exact position of the door.
 *
 * @param game The game data structure.
 * @param dy The distance to move the player in the y direction.
 */
void	ft_try_move_y(t_game *game, double dy)
{
	double	ox;
	double	px;
	double	ny;
	double	by;
	bool	can_move;

	ox = game->player->pos_y;
	px = game->player->pos_x;
	ny = ox + dy;
	if (!ft_is_blocked(game, px, ny))
	{
		if ((int)ny != (int)ox && ft_is_open_door(game, (int)px, (int)ny))
		{
			by = ny + dy;
			can_move = !ft_is_blocked(game, px, by);
			if (can_move)
				game->player->pos_y = by;
			else
				game->player->pos_y = ny;
		}
		else
			game->player->pos_y = ny;
	}
}

/**
 * @brief Attempts to move the player in the x direction by a given distance.
 *
 * If the destination is not blocked, the player is moved to the destination.
 * If the destination is blocked by a closed door, the player is moved to
 * the exact position of the door.
 *
 * @param game The game data structure.
 * @param dx The distance to move the player in the x direction.
 */
void	ft_try_move_x(t_game *game, double dx)
{
	double	ox;
	double	oy;
	double	nx;
	double	bx;
	bool	can_move;

	ox = game->player->pos_x;
	oy = game->player->pos_y;
	nx = ox + dx;
	if (!ft_is_blocked(game, nx, oy))
	{
		if ((int)nx != (int)ox && ft_is_open_door(game, (int)nx, (int)oy))
		{
			bx = nx + dx;
			can_move = !ft_is_blocked(game, bx, oy);
			if (can_move)
				game->player->pos_x = bx;
			else
				game->player->pos_x = nx;
		}
		else
			game->player->pos_x = nx;
	}
}
