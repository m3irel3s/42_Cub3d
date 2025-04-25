/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:00:00 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/25 14:34:57 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/cub3d_bonus.h"

/**
 * @brief Rotate the player's direction and camera plane by a signed angle.
 *
 * @param game      The game struct.
 * @param angle_rad Rotation angle in radians 
 *  (positive = right, negative = left).
 */
void	ft_rotate(t_game *game, double angle_rad)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player->dir_x;
	old_plane_x = game->player->plane_x;
	game->player->dir_x = game->player->dir_x * cos(angle_rad)
		- game->player->dir_y * sin(angle_rad);
	game->player->dir_y = old_dir_x * sin(angle_rad)
		+ game->player->dir_y * cos(angle_rad);
	game->player->plane_x = game->player->plane_x * cos(angle_rad)
		- game->player->plane_y * sin(angle_rad);
	game->player->plane_y = old_plane_x * sin(angle_rad)
		+ game->player->plane_y * cos(angle_rad);
}
