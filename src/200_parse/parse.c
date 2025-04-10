/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:06:31 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/10 16:56:51 by meferraz         ###   ########.fr       */
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
	// for (int i = 0; i < game->map->grid_start_index; i++)
	// 	ft_printf(1, "%s\n", game->cub_file[i]);
	// printf("\n\n");
	ft_parse_headers(game);
	ft_parse_map_grid(game);
	ft_check_map_closure(game);
	// printf("\n\nORIGINAL\n\n");
	// for (int i = 0; i < game->map->height; i++)
		// ft_printf(1, "%s\n", game->map->grid[i]);
	// printf("x-> %d y-> %d\n", game->map->s_pos.x, game->map->s_pos.y);
	// printf("s_dir -> %c\n", game->map->s_dir);
}

