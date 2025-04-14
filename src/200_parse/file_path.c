/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:31:22 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/14 18:57:52 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_parse_file_path(t_game *game)
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
