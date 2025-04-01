/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:29:06 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/01 15:13:52 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_map		*ft_init_map(void);
static t_texture	*ft_init_textures(void);
static t_path		*ft_init_path(void);

t_game	*ft_init_structs(void)
{
	t_game	*game;

	game = ft_safe_malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = ft_init_map();
	game->cub_file = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->img = NULL;
	game->player = NULL;
	return (game);
}

static t_map	*ft_init_map(void)
{
	t_map	*map;

	map = ft_safe_malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
	map->s_pos = NULL;
	map->imgs = ft_init_textures();
	map->paths = ft_init_path();
	map->map_path = NULL;
	return (map);
}

static t_texture	*ft_init_textures(void)
{
	t_texture	*texture;

	texture = ft_safe_malloc(sizeof(t_texture));
	if (!texture)
		return (NULL);
	texture->no_img = NULL;
	texture->so_img = NULL;
	texture->we_img = NULL;
	texture->ea_img = NULL;
	return (texture);
}

static t_path	*ft_init_path(void)
{
	t_path	*path;

	path = ft_safe_malloc(sizeof(t_path));
	if (!path)
		return (NULL);
	path->no_path = NULL;
	path->so_path = NULL;
	path->we_path = NULL;
	path->ea_path = NULL;
	return (path);
}
