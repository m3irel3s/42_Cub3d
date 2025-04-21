/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:31:22 by jmeirele          #+#    #+#             */
/*   Updated: 2025/04/21 21:57:42 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/**
 * @brief Verifies if the file path passed as argument to the program has a
 *        valid name.
 *
 * The function checks if the file path has a '.cub' extension. It also checks
 * if the file is in the root directory or if it is in a directory with a name
 * that has a length of 5 or more characters. If the file does not meet these
 * conditions, the program is terminated and an error message is printed.
 *
 * @param game A pointer to the central game structure containing game state
 *             and data.
 */
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
