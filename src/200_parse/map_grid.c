/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:37:57 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/22 11:01:43 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	ft_extract_map(t_game *game);
static void	ft_find_holes(t_game *game);

/**
 * @brief Parses the map grid from the cub file and validates its structure.
 *
 * This function extracts the map grid from the cub file, detects any holes
 * or empty lines within the grid, validates the characters used in the map,
 * and sets the player's initial position and direction based on the map.
 *
 * @param game A pointer to the central game structure containing game state
 *             and data.
 */
void	ft_parse_map_grid(t_game *game)
{
	ft_extract_map(game);
	ft_find_holes(game);
	ft_validate_map_chars(game);
	ft_set_player_values(game);
}

/**
 * @brief Detects empty lines within the map grid and triggers
 * cleanup if necessary.
 *
 * This function iterates through the map grid lines in the cub file starting
 * from the grid start index. It checks for empty lines and sets a flag if any
 * are found. If non-empty lines follow an empty line, it triggers a cleanup
 * with an error indicating that an empty line was found inside the map,
 * ensuring the map's integrity.
 *
 * @param game A pointer to the central game structure containing game state
 *             and data.
 */
static void	ft_find_holes(t_game *game)
{
	int	i;
	int	found_empty;

	i = game->map->grid_start_index;
	found_empty = 0;
	while (i < game->cub_file_size)
	{
		if (ft_is_empty_line(game->cub_file[i]) == SUCCESS)
		{
			found_empty = 1;
			i++;
		}
		else if (ft_is_empty_line(game->cub_file[i]) != SUCCESS)
		{
			if (found_empty == 1)
				ft_cleanup(game, FOUND_EMPTY_LINE_INSI_MAP, 2);
			i++;
		}
	}
}

/**
 * @brief Extracts the map grid from the cub file and allocates memory for it.
 *
 * This function initializes the map height and allocates memory for the map
 * grid based on the start and end indices. It then duplicates each relevant
 * line from the cub file into the map grid.
 *
 * @param game A pointer to the central game structure containing game state
 *             and data.
 */
static void	ft_extract_map(t_game *game)
{
	int	i;
	int	l;
	int	j;

	j = 0;
	i = game->map->grid_start_index;
	l = game->map->grid_last_index;
	game->map->height = l - i;
	game->map->grid = ft_safe_malloc(sizeof(char *) * (l - i + 1));
	while (i < l)
		game->map->grid[j++] = ft_strdup(game->cub_file[i++]);
	game->map->grid[j] = NULL;
}
