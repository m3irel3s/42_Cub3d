/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:50:50 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/24 16:51:16 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	ft_move_forward(t_game *game, double move_speed)
{
	ft_move_player(game,
		game->player->dir_x * move_speed,
		game->player->dir_y * move_speed);
}

void	ft_move_backward(t_game *game, double move_speed)
{
	ft_move_player(game,
		-game->player->dir_x * move_speed,
		-game->player->dir_y * move_speed);
}

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
