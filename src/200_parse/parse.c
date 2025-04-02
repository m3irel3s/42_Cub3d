/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:06:31 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/01 15:58:42 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_parse(t_game *game, char **argv)
{
	game->map->map_path = argv[1];
	// protect open maybe
	ft_parse_map_name(game);
	ft_set_cub_file(game);

	for (int i = 0; game->cub_file[i]; i++)
		printf("%s", game->cub_file[i]);

	// ft_parse_map_colors();
	// ft_parse_map_grid();
}
