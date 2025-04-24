/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:26:50 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/24 17:29:24 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

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
