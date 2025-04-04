/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:31:22 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/04 16:10:38 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parse_map_name(t_game *game)
{
	char	*extension;
	char	*to_compare;

	extension = ft_strrchr(game->file_path, '.');
	to_compare = ft_strrchr(game->file_path, '/');
	if (extension && (ft_strcmp(extension, ".cub") == 0))
	{
		if (to_compare == NULL || ft_strlen(to_compare) > 5)
			return ;
	}
	ft_cleanup(game, INVALID_MAP_NAME, 2);
}
