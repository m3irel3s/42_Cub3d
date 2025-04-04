/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:35:42 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/04 16:28:10 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_clean_map(t_map * map);
static void	ft_clean_graphics(t_game *game);

void	ft_cleanup(t_game *game, char *msg, int fd)
{
	if (game)
	{
		ft_clean_map(game->map);
		ft_clean_graphics(game);
		ft_free(game->map);
	ft_free(game->textures);
	ft_free(game->paths);
		ft_free(game->player);
		ft_free(game);
	}
	ft_printf(fd, "%s\n", msg);
	exit(EXIT_SUCCESS);
}

static void	ft_clean_map(t_map * map)
{
	ft_free_arr(map->grid);
}

static void	ft_clean_graphics(t_game *game)
{
	if (!game || !game->mlx)
		return;
	if (game->img)
	{
		if (game->img->mlx_img)
			mlx_destroy_image(game->mlx, game->img->mlx_img);
		ft_free(game->img);
	}
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	ft_free(game->mlx);
}
