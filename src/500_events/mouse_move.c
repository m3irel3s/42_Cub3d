/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:53:37 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/24 15:35:29 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	rotate_player(t_game *game, float angle);
static int	handle_horizontal_movement(int delta_x, t_game *game);
int			handle_vertical_movement(int delta_y, t_game *game);

int mouse_move_handler(int x, int y, t_game *game)
{
	int	center_x;
	int	center_y;
	int	delta_x;
	int	delta_y;
	static int	first_call = 1;
	
	center_x = SCREEN_WIDTH / 2;
	center_y = SCREEN_HEIGHT / 2;
	if (first_call)
	{
		mlx_mouse_move(game->mlx, game->win, center_x, center_y);
		first_call = 0;
		return (0);
	}
	delta_x = x - center_x;
	delta_y = y - center_y;
	handle_horizontal_movement(delta_x, game);
	handle_vertical_movement(delta_y, game);
	mlx_mouse_move(game->mlx, game->win, center_x, center_y);
	return (0);
}

static int handle_horizontal_movement(int delta_x, t_game *game)
{
	float sensitivity_x;
	
	sensitivity_x = 0.0004;
	if (delta_x != 0)
	{
		rotate_player(game, delta_x * sensitivity_x);
	}
	return (0);
}

int handle_vertical_movement(int delta_y, t_game *game)
{
	float sensitivity_y;

	sensitivity_y = 0.5;
	if (delta_y != 0)
	{
		game->player->look_offset -= delta_y * sensitivity_y;
		if (game->player->look_offset > 300)
			game->player->look_offset = 300;
		if (game->player->look_offset < -300)
			game->player->look_offset = -300;
	}
	return (0);
}

static void rotate_player(t_game *game, float angle)
{
	float old_dir_x;
	float old_plane_x;

	old_dir_x = game->player->dir_x;
	game->player->dir_x = game->player->dir_x * cos(angle) - game->player->dir_y * sin(angle);
	game->player->dir_y = old_dir_x * sin(angle) + game->player->dir_y * cos(angle);

	old_plane_x = game->player->plane_x;
	game->player->plane_x = game->player->plane_x * cos(angle) - game->player->plane_y * sin(angle);
	game->player->plane_y = old_plane_x * sin(angle) + game->player->plane_y * cos(angle);
}
