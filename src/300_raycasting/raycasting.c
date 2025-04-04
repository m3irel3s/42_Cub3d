/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:00:00 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/04 15:37:10 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_cast_rays(t_game *game)
{
	int		x;
	t_ray	ray;
	double	wallX;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		ft_init_ray(game, x, &ray);
		ft_perform_dda(game, &ray);
		if (ray.hit)
		{
			ft_calc_wall(game, &ray);
			if (ray.side == 0)
				wallX = game->player->pos_y + ray.perp_wall_dist * ray.ray_dir_y;
			else
				wallX = game->player->pos_x + ray.perp_wall_dist * ray.ray_dir_x;
			wallX = wallX - floor(wallX);
			ft_draw_texture_line(game, x, ray.draw_start,
				ray.draw_end, ray.side, wallX, &ray);
		}
		x++;
	}
}
