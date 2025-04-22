/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 22:02:15 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/22 22:08:57 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	ft_fill_cell_pixels(t_game *game, t_point screen, int scale, int color);

void	ft_draw_cell(t_game *game, int map_x, int map_y, t_cell type)
{
	t_point	screen;
	int		color;

	color = 0x00000000;
	screen.x = game->map->minimap.start_x + map_x * game->map->minimap.scale;
	screen.y = game->map->minimap.start_y + map_y * game->map->minimap.scale;
	if (type == WALL)
		color = COLOR_WALL;
	else if (type == FLOOR)
		color = COLOR_FLOOR;
	else if (type == EMPTY)
		color = COLOR_EMPTY;
	else if (type == DOOR)
		color = COLOR_DOOR;
	ft_fill_cell_pixels(game, screen, game->map->minimap.scale, color);
}

static void	ft_fill_cell_pixels(t_game *game, t_point screen, int scale, int color)
{
	int	y;
	int	x;

	y = 0;
	while (y < scale)
	{
		x = 0;
		while (x < scale)
		{
			if (y == 0 || x == 0 || y == scale - 1 || x == scale - 1)
				ft_mlx_pixel_put_to_image(game, screen.x + x, screen.y + y, CELL_BORDER);
			else if (color != 0x00000000)
				ft_mlx_pixel_put_to_image(game, screen.x + x, screen.y + y, color);
			x++;
		}
		y++;
	}
}
