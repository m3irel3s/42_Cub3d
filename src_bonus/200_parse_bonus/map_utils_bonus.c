/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:58:08 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/25 14:14:37 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

static int	ft_valid_map_line(t_game *game, char *line);
static int	ft_are_valid_map_chars(char c);

/**
 * @brief Finds the player's initial position and direction from the map grid.
 *
 * This function iterates through the map grid and finds the first occurrence of
 * a player character ('N', 'S', 'E', or 'W'). It then sets the player position
 * and direction in the game structure.
 *
 * @param game The game structure containing the game state and data.
 */
void	ft_set_player_values(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (game->map->grid[i][j])
		{
			if (ft_strchr("NSWE", game->map->grid[i][j]))
			{
				game->map->s_pos.x = j;
				game->map->s_pos.y = i;
				game->map->flood_fill_pos.x = i;
				game->map->flood_fill_pos.y = j;
				game->map->s_dir = game->map->grid[i][j];
			}
			j++;
		}
		i++;
	}
}

/**
 * @brief Validates the characters used in the map grid.
 *
 * This function iterates through the map grid and checks that each line is
 * valid, and that there is exactly one player character ('N', 'S', 'E', or 'W')
 * in the map. If there is more than one player character, it triggers a cleanup
 * with an error code indicating that multiple players were found. If there is
 * no player character, it triggers a cleanup with an error code indicating
 * that no player was found.
 *
 * @param game A pointer to the central game structure containing game state
 *             and data.
 */
void	ft_validate_map_chars(t_game *game)
{
	int		counter;
	int		i;
	int		j;

	i = game->map->grid_start_index;
	while (++i < game->cub_file_size)
		ft_valid_map_line(game, game->cub_file[i]);
	i = 0;
	counter = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (game->map->grid[i][j])
		{
			if (ft_strchr("NSWE", game->map->grid[i][j]))
				counter++;
			j++;
		}
		i++;
	}
	if (counter > 1)
		ft_cleanup(game, FOUND_MORE_PLAYERS, 2, EXIT_FAILURE);
	if (counter == 0)
		ft_cleanup(game, PLAYER_NOT_FOUND, 2, EXIT_FAILURE);
}

/**
 * @brief Validates a single line of the map for correct
 * characters and formatting.
 *
 * This function checks each character in the provided map line to ensure that
 * only valid map characters ('0', '1', 'N', 'S', 'E', 'W', or
 * space) are present.
 * It flags lines containing tabs as invalid and triggers
 * cleanup. It also verifies that at least one valid character
 * is present in the line. If the line is valid, the function
 * returns SUCCESS; otherwise, it returns FAILURE.
 *
 * @param game Pointer to the game structure containing the game state.
 * @param line The line from the map to be validated.
 * @return SUCCESS if the line is valid, FAILURE otherwise.
 */
static int	ft_valid_map_line(t_game *game, char *line)
{
	int	i;
	int	has_valid_char;

	i = 0;
	has_valid_char = 0;
	if (!line)
		return (SUCCESS);
	while (line[i])
	{
		if (line[i] == '\t')
			ft_cleanup(game, FOUND_TAB_IN_MAP, 2, EXIT_FAILURE);
		else if (ft_is_space(line[i]))
			i++;
		else if (ft_are_valid_map_chars(line[i]))
		{
			has_valid_char = 1;
			i++;
		}
		else
			ft_cleanup(game, FOUND_INVALID_CHAR_MAP, 2, EXIT_FAILURE);
	}
	if (has_valid_char)
		return (SUCCESS);
	return (FAILURE);
}

/**
 * @brief Checks if a character is a valid map character.
 *
 * This function checks whether the given character is one of the valid
 * characters allowed in the map grid, which includes '0', '1', 'N', 'S',
 * 'E', 'W', or a space. It returns a non-zero value if the character is
 * valid, and zero otherwise.
 *
 * @param c The character to be checked.
 * @return Non-zero if the character is valid, zero otherwise.
 */
static int	ft_are_valid_map_chars(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || c == ' ' || c == 'D');
}
