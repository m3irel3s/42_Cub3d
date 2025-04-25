/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_grid_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:37:57 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/25 14:34:57 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/cub3d_bonus.h"

static void	ft_extract_map(t_game *game);
static void	ft_find_holes(t_game *game);
static void	ft_get_map_width(t_game *game);

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
	ft_get_map_width(game);
}

/**
 * @brief Calculates and sets the map width based on the grid.
 *
 * This function iterates through each line of the map grid to determine
 * the maximum row width. It updates the map's width with this maximum value.
 *
 * @param game A pointer to the central game structure containing game state
 *             and data.
 */
static void	ft_get_map_width(t_game *game)
{
	int	i;
	int	max_width;
	int	row_width;

	i = 0;
	max_width = 0;
	while (game->map->grid[i])
	{
		row_width = ft_strlen(game->map->grid[i]);
		if (row_width > max_width)
			max_width = row_width;
		i++;
	}
	game->map->width = max_width;
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
				ft_cleanup(game, FOUND_EMPTY_LINE_INSI_MAP, 2, EXIT_FAILURE);
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
