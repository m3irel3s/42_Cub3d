/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:40:55 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/14 19:04:17 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**ft_dup_grid(t_game *game);
static void	ft_flood_fill(t_game *game, char **dup_grid, int x, int y);

void	ft_check_map_closure(t_game *game)
{
	int		x;
	int		y;
	char	**dup_grid;

	x = game->map->s_pos.x;
	y = game->map->s_pos.y;
	dup_grid = NULL;
	dup_grid = ft_dup_grid(game);
	ft_flood_fill(game, dup_grid, x, y);
	ft_free_arr(dup_grid);
}

static void	ft_flood_fill(t_game *game, char **dup_grid, int x, int y)
{
	if (!dup_grid[x][y])
	{
		ft_free_arr(dup_grid);
		ft_cleanup(game, FOUND_UNCLOSED_MAP, 2);
	}
	if (dup_grid[x][y] == '1' || dup_grid[x][y] == '+')
		return ;
	if (dup_grid[x][y] == '0' || dup_grid[x][y] == ' ')
		dup_grid[x][y] = '+';
	ft_flood_fill(game, dup_grid, x - 1, y);
	ft_flood_fill(game, dup_grid, x + 1, y);
	ft_flood_fill(game, dup_grid, x, y - 1);
	ft_flood_fill(game, dup_grid, x, y + 1);
}

static char	**ft_dup_grid(t_game *game)
{
	char	**dup_grid;
	int		i;

	i = 0;
	dup_grid = NULL;
	dup_grid = ft_safe_malloc(sizeof(char *) * (game->map->height + 1));
	while (i < game->map->height)
	{
		dup_grid[i] = ft_strdup(game->map->grid[i]);
		i++;
	}
	dup_grid[i] = NULL;
	return (dup_grid);
}
