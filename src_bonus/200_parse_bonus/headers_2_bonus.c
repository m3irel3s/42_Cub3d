/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers_2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:35:09 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/25 14:14:37 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

static int	ft_check_single_word(char *str);

/**
 * @brief Checks and sets the tags of the headers.
 *
 * This function takes a t_headers array and iterates over its elements. It
 * checks if the tag is valid and if there are no duplicate tags. If the tag is
 * not valid or if there are duplicate tags, the function calls ft_cleanup with
 * the corresponding error message.
 *
 * @param game The game struct containing the game state.
 * @param headers The t_headers array containing the headers.
 */
void	ft_check_and_set_headers_tags(t_game *game, t_headers *headers)
{
	int		i;
	t_tag	tag;
	int		found_tags[6];

	i = -1;
	while (++i < 6)
		found_tags[i] = 0;
	i = 0;
	while (i < 6)
	{
		tag = ft_compare_tags(headers[i].tag_name);
		headers[i].tag = tag;
		if (tag == UNKNOWN)
			ft_cleanup(game, INVALID_TAG_FOUND, 2, EXIT_FAILURE);
		if (found_tags[tag] > 0)
			ft_cleanup(game, FOUND_DUPLICATE_TAG, 2, EXIT_FAILURE);
		found_tags[tag]++;
		i++;
	}
}

/**
 * @brief Checks if the value of a header is a single word.
 *
 * This function takes a t_headers array and iterates over its elements. If the
 * tag is not equal to C_TAG or F_TAG, it checks if the value is a single word.
 * If the value is not a single word, the function calls ft_cleanup with the
 * error message FOUND_INVALID_VALUE.
 *
 * @param game The game struct containing the game state.
 * @param headers The t_headers array to be checked.
 */
void	ft_check_headers_values(t_game *game, t_headers *headers)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (headers[i].tag != C_TAG && headers[i].tag != F_TAG)
		{
			if (ft_check_single_word(headers[i].value) == FAILURE)
				ft_cleanup(game, FOUND_INVALID_VALUE, 2, EXIT_FAILURE);
		}
		i++;
	}
	return ;
}

/**
 * @brief Compares a string to known header tags and returns
 * the corresponding tag enum.
 *
 * This function takes a string representation of a header tag and checks it
 * against the predefined tags ("SO", "NO", "EA", "WE", "F", "C"). If a match
 * is found, the corresponding tag enum is returned. If no match is found,
 * the function returns UNKNOWN.
 *
 * @param str The string representation of a header tag.
 * @return The corresponding t_tag enum value, or UNKNOWN if no match is found.
 */

t_tag	ft_compare_tags(char *str)
{
	if (ft_strcmp(str, "SO") == SUCCESS)
		return (SO_TAG);
	else if (ft_strcmp(str, "NO") == SUCCESS)
		return (NO_TAG);
	else if (ft_strcmp(str, "EA") == SUCCESS)
		return (EA_TAG);
	else if (ft_strcmp(str, "WE") == SUCCESS)
		return (WE_TAG);
	else if (ft_strcmp(str, "F") == SUCCESS)
		return (F_TAG);
	else if (ft_strcmp(str, "C") == SUCCESS)
		return (C_TAG);
	return (UNKNOWN);
}

/**
 * @brief Counts the number of non-empty header lines in the .cub file.
 *
 * This function iterates through the lines of the cub_file up to the start
 * index of the map grid, counting the number of non-empty lines which are
 * considered headers.
 *
 * @param game A pointer to the central game structure containing game state
 *             and data, including the cub_file and map grid information.
 * @return The total number of non-empty header lines.
 */

int	ft_count_headers(t_game *game)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (i < game->map->grid_start_index)
	{
		if (ft_is_empty_line(game->cub_file[i]) == FAILURE)
			counter++;
		i++;
	}
	return (counter);
}

/**
 * @brief Checks if a string consists of a single word without any spaces.
 *
 * This function takes a string and checks if it consists of a single word
 * without any spaces. If a space is found, the function returns FAILURE.
 * Otherwise, it returns SUCCESS.
 *
 * @param str The string to check.
 * @return SUCCESS if the string is a single word, FAILURE otherwise.
 */
static int	ft_check_single_word(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (FAILURE);
	while (str[i])
	{
		if (ft_is_space(str[i]))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
