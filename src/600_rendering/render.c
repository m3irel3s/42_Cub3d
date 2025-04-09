/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:20:00 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/05 16:04:03 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
int darken_rgb_color3(int color, double factor, int times)
{
	int r, g, b;
	int j = 0;

	if (factor < 0 || factor > 1)
		return color;
	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	while (j < times)
	{
		r = (int)(r * factor);
		g = (int)(g * factor);
		b = (int)(b * factor);
		j++;
	}
	return ((r << 16) | (g << 8) | b);
}

void ft_clear_image(t_game *game, int ceiling_color, int floor_color)
{
	int x, y;
	int stop_ceiling = (SCREEN_HEIGHT / 2) - 110;
	int stop_floor = (SCREEN_HEIGHT / 2) + (SCREEN_HEIGHT / 2) / 2;
	int target_floor = stop_floor + 50;

	// Ceiling
	for (y = 0; y < SCREEN_HEIGHT / 2; y++)
	{
		int times_ceiling = 18 - ((stop_ceiling - y + 9) / 10);
		if (y >= stop_ceiling)
			times_ceiling = 18;
		if (times_ceiling < 0)
			times_ceiling = 0;
		int new_ceiling = darken_rgb_color3(ceiling_color, 0.9, times_ceiling);
		for (x = 0; x < SCREEN_WIDTH; x++)
			ft_mlx_pixel_put_to_image(game, x, y, new_ceiling);
	}

	// Floor
	for (y = SCREEN_HEIGHT / 2; y < SCREEN_HEIGHT; y++)
	{
		int times_floor = 0;
		if (y < target_floor)
		{
			times_floor = (target_floor - y + 9) / 10;
			if (times_floor > 18)
				times_floor = 18;
		}
		int new_floor = darken_rgb_color3(floor_color, 0.9, times_floor);
		for (x = 0; x < SCREEN_WIDTH; x++)
			ft_mlx_pixel_put_to_image(game, x, y, new_floor);
	}
}

int ft_render_next_frame(t_game *game)
{
	if (game->img->mlx_img)
		mlx_destroy_image(game->mlx, game->img->mlx_img);
	game->img->mlx_img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->img->addr = mlx_get_data_addr(game->img->mlx_img, &game->img->bpp,
			&game->img->line_len, &game->img->endian);
	ft_memset(game->img->addr, 0, SCREEN_HEIGHT * game->img->line_len);
	ft_set_floor_n_ceiling(game);
	ft_clear_image(game, game->ceiling_color_hex, game->floor_color_hex);
	ft_cast_rays(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img->mlx_img, 0, 0);
	return (0);
}
