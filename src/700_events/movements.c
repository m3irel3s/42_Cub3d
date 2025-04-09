/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:00:00 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/08 17:45:06 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_move_forward(t_game *game, double move_speed)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = game->player->pos_x + game->player->dir_x * move_speed;
	new_pos_y = game->player->pos_y + game->player->dir_y * move_speed;
	if (new_pos_x >= 0 && new_pos_x < game->map->width &&
		new_pos_y >= 0 && new_pos_y < game->map->height)
	{
		game->player->pos_x = new_pos_x;
		game->player->pos_y = new_pos_y;
	}
}

void	ft_move_backward(t_game *game, double move_speed)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = game->player->pos_x - game->player->dir_x * move_speed;
	new_pos_y = game->player->pos_y - game->player->dir_y * move_speed;
	if (new_pos_x >= 0 && new_pos_x < game->map->width &&
		new_pos_y >= 0 && new_pos_y < game->map->height)
	{
		game->player->pos_x = new_pos_x;
		game->player->pos_y = new_pos_y;
	}
}

void	ft_move_left(t_game *game, double move_speed)
{
	double perp_dir_x;
	double perp_dir_y;
	double new_pos_x;
	double new_pos_y;

	perp_dir_x = game->player->dir_y;
	perp_dir_y = -game->player->dir_x;
	new_pos_x = game->player->pos_x + perp_dir_x * move_speed;
	new_pos_y = game->player->pos_y + perp_dir_y * move_speed;
	if (new_pos_x >= 0 && new_pos_x < game->map->width &&
		new_pos_y >= 0 && new_pos_y < game->map->height)
	{
		game->player->pos_x = new_pos_x;
		game->player->pos_y = new_pos_y;
	}
}
void	ft_move_right(t_game *game, double move_speed)
{
	double perp_dir_x;
	double perp_dir_y;
	double new_pos_x;
	double new_pos_y;

	perp_dir_x = -game->player->dir_y;
	perp_dir_y = game->player->dir_x;
	new_pos_x = game->player->pos_x + perp_dir_x * move_speed;
	new_pos_y = game->player->pos_y + perp_dir_y * move_speed;
	if (new_pos_x >= 0 && new_pos_x < game->map->width &&
		new_pos_y >= 0 && new_pos_y < game->map->height)
	{
		game->player->pos_x = new_pos_x;
		game->player->pos_y = new_pos_y;
	}
}
