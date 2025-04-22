/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_gradient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:08:06 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/22 10:48:22 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	ft_clear_ceiling(t_game *game, int ceiling_color)
{
	int	x;
	int	y;
	int	times;
	int	new_ceiling;

	y = 0;
	while (y < SCREEN_HEIGHT / 2)
	{
		times = ft_gradient_step(y, CEILING_GRADIENT_START, 1);
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
