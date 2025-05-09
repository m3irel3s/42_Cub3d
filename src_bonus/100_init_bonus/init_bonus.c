/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:29:06 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/25 14:34:57 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/cub3d_bonus.h"

static void		ft_init_textures(t_game *game);
static t_map	*ft_init_map(void);
static void		ft_init_gate_textures(t_game *game);
static void		ft_init_intro(t_game *game);

/**
 * @brief Initializes all game's structs and sets them to their default values
 *
 * @return A pointer to the newly created game struct
 */
t_game	*ft_init_structs(void)
{
	t_game	*game;

	game = ft_safe_malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = ft_init_map();
	game->cub_file = NULL;
	game->headers = NULL;
	game->file_path = NULL;
	game->mlx = NULL;
	game->img = NULL;
	game->win = NULL;
	game->player = ft_safe_malloc(sizeof(t_player));
	if (!game->player)
		return (NULL);
	ft_init_intro(game);
	ft_init_textures(game);
	ft_init_gate_textures(game);
	return (game);
}

/**
 * @brief Initializes all textures in the game struct to NULL
 *
 * @param game The game struct containing the textures to be initialized
 */
static void	ft_init_textures(t_game *game)
{
	game->textures[0].mlx_img = NULL;
	game->textures[1].mlx_img = NULL;
	game->textures[2].mlx_img = NULL;
	game->textures[3].mlx_img = NULL;
}

/**
 * @brief Allocates memory for a new t_map struct and initializes it to default
 * values
 *
 * @return A pointer to the newly allocated t_map struct
 */
static t_map	*ft_init_map(void)
{
	t_map	*map;

	map = ft_safe_malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->grid = NULL;
	map->height = 0;
	map->show_map = false;
	map->gates = NULL;
	map->num_gates = 0;
	return (map);
}

static void	ft_init_gate_textures(t_game *game)
{
	game->gate_textures[0].mlx_img = NULL;
	game->gate_textures[1].mlx_img = NULL;
	game->gate_textures[2].mlx_img = NULL;
	game->gate_textures[3].mlx_img = NULL;
	game->gate_textures[4].mlx_img = NULL;
	game->gate_textures[5].mlx_img = NULL;
	game->gate_textures[6].mlx_img = NULL;
	game->gate_textures[7].mlx_img = NULL;
}

static void	ft_init_intro(t_game *game)
{
	game->intro = ft_safe_malloc(sizeof(t_intro));
	if (!game->intro)
		return ;
	game->intro->active = false;
	game->intro->animation.frames = NULL;
	game->intro->animation.frame_count = 0;
	game->intro->animation.current_frame = 0;
	game->intro->animation.frame_duration = 0;
	game->intro->animation.last_update = 0;
}
