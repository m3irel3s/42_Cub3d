/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:42:48 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/23 15:59:36 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * @brief Checks if a character is a valid map character.
 *
 * This function checks whether a given character is one of the valid characters
 * allowed in the map grid, which includes '0', '1', 'N', 'S', 'E', 'W'. It
 * returns a non-zero value if the character is valid, and zero otherwise.
 *
 * @param c The character to be checked.
 * @return Non-zero if the character is valid, zero otherwise.
 */
int	ft_check_valid_map_chars(char c)
{
	int		i;
	char	*valid_chars;

	i = 0;
	valid_chars = "01NSEWD";
	while (valid_chars[i])
	{
		if (valid_chars[i] == c)
			return (SUCCESS);
		i++;
	}
	return (FAILURE);
}

/**
 * @brief Finds the index of the first line of the map in the cub file.
 *
 * This function iterates through the lines of the cub file and checks if each
 * line is empty or contains valid map characters. If a line is empty or contains
 * invalid characters, the function continues to the next line. If the line
 * contains valid map characters and is not empty, it returns the current index;
 * otherwise, it returns ERROR.
 *
 * @param game A pointer to the central game structure containing game state
 *             and data.
 * @return The index of the first line of the map in the cub file, or ERROR if
 *         the map is empty or invalid.
 */
int	ft_get_grid_start_index(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->cub_file[i])
	{
		j = 0;
		while (game->cub_file[i][j] && ft_strchr(" ", game->cub_file[i][j]))
			j++;
		while (game->cub_file[i][j] && ft_strchr("10NSWED ",
				game->cub_file[i][j]))
		{
			if (game->cub_file[i][j + 1] == '\0'
				|| game->cub_file[i][j + 1] == '\r'
				|| game->cub_file[i][j + 1] == '\n')
				return (i);
			j++;
		}
		i++;
	}
	return (ERROR);
}

/**
 * @brief Finds the last index of the map grid in the cub file.
 *
 * This function finds the last index of the map grid in the cub file by
 * iterating through the lines of the file and checking if each line is empty
 * or contains valid map characters. If a line is empty or contains invalid
 * characters, the function returns the current index; otherwise, it continues
 * to the next line. If the end of the file is reached, the function returns
 * the last index of the file.
 *
 * @param game A pointer to the central game structure containing game state
 *             and data.
 * @return The last index of the map grid in the cub file.
 */
int	ft_get_grid_last_index(t_game *game)
{
	int	i;
	int	j;

	i = game->map->grid_start_index;
	while (game->cub_file[i])
	{
		j = 0;
		if (!ft_strchr("10NSWED ", game->cub_file[i][j]))
			return (i);
		while (game->cub_file[i][j] &&
				ft_strchr("10NSWED ", game->cub_file[i][j]))
			j++;
		i++;
	}
	return (i);
}

/**
 * @brief Checks if a string is empty.
 *
 * This function takes a string as input and checks if it is empty.
 * If the string is empty or NULL, the function returns SUCCESS; otherwise,
 * it returns FAILURE.
 *
 * @param str The string to check.
 * @return SUCCESS if the string is empty, FAILURE otherwise.
 */
int	ft_is_empty_line(char *str)
{
	if (!str)
		return (SUCCESS);
	return (FAILURE);
}

/**
 * @brief Counts the number of occurrences of a character in a string.
 *
 * This function takes a string and a character as input and counts the number
 * of occurrences of the character in the string. If the string is empty or
 * NULL, the function returns ERROR.
 *
 * @param str The string to count occurrences in.
 * @param c The character to count.
 * @return The number of occurrences of the character in the string.
 */
int	ft_count_occurs(char *str, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (!str)
		return (ERROR);
	while (str[i])
	{
		if (str[i] == c)
			counter++;
		i++;
	}
	return (counter);
}
