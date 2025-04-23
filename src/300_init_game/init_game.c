/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:12:01 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/23 22:27:27 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	ft_init_graphics(t_game *game);

/**
 * @brief Initializes all game's components and player
 *
 * @param game The game struct to be initialized
 */
void	ft_init_game(t_game *game)
{
	ft_init_player(game);
	ft_init_gates(game);
	ft_init_graphics(game);
}

/**
 * @brief Initializes the graphics components of the game.
 *
 * This function sets up the MLX graphics library, allocates memory for the
 * image structure, creates a new window, and initializes a new image for
 * rendering. It also loads textures and sets up hooks for rendering frames
 * and handling user input events. If any initialization fails, the function
 * cleans up and exits.
 *
 * @param game The game struct containing all necessary game data.
 */
static void	ft_init_graphics(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_cleanup(game, MLX_INIT_FAIL, 2, EXIT_FAILURE);
	game->img = ft_safe_malloc(sizeof(t_img));
	if (!game->img)
		ft_cleanup(game, MLX_INIT_FAIL, 2, EXIT_FAILURE);
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3d");
	game->img->mlx_img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->img->addr = mlx_get_data_addr(game->img->mlx_img, &game->img->bpp,
			&game->img->line_len, &game->img->endian);
	ft_load_textures(game);
	game->intro->active = true;
	mlx_loop_hook(game->mlx, ft_render_next_frame, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, ft_handle_key, game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask,
		ft_handle_key_release, game);
	mlx_hook(game->win, 17, 1L << 17, &ft_quit_game, game);
}
