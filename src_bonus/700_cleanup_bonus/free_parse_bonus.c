/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parse_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:18:14 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/25 14:34:57 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/cub3d_bonus.h"

static void	ft_free_headers(t_game *game);
static void	ft_free_cub_file_and_grid(t_game *game);

/**
 * @brief Frees the memory allocated for the parsed .cub file and its headers.
 *
 * This function takes a pointer to the game structure and frees the memory
 * allocated for the .cub file, its headers, and the map grid.
 *
 * @param game A pointer to the game structure.
 */
void	ft_free_parse(t_game *game)
{
	ft_free_headers(game);
	ft_free_cub_file_and_grid(game);
}

/**
 * @brief Frees the memory allocated for the cub_file and map grid in the game
 * structure.
 *
 * This function iterates over the cub_file array, freeing each line, and then
 * frees the array itself. It also iterates over the map grid, freeing each line,
 * and finally frees the grid, setting the pointer to NULL to prevent dangling
 * references.
 *
 * @param game A pointer to the game structure containing the cub_file and map
 * grid.
 */
static void	ft_free_cub_file_and_grid(t_game *game)
{
	int	i;

	i = -1;
	if (game->cub_file)
	{
		while (++i < game->cub_file_size)
			ft_free(game->cub_file[i]);
		ft_free(game->cub_file);
	}
	i = 0;
	if (game->map->grid)
	{
		while (game->map->grid[i])
			ft_free(game->map->grid[i++]);
		ft_free(game->map->grid);
		game->map->grid = NULL;
	}
}

/**
 * @brief Frees the memory allocated for the headers in the game structure.
 *
 * This function takes a pointer to the game structure and frees the memory
 * allocated for the headers array, iterating over each header and freeing its
 * tag name and value before freeing the header itself.
 *
 * @param game A pointer to the game structure containing the headers array.
 */
static void	ft_free_headers(t_game *game)
{
	int	i;

	i = -1;
	if (game->headers)
	{
		while (++i < 6)
		{
			ft_free(game->headers[i].tag_name);
			ft_free(game->headers[i].value);
		}
		ft_free(game->headers);
	}
}
