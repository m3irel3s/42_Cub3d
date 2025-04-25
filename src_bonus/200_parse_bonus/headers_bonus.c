/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:11:35 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/25 14:34:57 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/cub3d_bonus.h"

static t_headers	*ft_headers(t_game *game);
static void			ft_parse_header_line(t_headers *headers, char *line);

/**
 * @brief Parses the headers from the .cub file and stores
 * them in the game structure.
 *
 * This function initializes the headers, checks and sets their tags, validates
 * their values, processes color headers for floor and ceiling, and verifies
 * texture headers. It ensures that the headers are correctly parsed and set
 * within the game structure.
 *
 * @param game A pointer to the central game structure containing game state
 *             and data.
 */
void	ft_parse_headers(t_game *game)
{
	t_headers	*headers;

	game->headers = ft_headers(game);
	headers = game->headers;
	ft_check_and_set_headers_tags(game, headers);
	ft_check_headers_values(game, headers);
	ft_check_and_set_headers_colors(game, headers);
	ft_check_headers_textures(game, headers);
}

/**
 * @brief Allocates and populates the headers array from the .cub file's lines.
 *
 * This function allocates memory for the headers array, counts the number of
 * valid lines above the map, and parses each line to set the header's tag and
 * value. It handles empty lines and ensures there are exactly 6 headers.
 *
 * @param game A pointer to the central game structure containing game state
 *             and data.
 *
 * @return A pointer to the newly created headers array.
 */
static t_headers	*ft_headers(t_game *game)
{
	int			i;
	int			k;
	int			headers_size;
	t_headers	*headers;

	i = 0;
	k = 0;
	headers_size = ft_count_headers(game);
	if (headers_size != 6)
		ft_cleanup(game, FOUND_INVALID_N_HEADERS, 2, EXIT_FAILURE);
	headers = ft_safe_malloc(sizeof(t_headers) * (headers_size + 1));
	while (i < game->map->grid_start_index)
	{
		if (ft_is_empty_line(game->cub_file[i]) == SUCCESS)
		{
			i++;
			continue ;
		}
		ft_parse_header_line(&headers[k], game->cub_file[i]);
		k++;
		i++;
	}
	headers[k].tag_name = NULL;
	headers[k].value = NULL;
	return (headers);
}

/**
 * @brief Parses a single line of the .cub file and sets the tag_name and value
 *        fields of a t_headers struct.
 *
 * This function takes a string line from the .cub file and a pointer to a
 * t_headers structure. It extracts the tag name and value from the line,
 * using space as a delimiter, and sets the tag_name and value fields of the
 * t_headers structure to the extracted values. It ignores empty lines and
 * lines with leading spaces.
 *
 * @param headers A pointer to the t_headers structure to be populated.
 * @param line The string line from the .cub file to be parsed.
 */
static void	ft_parse_header_line(t_headers *headers, char *line)
{
	int	j;
	int	z;

	j = 0;
	while (line[j] && !ft_is_space(line[j]))
		j++;
	headers->tag_name = ft_substr(line, 0, j);
	while (line[j] == ' ')
		j++;
	z = j;
	while (line[j])
		j++;
	headers->value = ft_substr(line, z, j - z);
}
