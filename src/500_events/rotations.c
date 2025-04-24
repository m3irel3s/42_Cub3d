/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:00:00 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/24 11:43:24 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * @brief Rotate the player's direction and plane to the right.
 *
 * Rotate the player's direction and plane to the right using the given rotation
 * speed.
 *
 * @param game The game structure containing the player's data.
 * @param rot_speed The rotation speed.
 */
void	ft_rotate_right(t_game *game, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player->dir_x;
	game->player->dir_x = game->player->dir_x * cos(rot_speed)
		- game->player->dir_y * sin(rot_speed);
	game->player->dir_y = old_dir_x * sin(rot_speed)
		+ game->player->dir_y * cos(rot_speed);
	old_plane_x = game->player->plane_x;
	game->player->plane_x = game->player->plane_x * cos(rot_speed)
		- game->player->plane_y * sin(rot_speed);
	game->player->plane_y = old_plane_x * sin(rot_speed)
		+ game->player->plane_y * cos(rot_speed);
}

/**
 * @brief Rotate the player's direction and plane to the left.
 *
 * Rotate the player's direction and plane to the left using the given rotation
 * speed.
 *
 * @param game The game structure containing the player's data.
 * @param rot_speed The rotation speed.
 */
void	ft_rotate_left(t_game *game, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player->dir_x;
	game->player->dir_x = game->player->dir_x * cos(-rot_speed)
		- game->player->dir_y * sin(-rot_speed);
	game->player->dir_y = old_dir_x * sin(-rot_speed)
		+ game->player->dir_y * cos(-rot_speed);
	old_plane_x = game->player->plane_x;
	game->player->plane_x = game->player->plane_x * cos(-rot_speed)
		- game->player->plane_y * sin(-rot_speed);
	game->player->plane_y = old_plane_x * sin(-rot_speed)
		+ game->player->plane_y * cos(-rot_speed);
}
