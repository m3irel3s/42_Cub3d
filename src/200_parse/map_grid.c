/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:37:57 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/08 19:01:08 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_extract_map(t_game *game);
static void	ft_find_holes(t_game *game);
static void	ft_update_map_grid(t_game *game);
static void	ft_handle_map_spaces(t_game *game);

void	ft_parse_map_grid(t_game *game)
{
	printf("start -> %d\n", game->map->grid_start_index);
	printf("last -> %d\n", game->map->grid_last_index);
	ft_extract_map(game);
	ft_find_holes(game);
	ft_update_map_grid(game);
	ft_validate_map_chars(game);
	ft_handle_map_spaces(game);
	ft_set_player_values(game);
}

static void	ft_handle_map_spaces(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map->map_size)
	{
		j = 0;
		while (game->map->grid[i][j])
		{
			if (game->map->grid[i][j] == ' ')
				game->map->grid[i][j] = '0';
			j++;
		}
	}
}

static void	ft_update_map_grid(t_game *game)
{
	char	**n_grid;
	int		old_size;
	int		i;

	i = 0;
	n_grid = NULL;
	old_size = game->map->map_size;
	while (game->map->grid[i])
		i++;
	game->map->map_size = i;
	printf("new size -> %d\n", game->map->map_size);
	n_grid = ft_safe_malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (++i < game->map->map_size)
		n_grid[i] = ft_strdup(game->map->grid[i]);
	i = -1;
	while (++i < old_size)
		ft_free(game->map->grid[i]);
	ft_free(game->map->grid);
	game->map->grid = n_grid;
}

static void	ft_find_holes(t_game *game)
{
	int	i;
	int	found_empty;

	i = 0;
	found_empty = 0;
	while (i < game->map->map_size)
	{
		if (ft_is_empty_line(game->map->grid[i]) == SUCCESS)
		{
			found_empty = 1;
			i++;
		}
		else if (ft_is_empty_line(game->map->grid[i]) != SUCCESS)
		{
			if (found_empty == 1)
				ft_cleanup(game, FOUND_EMPTY_LINE_INSI_MAP, 2);
			i++;
		}
	}
}

static void	ft_extract_map(t_game *game)
{
	int	i;
	int	l;
	int	j;

	j = 0;
	i = game->map->grid_start_index;
	l = game->map->grid_last_index;
	game->map->map_size = l - i;
	printf("size w/nulls -> %d\n", game->map->map_size);
	game->map->grid = ft_safe_malloc(sizeof(char *) * (l - i + 1));
	while (i < l)
		game->map->grid[j++] = game->cub_file[i++];
	game->map->grid[j] = NULL;
}
