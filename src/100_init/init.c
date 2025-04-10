/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:29:06 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/10 15:57:07 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static t_map	*ft_init_map(void);

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
	game->img = ft_safe_malloc(sizeof(t_img));
	if (!game->img)
		return (NULL);
	game->player = ft_safe_malloc(sizeof(t_player));
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
	return (map);
}
