/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:06:31 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/22 11:02:00 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * @brief Parses the .cub file and its contents.
 *
 * This function takes the command line argument containing the path to the .cub
 * file and parses its contents. It verifies the file name and extension, reads
 * the file, sets the headers, parses the map grid, and checks for any holes or
 * empty lines within the grid.
 *
 * @param game A pointer to the central game structure containing game state
 *             and data.
 * @param argv The command line arguments containing the path to the .cub file.
 */
void	ft_parse(t_game *game, char **argv)
{
	game->file_path = argv[1];
	ft_parse_file_path(game);
	ft_set_cub_file(game);
	ft_parse_headers(game);
	ft_parse_map_grid(game);
	ft_check_map_closure(game);
}
