/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:06:31 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/14 16:14:59 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parse(t_game *game, char **argv)
{
	game->file_path = argv[1];
	// protect open maybe
	ft_parse_file_path(game);
	ft_set_cub_file(game);
	// printf("index => %d\n", game->map->grid_start_index);
	printf("\n\n");
	ft_parse_headers(game);
	ft_parse_map_grid(game);
	ft_check_map_closure(game);
	// printf("\n\nORIGINAL\n\n");
	// for (int i = 0; i < game->map->height; i++)
		// ft_printf(1, "%s\n", game->map->grid[i]);
	// printf("x-> %d y-> %d\n", game->map->s_pos.x, game->map->s_pos.y);
	// printf("s_dir -> %c\n", game->map->s_dir);
}

