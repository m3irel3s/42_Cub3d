/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:53:54 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/25 14:14:37 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

static void	ft_draw_player_circle(t_game *game, t_point center);
static void	ft_draw_direction(t_game *game, t_point center);

/**
 * @brief Draws the grid on the minimap.
 *
 * Iterates over each cell in the game map grid and draws the corresponding
 * cell on the minimap. Cells are drawn based on their type, such as walls,
 * floors, empty spaces, and doors, by calling the ft_draw_cell function
 * with the appropriate cell type.
 *
 * @param game The game structure containing the map and rendering state.
 */
void	ft_draw_grid(t_game *game)
{
	int		y;
	int		x;
	char	tile;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < (int)ft_strlen(game->map->grid[y]))
		{
			tile = game->map->grid[y][x];
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

/**
 * @brief Draws the player on the minimap.
 *
 * @param game The game structure containing rendering state.
 *
 * This function draws the player's position and direction on the minimap.
 * The player's position is drawn as a circle, and their direction is drawn
 * as a line extending from the center of the circle.
 */
void	ft_draw_player(t_game *game)
{
	t_point	center;

	center.x = game->map->minimap.start_x + \
		(game->player->pos_x * game->map->minimap.scale);
	center.y = game->map->minimap.start_y + \
		(game->player->pos_y * game->map->minimap.scale);
	ft_draw_player_circle(game, center);
	ft_draw_direction(game, center);
}

/**
 * @brief Draws a line to represent the player's direction on the minimap.
 *
 * The line is drawn from the player's position to a point in the direction the
 * player is facing. The length of the line is 1.5 times the minimap scale.
 *
 * @param game The game struct containing rendering state.
 * @param center The point on the screen where the player's position is drawn.
 */
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

/**
 * @brief Draws a circle centered at the given point, to represent the
 * player on the minimap.
 *
 * The circle is drawn using Bresenham's circle algorithm, with a radius of 6
 * pixels. The color of the circle is set to COLOR_PLAYER.
 *
 * @param game A pointer to the game structure containing the mlx image 
 * and window.
 * @param center A point structure containing the x and y coordinates of 
 * the circle's center.
 */
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
