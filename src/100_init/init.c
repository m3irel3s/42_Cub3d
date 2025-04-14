/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:29:06 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/14 17:35:46 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static t_map	*ft_init_map(void);
static void	ft_init_gate_textures(t_game *game);

t_game	*ft_init_structs(void)
{
	t_game	*game;

	game = NULL;
	game = ft_safe_malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = ft_init_map();
	game->cub_file = NULL;
	game->headers = NULL;
	game->file_path = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->player = ft_safe_malloc(sizeof(t_player));
	game->textures[0].mlx_img = NULL;
	game->textures[1].mlx_img = NULL;
	game->textures[2].mlx_img = NULL;
	game->textures[3].mlx_img = NULL;
	ft_init_gate_textures(game);
	if (!game->player)
		return (NULL);
	return (game);
}

static t_map	*ft_init_map(void)
{
	t_map	*map;

	map = NULL;
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
