/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:00:00 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/25 14:14:37 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

/**
 * @brief Casts a ray for each x-coordinate on the screen, performs the DDA
 *        algorithm, calculates the wall height, and draws the textured wall.
 *
 * @param game The game data structure.
 *
 * This function iterates over all x-coordinates on the screen and performs the
 * following steps:
 * 1. Initializes a ray for the current x-coordinate.
 * 2. Performs the Digital Differential Analyzer (DDA) algorithm on the ray.
 * 3. If the ray hits a wall, calculates the wall height.
 * 4. Draws the textured wall.
 */
void	ft_cast_rays(t_game *game)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		ft_init_ray(game, x, &ray);
		ft_perform_dda(game, &ray);
		if (ray.hit)
		{
			ft_calc_wall(game, &ray);
			if (ray.gate)
				ft_draw_gate(game, x, &ray);
			else
				ft_draw_textured_wall(game, x, &ray);
		}
		x++;
	}
}
