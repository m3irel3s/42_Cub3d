/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:00:00 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/24 17:30:39 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	ft_move_player(t_game *game, double dx, double dy)
{
	ft_try_move_x(game, dx);
	ft_try_move_y(game, dy);
}

bool	ft_is_open_door(t_game *game, int x, int y)
{
	int	idx;

	if (game->map->grid[y][x] != 'D')
		return (false);
	idx = ft_find_gate_index(game, x, y);
	if (idx != -1 && game->map->gates[idx].state == DOOR_OPEN)
		return (true);
	return (false);
}

bool	ft_is_blocked(t_game *game, double x, double y)
{
	int		map_x;
	int		map_y;
	char	cell;

	map_x = (int)x;
	map_y = (int)y;
	if (!ft_is_valid_cell(game, map_x, map_y))
		return (true);
	cell = game->map->grid[map_y][map_x];
	if (cell == '1')
		return (true);
	if (cell == 'D' && !ft_is_open_door(game, map_x, map_y))
		return (true);
	return (false);
}

bool	ft_is_valid_cell(t_game *game, int x, int y)
{
	if (y < 0 || y >= game->map->height
		|| x < 0 || x >= (int)ft_strlen(game->map->grid[y]))
		return (false);
	return (true);
}
