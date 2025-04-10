/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:07:22 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/10 15:47:10 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_set_N_or_S_values(t_game *game, char dir);
static void	ft_set_E_or_W_values(t_game *game, char dir);
static void	ft_debug_player(t_player *player);


void	ft_init_player(t_game *game)
{
	char	dir;

	dir = game->map->s_dir;
	if (dir == 'N' || dir == 'S')
		ft_set_N_or_S_values(game, dir);
	else if (dir == 'W' || dir == 'E')
		ft_set_E_or_W_values(game, dir);
	game->player->pos_x = (double)game->map->s_pos.x + 0.5;
	game->player->pos_y = (double)game->map->s_pos.y + 0.5;
	ft_debug_player(game->player);
	return ;
}

static void	ft_set_N_or_S_values(t_game *game, char dir)
{
	if (dir == 'N')
	{
		game->player->dir_x = 0;
		game->player->dir_y = -1;
		game->player->plane_x = FOV;
		game->player->plane_y = 0;
	}
	else if (dir == 'S')
	{
		game->player->dir_x = 0;
		game->player->dir_y = 1;
		game->player->plane_x = -FOV;
		game->player->plane_y = 0;
	}
}

static void	ft_set_E_or_W_values(t_game *game, char dir)
{
	if (dir == 'E')
	{
		game->player->dir_x = 1;
		game->player->dir_y = 0;
		game->player->plane_x = 0;
		game->player->plane_y = FOV;
	}
	else if (dir == 'W')
	{
		game->player->dir_x = -1;
		game->player->dir_y = 0;
		game->player->plane_x = 0;
		game->player->plane_y = -FOV;
	}
}

static void	ft_debug_player(t_player *player)
{
	printf("Player Position:    (%.2f, %.2f)\n", player->pos_x, player->pos_y);
	printf("Player Direction:   (%.2f, %.2f)\n", player->dir_x, player->dir_y);
	printf("Camera Plane:       (%.2f, %.2f)\n", player->plane_x, player->plane_y);
}