/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:58:08 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/14 16:54:06 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_valid_map_line(t_game *game, char *line);
static int	ft_are_valid_map_chars(char c);

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
				game->map->s_pos.x = i;
				game->map->s_pos.y = j;
				game->map->s_dir = game->map->grid[i][j];
			}
			j++;
		}
		i++;
	}
}

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
		ft_cleanup(game, FOUND_MORE_PLAYERS, 2);
	if (counter == 0)
		ft_cleanup(game, PLAYER_NOT_FOUND, 2);
}

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
			ft_cleanup(game, FOUND_TAB_IN_MAP, 2);
		else if (ft_is_space(line[i]))
			i++;
		else if (ft_are_valid_map_chars(line[i]))
		{
			has_valid_char = 1;
			i++;
		}
		else
			ft_cleanup(game, FOUND_INVALID_CHAR_MAP, 2);
	}
	if (has_valid_char)
		return (SUCCESS);
	return (FAILURE);
}

static int	ft_are_valid_map_chars(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S'
				|| c == 'E' || c == 'W' || c == ' ');
}
