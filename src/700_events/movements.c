/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:00:00 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/10 21:49:37 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_move_forward(t_game *game, double move_speed)
{
	double	new_pos_x;
	double	new_pos_y;
	int		current_row_len;

	new_pos_x = game->player->pos_x + game->player->dir_x * move_speed;
	new_pos_y = game->player->pos_y + game->player->dir_y * move_speed;
	current_row_len = ft_strlen(game->map->grid[(int)new_pos_y]);
	if ((int)new_pos_x > 0 && (int)new_pos_x < current_row_len - 1
		&& (int)new_pos_y > 0 && (int)new_pos_y < game->map->height - 1)
	{
		game->player->pos_x = new_pos_x;
		game->player->pos_y = new_pos_y;
	}
}


void	ft_move_backward(t_game *game, double move_speed)
{
	double	new_pos_x;
	double	new_pos_y;
	int		current_row_len;

	new_pos_x = game->player->pos_x - game->player->dir_x * move_speed;
	new_pos_y = game->player->pos_y - game->player->dir_y * move_speed;
	current_row_len = ft_strlen(game->map->grid[(int)new_pos_y]);
	if ((int)new_pos_x > 0 && (int)new_pos_x < current_row_len - 1
		&& (int)new_pos_y > 0 && (int)new_pos_y < game->map->height - 1)
	{
		game->player->pos_x = new_pos_x;
		game->player->pos_y = new_pos_y;
	}
}

void	ft_move_left(t_game *game, double move_speed)
{
	double	perp_dir_x;
	double	perp_dir_y;
	double	new_pos_x;
	double	new_pos_y;
	int		current_row_len;

	perp_dir_x = -game->player->dir_y;
	perp_dir_y = game->player->dir_x;
	new_pos_x = game->player->pos_x + perp_dir_x * move_speed;
	new_pos_y = game->player->pos_y + perp_dir_y * move_speed;
	current_row_len = ft_strlen(game->map->grid[(int)new_pos_y]);
	if ((int)new_pos_x > 0 && (int)new_pos_x < current_row_len - 1
		&& (int)new_pos_y > 0 && (int)new_pos_y < game->map->height - 1)
	{
		game->player->pos_x = new_pos_x;
		game->player->pos_y = new_pos_y;
	}
}

void	ft_move_right(t_game *game, double move_speed)
{
	double	perp_dir_x;
	double	perp_dir_y;
	double	new_pos_x;
	double	new_pos_y;
	int		current_row_len;

	perp_dir_x = game->player->dir_y;
	perp_dir_y = -game->player->dir_x;
	new_pos_x = game->player->pos_x + perp_dir_x * move_speed;
	new_pos_y = game->player->pos_y + perp_dir_y * move_speed;
	current_row_len = ft_strlen(game->map->grid[(int)new_pos_y]);
	if ((int)new_pos_x > 0 && (int)new_pos_x < current_row_len - 1
		&& (int)new_pos_y > 0 && (int)new_pos_y < game->map->height - 1)
	{
		game->player->pos_x = new_pos_x;
		game->player->pos_y = new_pos_y;
	}
}
