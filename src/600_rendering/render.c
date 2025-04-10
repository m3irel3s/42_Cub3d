/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:20:00 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/10 17:34:30 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_darken_rgb_color3(int color, double factor, int times)
{
	int	r;
	int	g;
	int	b;
	int	j;

	j = 0;
	if (factor < 0 || factor > 1)
		return (color);
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

static void	ft_clear_ceiling(t_game *game, int ceiling_color)
{
	int	x;
	int	y;
	int	times;
	int	new_ceiling;

	y = 0;
	while (y < SCREEN_HEIGHT / 2)
	{
		times = 18 - (((SCREEN_HEIGHT / 2) - 110 - y + 9) / 10);
		if (y >= stop)
			times = 18;
		if (times < 0)
			times = 0;
		new_ceiling = ft_darken_rgb_color3(ceiling_color, 0.9, times);
		x = 0;
		while (x < SCREEN_WIDTH)
			ft_mlx_pixel_put_to_image(game, x++, y, new_ceiling);
		y++;
	}
}

static void	ft_clear_floor(t_game *game, int floor_color)
{
	int	x;
	int	y;
	int	times;
	int	new_floor;

	y = SCREEN_HEIGHT / 2;
	while (y < SCREEN_HEIGHT)
	{
		times = 0;
		if (y < ((SCREEN_HEIGHT / 2) + (SCREEN_HEIGHT / 2) / 2) + 50)
		{
			times = (((SCREEN_HEIGHT / 2) + (SCREEN_HEIGHT / 2) / 2)
					+ 50 - y + 9) / 10;
			if (times > 18)
				times = 18;
		}
		new_floor = ft_darken_rgb_color3(floor_color, 0.9, times);
		x = 0;
		while (x < SCREEN_WIDTH)
			ft_mlx_pixel_put_to_image(game, x++, y, new_floor);
		y++;
	}
}

void	ft_clear_image(t_game *game, int ceiling_color, int floor_color)
{
	ft_clear_ceiling(game, ceiling_color);
	ft_clear_floor(game, floor_color);
}

int	ft_render_next_frame(t_game *game)
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
