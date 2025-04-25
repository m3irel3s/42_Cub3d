/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closure_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:40:55 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/25 14:34:57 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/cub3d_bonus.h"

static char	**ft_dup_grid(t_game *game);
static void	ft_flood_fill(t_game *game, char **dup_grid, int x, int y);

/**
 * @brief Checks if the map is closed by performing a flood
 * fill from the player position.
 *
 * This function creates a duplicate of the map grid and then performs a flood
 * fill from the player position. It checks if the '0' characters are all
 * replaced with '+', and if any ' ' characters are found, it means the map is
 * not closed and the program will exit with an error message.
 */
void	ft_check_map_closure(t_game *game)
{
	int		x;
	int		y;
	char	**dup_grid;

	x = game->map->flood_fill_pos.x;
	y = game->map->flood_fill_pos.y;
	dup_grid = NULL;
	dup_grid = ft_dup_grid(game);
	ft_flood_fill(game, dup_grid, x, y);
	ft_free_arr(dup_grid);
}

/**
 * @brief Recursively performs a flood fill on the duplicate grid.
 *
 * This function checks the current position on the duplicate grid and
 * performs a flood fill to mark open areas. If it encounters an unclosed map
 * or space inside the map, it triggers cleanup with an error message. The
 * flood fill is conducted by recursively moving in all four directions
 * (left, right, up, down) from the current position.
 *
 * @param game The game structure containing the game state.
 * @param dup_grid The duplicate map grid used for flood fill operations.
 * @param x The x-coordinate of the current position.
 * @param y The y-coordinate of the current position.
 */
static void	ft_flood_fill(t_game *game, char **dup_grid, int x, int y)
{
	if (!dup_grid[x][y] || dup_grid[x][y] == '#')
	{
		ft_free_arr(dup_grid);
		ft_cleanup(game, FOUND_UNCLOSED_MAP, 2, EXIT_FAILURE);
	}
	if (dup_grid[x][y] == '1' || dup_grid[x][y] == '+')
		return ;
	if (dup_grid[x][y] == ' ')
	{
		ft_free_arr(dup_grid);
		ft_cleanup(game, FOUND_SPACE_INSI_MAP, 2, EXIT_FAILURE);
	}
	if (dup_grid[x][y] == '0' || dup_grid[x][y] == 'D')
		dup_grid[x][y] = '+';
	if (x <= 0 || x >= game->map->height - 1 || y == 0)
	{
		ft_free_arr(dup_grid);
		ft_cleanup(game, FOUND_UNCLOSED_MAP, 2, EXIT_FAILURE);
	}
	ft_flood_fill(game, dup_grid, x - 1, y);
	ft_flood_fill(game, dup_grid, x + 1, y);
	ft_flood_fill(game, dup_grid, x, y - 1);
	ft_flood_fill(game, dup_grid, x, y + 1);
}

/**
 * @brief Duplicates the map grid and allocates memory for it.
 *
 * This function creates a duplicate of the map grid by allocating memory
 * for each row and copying the contents from the original grid. The last
 * row is set to NULL to indicate the end of the grid.
 *
 * @param game The game structure containing the game state.
 * @return A pointer to the duplicated grid.
 */
static char	**ft_dup_grid(t_game *game)
{
	char	**dup_grid;
	int		width;
	int		len;
	int		i;

	width = game->map->width;
	dup_grid = ft_safe_malloc(sizeof(char *) * (game->map->height + 1));
	i = 0;
	while (i < game->map->height)
	{
		len = ft_strlen(game->map->grid[i]);
		dup_grid[i] = ft_calloc(width + 1, sizeof(char));
		ft_memset(dup_grid[i], '#', width);
		ft_memcpy(dup_grid[i], game->map->grid[i], len);
		i++;
	}
	dup_grid[i] = NULL;
	return (dup_grid);
}
