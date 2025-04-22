/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:35:42 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/22 11:06:12 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * @brief Cleans up game resources and exits the game gracefully.
 *
 * This function is responsible for cleaning up all allocated resources
 * associated with the game and exiting the game with a message indicating
 * that the game is quitting. It is typically called when the player chooses
 * to quit the game.
 *
 * @param game A pointer to the game struct containing all game-related data.
 *
 * @return Always returns 0 to indicate successful execution.
 */

int	ft_quit_game(t_game *game)
{
	ft_cleanup(game, QUIT_GAME_MSG, 0);
	return (0);
}
