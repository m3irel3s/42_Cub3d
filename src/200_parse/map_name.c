/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:31:22 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/01 12:14:05 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parse_map_name(t_game *game)
{
	char	*extension;
	char	*to_compare;

	extension = ft_strrchr(game->map->map_path, '.');
	to_compare = ft_strrchr(game->map->map_path, '/');
	if (extension && (ft_strcmp(extension, ".cub") == 0)
		&& (ft_strlen(to_compare) > 5))
		return ;
	ft_cleanup(game, "Invalid map name given\n", 2);
}