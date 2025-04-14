/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:33:47 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/14 17:16:21 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_init_gates(t_game *game)
{
	int	i;
	int	j;
	int	index;
	int	door_count;

	i = 0;
	j = 0;
	door_count = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < (int)ft_strlen(game->map->grid[i]))
		{
			if (game->map->grid[i][j] == 'D')
				door_count++;
			j++;
		}
		i++;
	}
	game->map->num_gates = door_count;
	game->map->gates = ft_safe_malloc(sizeof(t_door_data) * door_count);
	if (!game->map->gates)
		ft_cleanup(game, "Memory allocation failed", 1);
	i = 0;
	j = 0;
	index = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < (int)ft_strlen(game->map->grid[i]))
		{
			if (game->map->grid[i][j] == 'D')
			{
				game->map->gates[index].pos.x = j;
				game->map->gates[index].pos.y = i;
				game->map->gates[index].state = DOOR_CLOSED;
				game->map->gates[index].frame = 0;
				game->map->gates[index].frame_count = 0;
				index++;
			}
			j++;
		}
		i++;
	}
}
