/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:07:22 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/25 14:14:37 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

static void	ft_set_n_or_s_values(t_game *game, char dir);
static void	ft_set_e_or_w_values(t_game *game, char dir);

/**
 * @brief Initializes the player's position and direction from the map.
 *
 * Checks the character that represents the player's position in the map and
 * sets the player's direction and position accordingly.
 *
 * @param game A pointer to the central game structure containing game state
 *             and data.
 */
void	ft_init_player(t_game *game)
{
	char	dir;

	dir = game->map->s_dir;
	if (dir == 'N' || dir == 'S')
		ft_set_n_or_s_values(game, dir);
	else if (dir == 'W' || dir == 'E')
		ft_set_e_or_w_values(game, dir);
	game->player->pos_x = (double)game->map->s_pos.x + 0.5;
	game->player->pos_y = (double)game->map->s_pos.y + 0.5;
	game->player->look_offset = 0;
	return ;
}

/**
 * @brief Sets the player's direction and plane when facing North or South.
 *
 * Based on the given direction character, sets the player's direction and plane
 * vectors accordingly.
 *
 * @param game A pointer to the central game structure containing game state
 *             and data.
 * @param dir The character representing the player's direction: 'N' or 'S'.
 */
static void	ft_set_n_or_s_values(t_game *game, char dir)
{
	if (dir == 'N')
	{
		game->player->dir_x = 0;
		game->player->dir_y = -1;
		game->player->plane_x = FOV;
		game->player->plane_y = 0;
	}
	else if (dir == 'S')
	{
		game->player->dir_x = 0;
		game->player->dir_y = 1;
		game->player->plane_x = -FOV;
		game->player->plane_y = 0;
	}
}

/**
 * @brief Sets the player's direction and plane when facing East or West.
 *
 * Based on the given direction character, sets the player's direction and plane
 * vectors accordingly.
 *
 * @param game A pointer to the central game structure containing game state
 *             and data.
 * @param dir The character representing the player's direction: 'E' or 'W'.
 */
static void	ft_set_e_or_w_values(t_game *game, char dir)
{
	if (dir == 'E')
	{
		game->player->dir_x = 1;
		game->player->dir_y = 0;
		game->player->plane_x = 0;
		game->player->plane_y = FOV;
	}
	else if (dir == 'W')
	{
		game->player->dir_x = -1;
		game->player->dir_y = 0;
		game->player->plane_x = 0;
		game->player->plane_y = -FOV;
	}
}
