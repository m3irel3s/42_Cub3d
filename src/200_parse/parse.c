/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:06:31 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/01 12:22:52 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	ft_parse(t_game *game, char **argv)
{
	game->map->map_path = argv[1];
	// protect open maybe
	ft_parse_map_name(game);
	ft_set_cub_file(game);
	// ft_parse_map_colors();
	// ft_parse_map_grid();
}