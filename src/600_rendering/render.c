/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:20:00 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/05 12:51:24 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void ft_clear_image(t_game *game, int ceiling_color, int floor_color)
{
	int x, y;
	for (y = 0; y < SCREEN_HEIGHT / 2; y++)
		for (x = 0; x < SCREEN_WIDTH; x++)
			ft_mlx_pixel_put_to_image(game, x, y, ceiling_color);
	for (y = SCREEN_HEIGHT / 2; y < SCREEN_HEIGHT; y++)
		for (x = 0; x < SCREEN_WIDTH; x++)
			ft_mlx_pixel_put_to_image(game, x, y, floor_color);
}

int ft_render_next_frame(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img->mlx_img);
	game->img->mlx_img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->img->addr = mlx_get_data_addr(game->img->mlx_img, &game->img->bpp,
			&game->img->line_len, &game->img->endian);
	ft_set_floor_n_ceiling(game);
	ft_clear_image(game, game->ceiling_color_hex, game->floor_color_hex);
	ft_cast_rays(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img->mlx_img, 0, 0);
	return (0);
}
