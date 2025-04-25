/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:35:42 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/23 15:53:10 by jmeirele         ###   ########.fr       */
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
	ft_cleanup(game, QUIT_GAME_MSG, 0, EXIT_SUCCESS);
	return (0);
}
