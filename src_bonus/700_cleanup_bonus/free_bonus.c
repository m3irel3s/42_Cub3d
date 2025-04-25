/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:35:42 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/25 14:34:57 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/cub3d_bonus.h"

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
		if (game->mlx)
			ft_clean_graphics(game);
		if (game->map->gates)
			ft_free(game->map->gates);
		ft_free(game->map);
		ft_free(game->player);
		ft_free(game->intro);
		ft_free(game->img);
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
	int	i;

	i = -1;
	if (!game || !game->mlx)
		return ;
	if (game->intro && game->intro->animation.frames)
	{
		while (++i < game->intro->animation.frame_count)
		{
			if (game->intro->animation.frames[i].mlx_img)
				mlx_destroy_image(game->mlx,
					game->intro->animation.frames[i].mlx_img);
		}
		ft_free(game->intro->animation.frames);
	}
	if (game->img)
	{
		if (game->img->mlx_img)
			mlx_destroy_image(game->mlx, game->img->mlx_img);
	}
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	ft_free(game->mlx);
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
	i = 0;
	while (i < 8)
	{
		if (game->gate_textures[i].mlx_img)
			mlx_destroy_image(game->mlx, game->gate_textures[i].mlx_img);
		i++;
	}
	i = 0;
}
