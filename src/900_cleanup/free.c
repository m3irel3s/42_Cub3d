/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:35:42 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/04 16:12:31 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_clean_map(t_map * map);

void	ft_cleanup(t_game *game, char *msg, int fd)
{
	ft_clean_map(game->map);
	ft_free(game->map);
	ft_free(game->textures);
	ft_free(game->paths);
	ft_free(game);
	ft_printf(fd, msg);
	exit(0);
}

static void	ft_clean_map(t_map * map)
{
	ft_free(map->grid);
}

