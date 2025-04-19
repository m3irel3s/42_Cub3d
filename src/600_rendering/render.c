/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:20:00 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/19 16:49:46 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	ft_render_intro(t_game *game);
int	ft_get_time_ms(void);
/**
 * Darkens an RGB color by applying a factor multiple times.
 *
 * This function extracts the red, green, and blue components from
 * a given color and repeatedly scales them by a specified factor.
 * The operation is performed a given number of times for progressive
 * darkening. If the factor is outside the range [0, 1], the original
 * color is returned unchanged.
 *
 * @param color The original RGB color represented as an integer.
 * @param factor The factor by which to darken the color components.
 *               This should be a value between 0 and 1.
 * @param times The number of times the darkening factor should be applied.
 * @return The resulting darkened RGB color represented as an integer.
 */

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

/**
 * Clears the top half of the screen with a gradient of the given ceiling color.
 *
 * This function uses ft_darken_rgb_color3 to darken the ceiling color by a
 * factor of 0.9 a specified number of times, depending on the y-coordinate.
 * The top of the screen is rendered with the brightest color, and the bottom
 * of the ceiling with the darkest. The resulting color is then used to fill
 * each horizontal line of the top half of the screen.
 *
 * @param game The game data structure, which contains the mlx image and window.
 * @param ceiling_color The original RGB ceiling color represented as an integer.
 */
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
		if (y >= ((SCREEN_HEIGHT / 2) - 110))
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

/**
 * Clears the bottom half of the screen with a gradient of the given floor color.
 *
 * This function uses ft_darken_rgb_color3 to darken the floor color by a factor
 * of 0.9 a specified number of times, depending on the y-coordinate. The bottom
 * of the screen is rendered with the brightest color, and the top of the floor
 * with the darkest. The resulting color is then used to fill each horizontal
 * line of the bottom half of the screen.
 *
 * @param game The game data structure, which contains the mlx image and window.
 * @param floor_color The original RGB floor color represented as an integer.
 */
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

/**
 * Clears the screen with a gradient of the given ceiling and floor colors.
 *
 * This function simply calls ft_clear_ceiling and ft_clear_floor to clear the
 * top and bottom halves of the screen, respectively.
 *
 * @param game The game data structure, which contains the mlx image and window.
 * @param ceiling_color The original RGB ceiling color represented as an integer.
 * @param floor_color The original RGB floor color represented as an integer.
 */
void	ft_clear_image(t_game *game, int ceiling_color, int floor_color)
{
	ft_clear_ceiling(game, ceiling_color);
	ft_clear_floor(game, floor_color);
}

/**
 * Renders the next frame of the game.
 *
 * This function first destroys the current frame, then creates a new one. It
 * then clears the screen with a gradient of the given ceiling and floor colors,
 * renders the raycasted walls, and finally puts the new frame in the window.
 *
 * @param game The game data structure, which contains the mlx image and window.
 * @return 0 if the function was successful, 1 otherwise.
 */
int	ft_render_next_frame(t_game *game)
{
	if (game->intro->active)
		ft_render_intro(game);
	else
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
		if (game->map->show_map)
			ft_display_minimap(game);
		ft_update_gates(game);
		mlx_put_image_to_window(game->mlx, game->win, game->img->mlx_img, 0, 0);
	}
	return (0);
}

static void	ft_render_intro(t_game *game)
{
	double	current_time;

	current_time = ft_get_time_ms();
	if (current_time - game->intro->animation.last_update >= game->intro->animation.frame_duration) {
		game->intro->animation.current_frame =
			(game->intro->animation.current_frame + 1) % game->intro->animation.frame_count;
		game->intro->animation.last_update = current_time;
	}
	t_img *current = &game->intro->animation.frames[game->intro->animation.current_frame];
	int x = (SCREEN_WIDTH - current->width) / 2;
	int y = (SCREEN_HEIGHT - current->height) / 2;
	if (game->img->mlx_img)
		mlx_destroy_image(game->mlx, game->img->mlx_img);
	game->img->mlx_img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->img->addr = mlx_get_data_addr(game->img->mlx_img, &game->img->bpp,
			&game->img->line_len, &game->img->endian);
	ft_memset(game->img->addr, 0, SCREEN_HEIGHT * game->img->line_len);
	mlx_put_image_to_window(game->mlx, game->win, current->mlx_img, x, y);
}
