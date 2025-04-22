/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:18:14 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/22 11:04:49 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	ft_free_headers(t_game *game);
static void	ft_free_cub_file_and_grid(t_game *game);

void	ft_free_parse(t_game *game)
{
	ft_free_headers(game);
	ft_free_cub_file_and_grid(game);
}

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
