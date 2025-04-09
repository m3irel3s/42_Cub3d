/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:37:57 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/09 15:39:00 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_extract_map(t_game *game);
static void	ft_find_holes(t_game *game);

void	ft_parse_map_grid(t_game *game)
{
	printf("start index -> %d\n", game->map->grid_start_index);
	printf("last index -> %d\n", game->map->grid_last_index);
	ft_extract_map(game);
	ft_find_holes(game);
	ft_validate_map_chars(game);
	ft_set_player_values(game);
}

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

static void	ft_extract_map(t_game *game)
{
	int	i;
	int	l;
	int	j;

	j = 0;
	i = game->map->grid_start_index;
	l = game->map->grid_last_index;
	game->map->map_size = l - i;
	game->map->grid = ft_safe_malloc(sizeof(char *) * (l - i + 1));
	while (i < l)
		game->map->grid[j++] = ft_strdup(game->cub_file[i++]);
	game->map->grid[j] = NULL;
}


