/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:53:37 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/24 19:45:41 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	ft_handle_horizontal_movement(int delta_x, t_game *game);

/**
 * @brief Handles mouse movement by adjusting the player's direction and
 * centering the mouse on the screen.
 *
 * This function is called whenever the mouse is moved. It first checks if it is
 * the first call and if so, moves the mouse to the center of the screen. Then,
 * it calculates the delta x and y coordinates of the mouse movement and calls
 * ft_handle_horizontal_movement to adjust the player's direction. Finally, it
 * moves the mouse back to the center of the screen.
 *
 * @param x The x-coordinate of the mouse.
 * @param y The y-coordinate of the mouse.
 * @param game The game structure containing rendering state.
 * @return Always returns 0.
 */
int	ft_mouse_move_handler(int x, int y, t_game *game)
{
	int			center_x;
	int			center_y;
	int			delta_x;
	static int	first_call;

	(void)y;
	center_x = SCREEN_WIDTH / 2;
	center_y = SCREEN_HEIGHT / 2;
	if (first_call)
	{
		mlx_mouse_move(game->mlx, game->win, center_x, center_y);
		first_call = 0;
		return (0);
	}
	delta_x = x - center_x;
	ft_handle_horizontal_movement(delta_x, game);
	mlx_mouse_move(game->mlx, game->win, center_x, center_y);
	return (0);
}

/**
 * @brief Handles the horizontal movement of the mouse.
 *
 * This function adjusts the player's direction based on the horizontal
 * movement of the mouse. It calculates the rotation angle using the delta
 * x-coordinate and a predefined sensitivity factor, then applies the rotation
 * to the player's view.
 *
 * @param delta_x The change in x-coordinate of the mouse.
 * @param game Pointer to the game structure containing game data.
 * @return Always returns 0.
 */
static int	ft_handle_horizontal_movement(int delta_x, t_game *game)
{
	float	sensitivity_x;

	sensitivity_x = 0.0004;
	if (delta_x != 0)
		ft_rotate(game, delta_x * sensitivity_x);
	return (0);
}
