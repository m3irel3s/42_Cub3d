/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:30:00 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/22 11:56:58 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * Handles key press events for the game. Depending on the key pressed,
 * it performs the appropriate action such as moving the player or rotating
 * the view. The function supports movement keys (W, A, S, D), rotation keys
 * (LEFT, RIGHT), and the ESC key to quit the game.
 *
 * @param key The key code of the pressed key.
 * @param game Pointer to the game structure containing game data.
 * @return Always returns 0.
 */
int	ft_handle_key(int key, t_game *game)
{
	double	move_speed;
	double	rot_speed;

	move_speed = 0.2;
	rot_speed = 0.2;
	if (game->intro->active)
	{
		if (key == KEY_ENTER)
			game->intro->active = false;
		else if (key == KEY_ESC)
			ft_quit_game(game);
		return (0);
	}
	if (key == KEY_ESC)
		ft_quit_game(game);
	else if (key == KEY_W)
		ft_move_forward(game, move_speed);
	else if (key == KEY_S)
		ft_move_backward(game, move_speed);
	else if (key == KEY_D)
		ft_move_left(game, move_speed);
	else if (key == KEY_A)
		ft_move_right(game, move_speed);
	else if (key == KEY_LEFT)
		ft_rotate_left(game, rot_speed);
	else if (key == KEY_RIGHT)
		ft_rotate_right(game, rot_speed);
	else if (key == KEY_M)
		game->map->show_map = true;
	else if (key == KEY_G)
		ft_handle_gate_animation(game);
	return (0);
}


/**
 * Handles key release events for the game. Currently, it only toggles the
 * show_map flag in the game structure when the M key is released.
 *
 * @param key The key code of the released key.
 * @param game Pointer to the game structure containing game data.
 * @return Always returns 0.
 */
int	ft_handle_key_release(int key, t_game *game)
{
	if (key == KEY_M)
		game->map->show_map = false;
	return (0);
}
