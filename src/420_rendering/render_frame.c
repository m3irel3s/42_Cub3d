/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:20:00 by meferraz          #+#    #+#             */
/*   Updated: 2025/04/22 15:54:19 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	ft_render_intro(t_game *game);
int	ft_get_time_ms(void);

/**
 * @brief Clears the image to be rendered by filling it with the given
 *        ceiling and floor colors.
 *
 * This function clears the image by calling ft_clear_ceiling and
 * ft_clear_floor with the given colors.
 *
 * @param game The game struct containing the game state.
 * @param ceiling_color The color value to use for the ceiling.
 * @param floor_color The color value to use for the floor.
 */
void	ft_clear_image(t_game *game, int ceiling_color, int floor_color)
{
	ft_clear_ceiling(game, ceiling_color);
	ft_clear_floor(game, floor_color);
}

/**
 * @brief Renders the next frame in the game window.
 *
 * This function is a loop hook for MLX, responsible for rendering the game
 * window frame by frame. It clears the image, sets the floor and ceiling
 * colors, clears the image with those colors, casts the rays for the current
 * player position, and then puts the rendered image in the game window.
 *
 * @param game The game struct containing the game state.
 *
 * @return Always returns 0 to indicate successful execution.
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
	t_img *current;

	current_time = ft_get_time_ms();
	if (current_time - game->intro->animation.last_update >= game->intro->animation.frame_duration) {
		game->intro->animation.current_frame =
			(game->intro->animation.current_frame + 1) % game->intro->animation.frame_count;
		game->intro->animation.last_update = current_time;
	}
	current = &game->intro->animation.frames[game->intro->animation.current_frame];
	mlx_put_image_to_window(
		game->mlx,
		game->win,
		current->mlx_img,
		(SCREEN_WIDTH - current->width) / 2,
		(SCREEN_HEIGHT - current->height) / 2
	);
}
