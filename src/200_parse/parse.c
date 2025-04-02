/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:06:31 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/02 15:28:14 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parse(t_game *game, char **argv)
{
	game->map->map_path = argv[1];
	// protect open maybe
	ft_parse_map_name(game);
	ft_set_cub_file(game);
	printf("index => %d\n", game->map->grid_start_index);
	for (int i = 0; game->cub_file[i]; i++)
		printf("%s", game->cub_file[i]);
	ft_parse_map_headers(game);
	// ft_parse_map_grid();
}

