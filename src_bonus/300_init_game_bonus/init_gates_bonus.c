/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gates_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:33:47 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/25 14:14:37 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

/**
 * @brief Counts the number of doors ('D') in the map.
 *
 * @param game Pointer to the game structure.
 * @return The number of doors found.
 */
static int	ft_count_doors(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < (int)ft_strlen(game->map->grid[i]))
		{
			if (game->map->grid[i][j] == 'D')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

/**
 * @brief Initializes each door's position and default state.
 * @param game Pointer to the game structure.
 */
static void	ft_setup_doors(t_game *game)
{
	int	i;
	int	j;
	int	index;

	i = 0;
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

/**
 * @brief Initializes all doors ('D') in the map, allocating memory and
 *        storing their position/state.
 * @param game Pointer to the t_game struct with the map loaded.
 */
void	ft_init_gates(t_game *game)
{
	game->map->num_gates = ft_count_doors(game);
	game->map->gates = ft_safe_malloc(sizeof(t_door_data)
			* game->map->num_gates);
	if (!game->map->gates)
		ft_cleanup(game, MALLOC_FAILED, 2, EXIT_FAILURE);
	ft_setup_doors(game);
}
