/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:00:00 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/18 22:42:25 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static bool	ft_is_open_door(t_game *game, int x, int y)
{
	int	idx;

	if (game->map->grid[y][x] != 'D')
		return (false);
	idx = ft_find_gate_index(game, x, y);
	if (idx != -1 && game->map->gates[idx].state == DOOR_OPEN)
		return (true);
	return (false);
}

static bool	ft_is_blocked(t_game *game, double x, double y)
{
	int		map_x;
	int		map_y;
	char	cell;

	map_x = (int)x;
	map_y = (int)y;
	if (map_y < 0 || map_y >= game->map->height
		|| map_x < 0 || map_x >= (int)ft_strlen(game->map->grid[map_y]))
		return (true);
	cell = game->map->grid[map_y][map_x];
	if (cell == '1')
		return (true);
	if (cell == 'D' && !ft_is_open_door(game, map_x, map_y))
		return (true);
	return (false);
}

static void	ft_move_player(t_game *game, double dx, double dy)
{
	double	ox;
	double	oy;
	double	nx;
	double	ny;
	double	bx;
	double	by;

	ox = game->player->pos_x;
	oy = game->player->pos_y;
	nx = ox + dx;
	ny = oy + dy;
	if (!ft_is_blocked(game, nx, oy))
	{
		if ((int)nx != (int)ox && ft_is_open_door(game, (int)nx, (int)oy))
		{
			bx = nx + dx;
			if (!ft_is_blocked(game, bx, oy))
				game->player->pos_x = bx;
			else
				game->player->pos_x = nx;
		}
		else
			game->player->pos_x = nx;
	}
	if (!ft_is_blocked(game, game->player->pos_x, ny))
	{
		if ((int)ny != (int)oy
			&& ft_is_open_door(game, (int)game->player->pos_x, (int)ny))
		{
			by = ny + dy;
			if (!ft_is_blocked(game, game->player->pos_x, by))
				game->player->pos_y = by;
			else
				game->player->pos_y = ny;
		}
		else
			game->player->pos_y = ny;
	}
}

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
