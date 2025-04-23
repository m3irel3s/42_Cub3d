/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:38:45 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/23 16:28:33 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * @brief Set the floor and ceiling colors in hexadecimal format.
 *
 * This function converts the rgb struct values to hexadecimal format.
 *
 * @param game The game struct containing the game state.
 */
void	ft_set_floor_n_ceiling(t_game *game)
{
	t_rgb	f;

	f = game->floor_color;
	game->floor_color_hex = ft_rgb_to_hex(f.r, f.g, f.b);
	f = game->ceiling_color;
	game->ceiling_color_hex = ft_rgb_to_hex(f.r, f.g, f.b);
}
