/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 22:02:15 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/24 15:38:16 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	ft_fill_cell_pixels(t_game *game, t_point screen, int scale,
				int color);

/**
 * @brief Draws a cell on the minimap.
 *
 * Calculates the position of the cell on the screen based on the map's
 * dimensions and the minimap's scale. Then, it fills the corresponding
 * pixels in the image with the color associated with the given cell type.
 *
 * @param game The game structure containing the map and rendering state.
 * @param map_x The x-coordinate of the cell in the map.
 * @param map_y The y-coordinate of the cell in the map.
 * @param type The type of the cell to be drawn, which determines the color used.
 */
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

/**
 * @brief Fills a cell on the minimap with the given color.
 *
 * This function fills the pixels of a cell on the minimap with the given color.
 * The cell is drawn as a square with a border of one pixel all around.
 *
 * @param game The game structure containing the mlx image and window.
 * @param screen The point structure containing the x and y coordinates of the
 *               top-left corner of the cell on the screen.
 * @param scale The size of the cell, in pixels.
 * @param color The color to use to fill the cell. If set to 0x00000000, the
 *              cell will not be filled.
 */
static void	ft_fill_cell_pixels(t_game *game, t_point screen, int scale,
	int color)
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
				ft_mlx_pixel_put_to_image(game, screen.x + x, screen.y + y,
					CELL_BORDER);
			else if (color != 0x00000000)
				ft_mlx_pixel_put_to_image(game, screen.x + x, screen.y + y,
					color);
			x++;
		}
		y++;
	}
}
