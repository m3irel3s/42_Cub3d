/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:35:42 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/23 15:48:49 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	ft_clean_graphics(t_game *game);
static void	ft_free_textures(t_game *game);

/**
 * @brief Cleans up all allocated resources and exits the game.
 *
 * This function frees all dynamically allocated memory associated with the game,
 * including parsing data, textures, graphics, and game structures. It outputs
 * a message to the specified file descriptor and then exits the program.
 *
 * @param game A pointer to the central game structure containing game state
 *             and data to be freed.
 * @param msg A message to be printed before exiting the program.
 * @param fd The file descriptor to which the message will be printed.
 */
void	ft_cleanup(t_game *game, char *msg, int fd, int status)
{
	if (game)
	{
		ft_free_parse(game);
		ft_free_textures(game);
		ft_clean_graphics(game);
		ft_free(game->mlx);
		ft_free(game->map);
		ft_free(game->player);
		ft_free(game);
	}
	ft_printf(fd, "%s\n", msg);
	exit(status);
}

/**
 * @brief Cleans up graphics resources for the game.
 *
 * This function is responsible for freeing resources related to the graphics
 * rendering of the game, such as the game image, window, and MLX display.
 *
 * @param game A pointer to the central game structure containing game state
 *             and data to be freed.
 */
static void	ft_clean_graphics(t_game *game)
{
	if (!game || !game->mlx)
		return ;
	if (game->img)
	{
		if (game->img->mlx_img)
			mlx_destroy_image(game->mlx, game->img->mlx_img);
		ft_free(game->img);
	}
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
}

/**
 * @brief Frees all textures in the game.
 *
 * This function iterates through the game->textures array and frees any
 * textures that have been loaded. It uses mlx_destroy_image to properly
 * free the resources associated with the textures.
 *
 * @param game A pointer to the central game structure containing game state
 *             and data to be freed.
 */
static void	ft_free_textures(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (game->textures[i].mlx_img)
			mlx_destroy_image(game->mlx, game->textures[i].mlx_img);
	}
}
