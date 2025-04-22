/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_gradient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:08:06 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/22 11:14:32 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * @brief Fills the top half of the screen with a gradient of the specified
 *        ceiling color.
 *
 * This function iterates over the screen, starting from the top and going down,
 * and for each row, it calculates the amount of darkening needed based on the
 * current row (y) and the starting row of the gradient, and then darkens the
 * ceiling color accordingly. The resulting color is then used to fill a row of
 * pixels on the screen.
 *
 * @param game The game struct containing the game state.
 * @param ceiling_color The color to use for the gradient.
 */
void	ft_clear_ceiling(t_game *game, int ceiling_color)
{
	int	x;
	int	y;
	int	times;
	int	new_ceiling;

	y = 0;
	while (y < SCREEN_HEIGHT / 2)
	{
		times = ft_gradient_step(y, (SCREEN_HEIGHT / 2 - 110), 1);
		new_ceiling = ft_darken_rgb_color3(ceiling_color, DARKEN_FACTOR, times);
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			ft_mlx_pixel_put_to_image(game, x, y, new_ceiling);
			x++;
		}
		y++;
	}
}

/**
 * @brief Fills the bottom half of the screen with a gradient of the specified
 *        floor color.
 *
 * This function iterates over the screen, starting from the middle and going
 * down, and for each row, it calculates the amount of darkening needed based on
 * the current row (y) and the starting row of the gradient, and then darkens
 * the floor color accordingly. The resulting color is then used to fill a row
 * of pixels on the screen.
 *
 * @param game The game struct containing the game state.
 * @param floor_color The color to use for the gradient.
 */
void	ft_clear_floor(t_game *game, int floor_color)
{
	int	x;
	int	y;
	int	times;
	int	new_floor;

	y = SCREEN_HEIGHT / 2;
	while (y < SCREEN_HEIGHT)
	{
		times = ft_gradient_step(y, 0, 0);
		new_floor = ft_darken_rgb_color3(floor_color, DARKEN_FACTOR, times);
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			ft_mlx_pixel_put_to_image(game, x, y, new_floor);
			x++;
		}
		y++;
	}
}
