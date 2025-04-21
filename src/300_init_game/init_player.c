/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:07:22 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/21 15:39:55 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_set_n_or_s_values(t_game *game, char dir);
static void	ft_set_e_or_w_values(t_game *game, char dir);

void	ft_init_player(t_game *game)
{
	char	dir;

	dir = game->map->s_dir;
	if (dir == 'N' || dir == 'S')
		ft_set_n_or_s_values(game, dir);
	else if (dir == 'W' || dir == 'E')
		ft_set_e_or_w_values(game, dir);
	game->player->pos_x = (double)game->map->s_pos.x + 0.5;
	game->player->pos_y = (double)game->map->s_pos.y + 0.5;
	return ;
}

static void	ft_set_n_or_s_values(t_game *game, char dir)
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

static void	ft_set_e_or_w_values(t_game *game, char dir)
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
