/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:35:42 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/05 15:29:55 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_clean_map(t_map * map);
static void	ft_free_textures(t_game *game);
static void	ft_clean_graphics(t_game *game);

void	ft_cleanup(t_game *game, char *msg, int fd)
{
	if (game)
	{
		if(game->map)
			ft_clean_map(game->map);
		if (game->cub_file)
			ft_free_arr(game->cub_file);
		ft_free_textures(game);
		if (game->mlx)
			ft_clean_graphics(game);
		ft_free(game->player);
		ft_free(game);
	}
	ft_printf(fd, "%s\n", msg);
	exit(EXIT_SUCCESS);
}

static void	ft_clean_map(t_map * map)
{
	ft_free_arr(map->grid);
	ft_free(map);
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
static void	ft_free_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (game->textures[i].mlx_img)
			mlx_destroy_image(game->mlx, game->textures[i].mlx_img);
		i++;
	}
}
