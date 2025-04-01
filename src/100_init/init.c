/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:29:06 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/01 11:44:50 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_map	*ft_init_map(void);
static t_img	*ft_init_imgs(void);
static t_path	*ft_init_path(void);

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
	return (game);
}

static t_map	*ft_init_map(void)
{
	t_map	*map;

	map = ft_safe_malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->grid = NULL;
	map->imgs = ft_init_imgs();
	map->paths = ft_init_path();
	map->map_path = NULL;
	return (map);
}

static t_img	*ft_init_imgs(void)
{
	t_img	*img;

	img = ft_safe_malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->no_img = NULL;
	img->so_img = NULL;
	img->we_img = NULL;
	img->ea_img = NULL;
	return (img);
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
