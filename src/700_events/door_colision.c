/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_colision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:23:37 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/14 17:27:06 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	ft_find_gate_index(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < game->map->num_gates)
	{
		if (game->map->gates[i].pos.x == x && game->map->gates[i].pos.y == y)
			return (i);
		i++;
	}
	return (-1);
}

bool	ft_handle_door_collision(t_game *game, double new_x, double new_y)
{
	int		map_x;
	int		map_y;
	int		gate_index;

	map_x = (int)new_x;
	map_y = (int)new_y;
	if (map_y < 0 || map_y >= game->map->height || map_x < 0
		|| map_x >= (int)ft_strlen(game->map->grid[map_y]))
		return (false);
	if (game->map->grid[map_y][map_x] == 'D')
	{
		gate_index = ft_find_gate_index(game, map_x, map_y);
		if (gate_index != -1 && game->map->gates[gate_index].state != DOOR_OPEN)
			return (true);
	}
	return (false);
}
