/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:13:18 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/25 14:14:37 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

static void	ft_handle_movement(int key, t_game *game, double move_speed);
static void	ft_handle_rotation(int key, t_game *game, double rot_speed);

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
	else if (key == KEY_TAB)
		game->map->show_map = true;
	else if (key == KEY_E)
		ft_handle_gate_animation(game);
	else
	{
		ft_handle_movement(key, game, move_speed);
		ft_handle_rotation(key, game, rot_speed);
	}
	return (0);
}

/**
 * Handles key release events for the game. Currently, it only toggles the
 * show_map flag in the game structure when the TAB key is released.
 *
 * @param key The key code of the released key.
 * @param game Pointer to the game structure containing game data.
 * @return Always returns 0.
 */
int	ft_handle_key_release(int key, t_game *game)
{
	if (key == KEY_TAB)
		game->map->show_map = false;
	return (0);
}

/**
 * Handles the player's movement based on the given key press event.
 *
 * If the W key is pressed, the player moves forward.
 * If the S key is pressed, the player moves backward.
 * If the D key is pressed, the player moves left.
 * If the A key is pressed, the player moves right.
 *
 * The movement speed is determined by the move_speed parameter.
 *
 * @param key The key code of the pressed key.
 * @param game Pointer to the game structure containing game data.
 * @param move_speed The speed at which the player moves.
 */
static void	ft_handle_movement(int key, t_game *game, double move_speed)
{
	if (key == KEY_W)
		ft_move_forward(game, move_speed);
	else if (key == KEY_S)
		ft_move_backward(game, move_speed);
	else if (key == KEY_D)
		ft_move_left(game, move_speed);
	else if (key == KEY_A)
		ft_move_right(game, move_speed);
}

/**
 * @brief Handles the player's rotation based on the given key press event.
 *
 * If the LEFT key is pressed, the player rotates to the left.
 * If the RIGHT key is pressed, the player rotates to the right.
 *
 * The rotation speed is determined by the rot_speed parameter.
 *
 * @param key The key code of the pressed key.
 * @param game Pointer to the game structure containing game data.
 * @param rot_speed The speed at which the player rotates.
 */
static void	ft_handle_rotation(int key, t_game *game, double rot_speed)
{
	if (key == KEY_LEFT)
		ft_rotate(game, -rot_speed);
	else if (key == KEY_RIGHT)
		ft_rotate(game, rot_speed);
}
