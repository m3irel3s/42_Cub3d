/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:53:54 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/22 22:07:00 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	ft_draw_player_circle(t_game *game, t_point center);
static void	ft_draw_direction(t_game *game, t_point center);

void	ft_draw_grid(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < (int)ft_strlen(game->map->grid[y]))
		{
			char tile = game->map->grid[y][x];
			if (tile == '1')
				ft_draw_cell(game, x, y, WALL);
			else if (tile == '0' || tile == 'N' || tile == 'S'
				|| tile == 'E' || tile == 'W')
				ft_draw_cell(game, x, y, FLOOR);
			else if (tile == ' ')
				ft_draw_cell(game, x, y, EMPTY);
			else if (tile == 'D')
				ft_draw_cell(game, x, y, DOOR);
			x++;
		}
		y++;
	}
}

void	ft_draw_player(t_game *game)
{
	t_point	center;

	center.x = game->map->minimap.start_x +
		(game->player->pos_x * game->map->minimap.scale);
	center.y = game->map->minimap.start_y +
		(game->player->pos_y * game->map->minimap.scale);
	ft_draw_player_circle(game, center);
	ft_draw_direction(game, center);
}

static void	ft_draw_direction(t_game *game, t_point center)
{
	double	scale;
	int		i;

	scale = game->map->minimap.scale * 1.5;
	i = -1;
	while (++i < (int)scale)
	{
		ft_mlx_pixel_put_to_image(game,
			center.x + game->player->dir_x * i,
			center.y + game->player->dir_y * i,
			COLOR_PLAYER);
	}
}

static void	ft_draw_player_circle(t_game *game, t_point center)
{
	int	x;
	int	y;
	int	radius;

	radius = 6;
	y = -radius - 1;
	while (++y <= radius)
	{
		x = -radius - 1;
		while (++x <= radius)
		{
			if (x * x + y * y <= radius * radius + radius * 0.8)
			{
				ft_mlx_pixel_put_to_image(game,
					center.x + x,
					center.y + y,
					COLOR_PLAYER);
			}
		}
	}
}
